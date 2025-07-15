from pokemon_parser import PokemonParser
from pathlib import Path
import re

parser = PokemonParser(Path('.'))
parser.load_constants()

# Let's manually check the source files for Electrode
species_dir = Path('.') / "src" / "data" / "pokemon" / "species_info"

print("Searching for ELECTRODE in source files...")
print("=" * 50)

for gen_file in species_dir.glob("gen_*.h"):
    with open(gen_file, 'r', encoding='utf-8') as f:
        content = f.read()
        
    if 'ELECTRODE' in content:
        print(f"\nFound ELECTRODE in {gen_file.name}")
        
        # Find the ELECTRODE entry
        electrode_match = re.search(r'\[SPECIES_ELECTRODE\]\s*=\s*\{([^}]+)\}', content, re.DOTALL)
        if electrode_match:
            electrode_data = electrode_match.group(1)
            print("ELECTRODE data block:")
            print("-" * 30)
            print(electrode_data[:1000])  # Show first 1000 chars
            print("-" * 30)
            
            # Check for abilities pattern
            abilities_match = re.search(r'\.abilities\s*=\s*\{\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*\}', electrode_data)
            if abilities_match:
                print("Found abilities pattern:")
                print(f"  Ability 1: {abilities_match.group(1)}")
                print(f"  Ability 2: {abilities_match.group(2)}")
                print(f"  Ability 3: {abilities_match.group(3)}")
            else:
                print("No abilities pattern found in data block")
                
                # Check if there are any macro references
                macro_refs = re.findall(r'(\w+_MISC_INFO)', electrode_data)
                if macro_refs:
                    print(f"Found macro references: {macro_refs}")
                    
                    # Parse macros to see what they contain
                    parser.parse_macros(gen_file)
                    for macro_name in macro_refs:
                        if macro_name in parser.macro_definitions:
                            macro_content = parser.macro_definitions[macro_name]
                            print(f"\nMacro {macro_name} content:")
                            print(macro_content[:500])
                            
                            # Check for abilities in macro
                            macro_abilities = re.search(r'\.abilities\s*=\s*\{\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*\}', macro_content)
                            if macro_abilities:
                                print(f"Found abilities in macro:")
                                print(f"  Ability 1: {macro_abilities.group(1)}")
                                print(f"  Ability 2: {macro_abilities.group(2)}")  
                                print(f"  Ability 3: {macro_abilities.group(3)}")
        else:
            print("Could not extract ELECTRODE data block")

# Let's also check a few other problematic Pokemon
print("\n" + "=" * 50)
print("Checking other Pokemon with missing abilities...")

problem_pokemon = ['GASTLY', 'GENGAR', 'MEW']
for poke_name in problem_pokemon:
    print(f"\nSearching for {poke_name}...")
    
    for gen_file in species_dir.glob("gen_*.h"):
        with open(gen_file, 'r', encoding='utf-8') as f:
            content = f.read()
            
        if f'SPECIES_{poke_name}' in content:
            print(f"Found {poke_name} in {gen_file.name}")
            
            # Find the entry
            pattern = rf'\[SPECIES_{poke_name}\]\s*=\s*\{{([^}}]+)\}}'
            match = re.search(pattern, content, re.DOTALL)
            if match:
                data_block = match.group(1)
                print(f"Data block snippet: {data_block[:200]}...")
                
                # Check for abilities
                abilities_match = re.search(r'\.abilities\s*=\s*\{\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*\}', data_block)
                if abilities_match:
                    print(f"  Has abilities: {abilities_match.group(1)}, {abilities_match.group(2)}, {abilities_match.group(3)}")
                else:
                    print("  No abilities found in data block")
            break
