#!/usr/bin/env python3
"""
Debug specific Pokemon parsing
"""

import re
from pathlib import Path
from pokemon_parser import PokemonParser

def test_specific_pokemon():
    base_path = Path(__file__).parent
    parser = PokemonParser(base_path)
    parser.load_constants()
    
    # Parse just gen_1.h to test Arcanine
    gen1_file = base_path / "src" / "data" / "pokemon" / "species_info" / "gen_1.h"
    parser.parse_macros(gen1_file)
    
    print("Sample macro definitions:")
    for name, content in list(parser.macro_definitions.items())[:3]:
        print(f"{name}: {content[:100]}...")
    
    # Find ARCANINE_HISUIAN specifically
    with open(gen1_file, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Find the Arcanine Hisuian entry
    start_pattern = r'\[SPECIES_ARCANINE_HISUIAN\]\s*=\s*\{'
    match = re.search(start_pattern, content)
    if match:
        start_pos = match.end() - 1
        
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
        
        arcanine_data = content[start_pos + 1:end_pos]
        print("\nOriginal Arcanine Hisuian data:")
        print(arcanine_data[:500])
        
        expanded_data = parser.expand_macros(arcanine_data)
        print("\nExpanded Arcanine Hisuian data:")
        print(expanded_data[:500])
        
        # Test type parsing
        types_match = re.search(r'\.types\s*=\s*\{\s*TYPE_(\w+)\s*,\s*TYPE_(\w+)\s*\}', expanded_data)
        if types_match:
            print(f"\nFound types: {types_match.group(1)}, {types_match.group(2)}")
        else:
            print("\nNo types found in expanded data")
            
        # Test ability parsing
        abilities_match = re.search(r'\.abilities\s*=\s*\{\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*\}', expanded_data)
        if abilities_match:
            print(f"Found abilities: {abilities_match.group(1)}, {abilities_match.group(2)}, {abilities_match.group(3)}")
        else:
            print("No abilities found in expanded data")

if __name__ == "__main__":
    test_specific_pokemon()
