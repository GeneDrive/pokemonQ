#!/usr/bin/env python3
"""
Pokemon Data Parser
Parses all Pokemon stats, types, and abilities from ROM hack source files
and creates a Word document with the information.
"""

import os
import re
import sys
from pathlib import Path
from docx import Document
from docx.shared import Inches
from docx.enum.text import WD_ALIGN_PARAGRAPH

# Define constants mappings
TYPE_NAMES = {
    0: "Normal", 1: "Fighting", 2: "Flying", 3: "Poison", 4: "Ground",
    5: "Rock", 6: "Bug", 7: "Ghost", 8: "Steel", 9: "Mystery",
    10: "Fire", 11: "Water", 12: "Grass", 13: "Electric", 14: "Psychic",
    15: "Ice", 16: "Dragon", 17: "Dark", 18: "Fairy", 19: "Time", 255: "None"
}

class PokemonParser:
    def __init__(self, base_path):
        self.base_path = Path(base_path)
        self.species_data = {}
        self.abilities_map = {}
        self.species_names = {}
        self.macro_definitions = {}  # Store macro definitions
        self.base_form_data = {}  # Store base form data for inheritance
        
    def load_constants(self):
        """Load species, abilities, and type constants from header files"""
        # Load species constants
        species_file = self.base_path / "include" / "constants" / "species.h"
        if species_file.exists():
            with open(species_file, 'r', encoding='utf-8') as f:
                content = f.read()
                for match in re.finditer(r'#define\s+SPECIES_(\w+)\s+(\d+)', content):
                    species_name = match.group(1)
                    species_id = int(match.group(2))
                    self.species_names[species_id] = species_name
                    
        # Load abilities constants
        abilities_file = self.base_path / "include" / "constants" / "abilities.h"
        if abilities_file.exists():
            with open(abilities_file, 'r', encoding='utf-8') as f:
                content = f.read()
                for match in re.finditer(r'#define\s+ABILITY_(\w+)\s+(\d+)', content):
                    ability_name = match.group(1).replace('_', ' ').title()
                    ability_id = int(match.group(2))
                    self.abilities_map[ability_id] = ability_name
                    
    def parse_species_files(self):
        """Parse all generation species files"""
        species_dir = self.base_path / "src" / "data" / "pokemon" / "species_info"
        
        # First pass: collect macro definitions and base forms
        for gen_file in species_dir.glob("gen_*.h"):
            print(f"Parsing macros from {gen_file.name}...")
            self.parse_macros(gen_file)
            
        # Second pass: parse all species
        for gen_file in species_dir.glob("gen_*.h"):
            print(f"Parsing species from {gen_file.name}...")
            self.parse_species_file(gen_file)
            
    def parse_macros(self, file_path):
        """Parse macro definitions that contain Pokemon data"""
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
            
        # Find macro definitions like #define POKEMON_MISC_INFO
        macro_pattern = r'#define\s+(\w+_MISC_INFO)\s+(.+?)(?=\n#define|\nstatic|\n\[SPECIES|\n#if|\n#endif|\Z)'
        
        for match in re.finditer(macro_pattern, content, re.DOTALL):
            macro_name = match.group(1)
            macro_content = match.group(2).strip()
            self.macro_definitions[macro_name] = macro_content
            
    def parse_species_file(self, file_path):
        """Parse a single species file"""
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
            
        # Find all pokemon species entries - improved regex to capture the complete block
        # This regex handles nested braces better
        species_entries = []
        
        # Find species entries with a more robust approach
        start_pattern = r'\[SPECIES_(\w+)\]\s*=\s*\{'
        
        for start_match in re.finditer(start_pattern, content):
            species_name = start_match.group(1)
            start_pos = start_match.end() - 1  # Position of opening brace
            
            # Find matching closing brace
            brace_count = 0
            pos = start_pos
            while pos < len(content):
                if content[pos] == '{':
                    brace_count += 1
                elif content[pos] == '}':
                    brace_count -= 1
                    if brace_count == 0:
                        end_pos = pos
                        break
                pos += 1
            else:
                continue  # No matching brace found
                
            # Extract the data block
            species_data = content[start_pos + 1:end_pos]
            
            # Skip entries that only have evolution data or minimal info
            if self.has_meaningful_data(species_data):
                species_entries.append((species_name, species_data))
        
        # Sort entries to process base forms before alternate forms
        species_entries.sort(key=lambda x: (self.is_alternate_form(x[0]), x[0]))
        
        # Process entries
        for species_name, species_data in species_entries:
            pokemon_info = self.parse_pokemon_data(species_name, species_data)
            if pokemon_info and (pokemon_info['stats'] or pokemon_info['types'] or pokemon_info['abilities']):
                self.species_data[species_name] = pokemon_info
                    
    def has_meaningful_data(self, data_block):
        """Check if the data block contains meaningful pokemon information"""
        # Check for base stats, types, or abilities
        meaningful_patterns = [
            r'\.baseHP\s*=',
            r'\.types\s*=',
            r'\.abilities\s*=',
            r'\.baseAttack\s*='
        ]
        
        for pattern in meaningful_patterns:
            if re.search(pattern, data_block):
                return True
        return False
                
    def parse_pokemon_data(self, species_name, data_block):
        """Parse individual pokemon data block"""
        pokemon = {
            'name': species_name,
            'display_name': '',
            'stats': {},
            'types': [],
            'abilities': [],
            'is_alternate_form': self.is_alternate_form(species_name)
        }
        
        # First, check for explicit definitions in the original data block (before macro expansion)
        # This prioritizes Pokemon-specific data over macro data
        
        # Parse types - check original first, then expanded
        types_match = re.search(r'\.types\s*=\s*\{\s*TYPE_(\w+)\s*,\s*TYPE_(\w+)\s*\}', data_block)
        if not types_match:
            # If not found in original, expand macros and try again
            expanded_data = self.expand_macros(data_block)
            types_match = re.search(r'\.types\s*=\s*\{\s*TYPE_(\w+)\s*,\s*TYPE_(\w+)\s*\}', expanded_data)
        
        if types_match:
            type1_raw = types_match.group(1)
            type2_raw = types_match.group(2)
            
            # Convert type names
            type1 = self.format_type_name(type1_raw)
            type2 = self.format_type_name(type2_raw)
            
            # Only add unique types
            if type1 == type2:
                pokemon['types'] = [type1]
            else:
                pokemon['types'] = [type1, type2]
        
        # Parse abilities - check original first, then expanded
        abilities_match = re.search(r'\.abilities\s*=\s*\{\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*\}', data_block)
        if not abilities_match:
            # If not found in original, expand macros and try again
            expanded_data = self.expand_macros(data_block)
            abilities_match = re.search(r'\.abilities\s*=\s*\{\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*\}', expanded_data)
            
        if abilities_match:
            abilities = []
            ability_names = []
            
            # Get all three ability slots
            for i in range(1, 4):
                ability_raw = abilities_match.group(i)
                if ability_raw and ability_raw != "NONE":
                    ability_name = self.format_ability_name(ability_raw)
                    ability_names.append(ability_name)
                else:
                    ability_names.append(None)
            
            # Determine ability types based on Pokemon ability system:
            # Slot 1: Regular ability
            # Slot 2: Second regular ability (if different from slot 1)
            # Slot 3: Hidden Ability
            
            # First, check if all abilities are the same
            unique_abilities = set(filter(None, ability_names))
            
            if len(unique_abilities) == 1:
                # All abilities are the same - just show "Ability"
                abilities.append(f"{list(unique_abilities)[0]} (Ability)")
            else:
                # Multiple different abilities
                if ability_names[0]:  # First ability slot
                    if ability_names[1] and ability_names[1] != ability_names[0]:
                        # Pokemon has two different regular abilities
                        abilities.append(f"{ability_names[0]} (Ability 1)")
                        abilities.append(f"{ability_names[1]} (Ability 2)")
                    else:
                        # Pokemon has only one regular ability
                        abilities.append(f"{ability_names[0]} (Ability)")
                
                if ability_names[2]:  # Hidden ability slot
                    # Only add hidden ability if it's different from the regular abilities
                    if ability_names[2] != ability_names[0] and ability_names[2] != ability_names[1]:
                        abilities.append(f"{ability_names[2]} (Hidden Ability)")
            
            pokemon['abilities'] = abilities
        
        # For other fields, use expanded data since they don't conflict
        expanded_data = self.expand_macros(data_block)
        
        # Parse base stats
        stat_patterns = {
            'HP': r'\.baseHP\s*=\s*(\d+)',
            'Attack': r'\.baseAttack\s*=\s*(\d+)',
            'Defense': r'\.baseDefense\s*=\s*(\d+)',
            'Sp. Attack': r'\.baseSpAttack\s*=\s*(\d+)',
            'Sp. Defense': r'\.baseSpDefense\s*=\s*(\d+)',
            'Speed': r'\.baseSpeed\s*=\s*(\d+)'
        }
        
        for stat_name, pattern in stat_patterns.items():
            match = re.search(pattern, data_block)  # Check original first
            if not match:
                match = re.search(pattern, expanded_data)  # Then expanded
            if match:
                pokemon['stats'][stat_name] = int(match.group(1))
            
        # Parse display name
        name_match = re.search(r'\.speciesName\s*=\s*_\("([^"]+)"\)', expanded_data)
        if name_match:
            pokemon['display_name'] = name_match.group(1)
        else:
            pokemon['display_name'] = self.format_species_name(species_name)
            
        return pokemon
        
    def expand_macros(self, data_block):
        """Recursively expand macro references in data block"""
        expanded = data_block
        max_iterations = 10  # Prevent infinite loops
        iteration = 0
        
        while iteration < max_iterations:
            old_expanded = expanded
            
            # Find macro references and expand them
            for macro_name, macro_content in self.macro_definitions.items():
                if macro_name in expanded:
                    expanded = expanded.replace(macro_name, macro_content)
            
            # If no changes were made, we're done
            if expanded == old_expanded:
                break
                
            iteration += 1
                
        return expanded
        
    def is_alternate_form(self, species_name):
        """Check if this is an alternate form (Mega, Alolan, etc.)"""
        alternate_keywords = [
            'MEGA', 'ALOLAN', 'GALARIAN', 'HISUIAN', 'PALDEAN',
            'PRIMAL', 'ORIGIN', 'SUNSHINE', 'ALTERED', 'ORIGIN',
            'HEAT', 'WASH', 'FROST', 'FAN', 'MOW'
        ]
        
        for keyword in alternate_keywords:
            if keyword in species_name:
                return True
        return False
        
    def get_base_form_name(self, species_name):
        """Get the base form name from an alternate form"""
        # Remove common alternate form suffixes
        base_name = species_name
        
        suffixes_to_remove = [
            '_MEGA', '_MEGA_X', '_MEGA_Y', '_PRIMAL',
            '_ALOLAN', '_GALARIAN', '_HISUIAN', '_PALDEAN',
            '_ORIGIN', '_SUNSHINE', '_ALTERED',
            '_HEAT_ROTOM', '_WASH_ROTOM', '_FROST_ROTOM', '_FAN_ROTOM', '_MOW_ROTOM',
            '_STANDARD_MODE', '_ZEN_MODE'
        ]
        
        for suffix in suffixes_to_remove:
            if base_name.endswith(suffix):
                base_name = base_name[:-len(suffix)]
                break
                
        return base_name
        
    def format_type_name(self, type_raw):
        """Format type name from constant to readable form"""
        return type_raw.replace('_', ' ').title()
        
    def format_ability_name(self, ability_raw):
        """Format ability name from constant to readable form"""
        return ability_raw.replace('_', ' ').title()
        
    def get_form_display_name(self, species_name, display_name):
        """Get the display name with form information for alternate forms"""
        if not self.is_alternate_form(species_name):
            return display_name
            
        # Extract form information from the species constant name
        form_suffix = ""
        
        # Check for specific form types and create readable names
        if "_MEGA_X" in species_name:
            form_suffix = " (Mega X)"
        elif "_MEGA_Y" in species_name:
            form_suffix = " (Mega Y)"
        elif "_MEGA" in species_name:
            form_suffix = " (Mega)"
        elif "_PRIMAL" in species_name:
            form_suffix = " (Primal)"
        elif "_GIGANTAMAX" in species_name or "_GMAX" in species_name:
            form_suffix = " (Gigantamax)"
        elif "_ALOLAN" in species_name:
            form_suffix = " (Alolan)"
        elif "_GALARIAN" in species_name:
            form_suffix = " (Galarian)"
        elif "_HISUIAN" in species_name:
            form_suffix = " (Hisuian)"
        elif "_PALDEAN" in species_name:
            form_suffix = " (Paldean)"
        elif "_ORIGIN" in species_name:
            form_suffix = " (Origin Forme)"
        elif "_SUNSHINE" in species_name:
            form_suffix = " (Sunshine Form)"
        elif "_ALTERED" in species_name:
            form_suffix = " (Altered Forme)"
        elif "_HEAT_ROTOM" in species_name or "_HEAT" in species_name:
            form_suffix = " (Heat Rotom)"
        elif "_WASH_ROTOM" in species_name or "_WASH" in species_name:
            form_suffix = " (Wash Rotom)"
        elif "_FROST_ROTOM" in species_name or "_FROST" in species_name:
            form_suffix = " (Frost Rotom)"
        elif "_FAN_ROTOM" in species_name or "_FAN" in species_name:
            form_suffix = " (Fan Rotom)"
        elif "_MOW_ROTOM" in species_name or "_MOW" in species_name:
            form_suffix = " (Mow Rotom)"
        elif "_ZEN_MODE" in species_name:
            form_suffix = " (Zen Mode)"
        elif "_STANDARD_MODE" in species_name:
            form_suffix = " (Standard Mode)"
        elif "_ATTACK" in species_name:
            form_suffix = " (Attack Forme)"
        elif "_DEFENSE" in species_name:
            form_suffix = " (Defense Forme)"
        elif "_SPEED" in species_name:
            form_suffix = " (Speed Forme)"
        elif "_INCARNATE" in species_name:
            form_suffix = " (Incarnate Forme)"
        elif "_THERIAN" in species_name:
            form_suffix = " (Therian Forme)"
        elif "_WHITE" in species_name:
            form_suffix = " (White)"
        elif "_BLACK" in species_name:
            form_suffix = " (Black)"
        elif "_BLUE" in species_name:
            form_suffix = " (Blue)"
        elif "_RED" in species_name:
            form_suffix = " (Red)"
        elif "_SCHOOL" in species_name:
            form_suffix = " (School)"
        elif "_SOLO" in species_name:
            form_suffix = " (Solo)"
        elif "_BUSTED" in species_name:
            form_suffix = " (Busted)"
        elif "_DISGUISED" in species_name:
            form_suffix = " (Disguised)"
        elif "_CORE" in species_name:
            form_suffix = " (Core)"
        elif "_COMPLETE" in species_name:
            form_suffix = " (Complete)"
        elif "_ULTRA" in species_name:
            form_suffix = " (Ultra)"
        elif "_DAWN_WINGS" in species_name:
            form_suffix = " (Dawn Wings)"
        elif "_DUSK_MANE" in species_name:
            form_suffix = " (Dusk Mane)"
        elif "_LOW_KEY" in species_name:
            form_suffix = " (Low Key)"
        elif "_AMPED" in species_name:
            form_suffix = " (Amped)"
        elif "_FULL_BELLY" in species_name:
            form_suffix = " (Full Belly)"
        elif "_HANGRY" in species_name:
            form_suffix = " (Hangry)"
        elif "_NOICE" in species_name:
            form_suffix = " (Noice Face)"
        elif "_ICE" in species_name and "DARMANITAN" in species_name:
            form_suffix = " (Zen Mode)"
        elif "_CROWNED" in species_name:
            form_suffix = " (Crowned)"
        elif "_ETERNAMAX" in species_name:
            form_suffix = " (Eternamax)"
        elif "_SINGLE_STRIKE" in species_name:
            form_suffix = " (Single Strike)"
        elif "_RAPID_STRIKE" in species_name:
            form_suffix = " (Rapid Strike)"
        elif "_RIDER" in species_name:
            form_suffix = " (Ice Rider)" if "ICE" in species_name else " (Shadow Rider)"
        
        return display_name + form_suffix
        
    def format_species_name(self, species_raw):
        """Format species name from constant to readable form"""
        return species_raw.replace('_', ' ').title()
        
    def create_word_document(self, output_file="pokemon_data.docx"):
        """Create a Word document with all Pokemon data"""
        doc = Document()
        
        # Add title
        title = doc.add_heading('Pokemon ROM Hack Data', 0)
        title.alignment = WD_ALIGN_PARAGRAPH.CENTER
        
        # Add generation info
        doc.add_paragraph(f"Generated from: {self.base_path}")
        doc.add_paragraph(f"Total Pokemon: {len(self.species_data)}")
        doc.add_paragraph("")
        
        # Sort Pokemon by display name for better readability
        sorted_pokemon = sorted(self.species_data.values(), key=lambda x: x['display_name'])
        
        for pokemon in sorted_pokemon:
            # Get the appropriate display name with form information
            form_display_name = self.get_form_display_name(pokemon['name'], pokemon['display_name'])
            
            # Pokemon name header with form information for alternate forms
            doc.add_heading(f"{form_display_name}", level=1)
            
            # Create table for pokemon data
            table = doc.add_table(rows=1, cols=2)
            table.style = 'Table Grid'
            
            # Stats section
            stats_cell = table.cell(0, 0)
            stats_cell.text = "Base Stats:"
            stats_para = stats_cell.paragraphs[0]
            stats_para.add_run().add_break()
            
            total_stats = 0
            if pokemon['stats']:
                for stat, value in pokemon['stats'].items():
                    stats_para.add_run(f"{stat}: {value}").add_break()
                    total_stats += value
                stats_para.add_run(f"BST: {total_stats}")
            else:
                stats_para.add_run("No stat data available")
            
            # Types and Abilities section
            info_cell = table.cell(0, 1)
            info_para = info_cell.paragraphs[0]
            
            # Types
            if pokemon['types']:
                types_str = " / ".join(pokemon['types'])
            else:
                types_str = "Unknown"
            info_para.add_run(f"Type(s): {types_str}").add_break()
            info_para.add_run().add_break()
            
            # Abilities
            info_para.add_run("Abilities:").add_break()
            if pokemon['abilities']:
                for ability in pokemon['abilities']:
                    info_para.add_run(f"• {ability}").add_break()
            else:
                info_para.add_run("• No abilities found")
                
            doc.add_paragraph("")  # Add spacing
            
        # Save document with error handling
        output_path = self.base_path / output_file
        
        # Try to save, if permission denied, try with a different name
        attempt = 0
        max_attempts = 5
        while attempt < max_attempts:
            try:
                if attempt == 0:
                    save_path = output_path
                else:
                    # Add a number to the filename
                    stem = output_path.stem
                    suffix = output_path.suffix
                    save_path = output_path.parent / f"{stem}_{attempt}{suffix}"
                
                doc.save(save_path)
                print(f"Word document saved to: {save_path}")
                return save_path
                
            except PermissionError as e:
                attempt += 1
                if attempt == 1:
                    print(f"Permission denied for {output_path}")
                    print("The file might be open in Word. Trying alternative filename...")
                elif attempt < max_attempts:
                    print(f"Attempt {attempt} failed, trying {save_path}...")
                else:
                    print(f"Failed to save after {max_attempts} attempts.")
                    print("Please close the Word document if it's open and try again.")
                    raise e
            except Exception as e:
                print(f"Error saving document: {e}")
                raise e

