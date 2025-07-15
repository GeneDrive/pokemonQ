from pokemon_parser import PokemonParser
from pathlib import Path
import re

parser = PokemonParser(Path('.'))
parser.load_constants()

# Let's check all the *_MISC_INFO macros that might contain abilities
species_dir = Path('.') / "src" / "data" / "pokemon" / "species_info"

print("Searching for all MISC_INFO macros and their ability content...")
print("=" * 60)

for gen_file in species_dir.glob("gen_*.h"):
    with open(gen_file, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Find all MISC_INFO macro definitions
    misc_info_pattern = r'#define\s+(\w+_MISC_INFO)\s*\\?\s*(.*?)(?=\n#define|\n\[|$)'
    misc_info_matches = re.finditer(misc_info_pattern, content, re.DOTALL)
    
    for match in misc_info_matches:
        macro_name = match.group(1)
        macro_content = match.group(1)
        
        # Only check macros that might be related to our problematic Pokemon
        relevant_macros = [
            'ELECTRODE_MISC_INFO', 'VOLTORB_MISC_INFO', 'VOLTORB_FAMILY_MISC_INFO',
            'GASTLY_MISC_INFO', 'GENGAR_MISC_INFO', 'MEW_MISC_INFO',
            'METAPOD_MISC_INFO'
        ]
        
        if macro_name in relevant_macros:
            print(f"\nFound {macro_name} in {gen_file.name}")
            print("-" * 40)
            print(macro_content[:500])  # First 500 chars
            print("-" * 40)
            
            # Check for abilities in this macro
            abilities_match = re.search(r'\.abilities\s*=\s*\{\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*\}', macro_content)
            if abilities_match:
                print(f"✓ {macro_name} contains abilities:")
                print(f"  {abilities_match.group(1)}, {abilities_match.group(2)}, {abilities_match.group(3)}")
            else:
                print(f"✗ {macro_name} does not contain abilities")
                
                # Check if it references another macro
                family_ref = re.search(r'(\w+_FAMILY_MISC_INFO)', macro_content)
                if family_ref:
                    print(f"  → References family macro: {family_ref.group(1)}")

# Now let's get the actual content of these macros from the parser
print("\n" + "=" * 60)
print("Loading macros through the parser...")

for gen_file in species_dir.glob("gen_*.h"):
    parser.parse_macros(gen_file)

print(f"\nTotal macros loaded: {len(parser.macro_definitions)}")

# Check specific macros for our problematic Pokemon
target_macros = [
    'ELECTRODE_MISC_INFO', 'VOLTORB_MISC_INFO', 'VOLTORB_FAMILY_MISC_INFO',
    'GASTLY_MISC_INFO', 'GENGAR_MISC_INFO', 'MEW_MISC_INFO'
]

for macro_name in target_macros:
    if macro_name in parser.macro_definitions:
        macro_content = parser.macro_definitions[macro_name]
        print(f"\n{macro_name}:")
        print("-" * 30)
        print(macro_content[:300])
        
        # Check for abilities
        abilities_match = re.search(r'\.abilities\s*=\s*\{\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*\}', macro_content)
        if abilities_match:
            print(f"✓ Contains abilities: {abilities_match.group(1)}, {abilities_match.group(2)}, {abilities_match.group(3)}")
        else:
            print("✗ No abilities found")
            
            # Check for family macro reference
            family_ref = re.search(r'(\w+_FAMILY_MISC_INFO)', macro_content)
            if family_ref:
                family_macro = family_ref.group(1)
                print(f"  → References: {family_macro}")
                
                if family_macro in parser.macro_definitions:
                    family_content = parser.macro_definitions[family_macro]
                    family_abilities = re.search(r'\.abilities\s*=\s*\{\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*\}', family_content)
                    if family_abilities:
                        print(f"  ✓ Family macro has abilities: {family_abilities.group(1)}, {family_abilities.group(2)}, {family_abilities.group(3)}")
    else:
        print(f"\n{macro_name}: Not found in parser")