def main():
    # Get the current directory (where the script is located)
    base_path = Path(__file__).parent
    
    print("Pokemon ROM Hack Data Parser")
    print("=" * 40)
    print(f"Working directory: {base_path}")
    
    # Initialize parser
    parser = PokemonParser(base_path)
    
    # Load constants
    print("Loading constants...")
    parser.load_constants()
    print(f"Loaded {len(parser.abilities_map)} abilities")
    print(f"Loaded {len(parser.species_names)} species")
    
    # Parse species files
    print("Parsing species files...")
    parser.parse_species_files()
    
    print(f"Found {len(parser.species_data)} Pokemon with data")
    print(f"Found {len(parser.macro_definitions)} macro definitions")
    
    # Show some debug info for first few Pokemon
    count = 0
    for name, data in parser.species_data.items():
        if count < 5:  # Show first 5 pokemon for debugging
            print(f"\nDebug - {name}:")
            print(f"  Display name: {data['display_name']}")
            print(f"  Stats: {data['stats']}")
            print(f"  Types: {data['types']}")
            print(f"  Abilities: {data['abilities']}")
            count += 1
    
    # Create Word document
    print("\nCreating Word document...")
    output_file = parser.create_word_document()
    
    print(f"Complete! Pokemon data saved to: {output_file}")

if __name__ == "__main__":
    main()
