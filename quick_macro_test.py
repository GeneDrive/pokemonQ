from pokemon_parser import PokemonParser
from pathlib import Path
import re

# Quick test of macro expansion for ELECTRODE specifically
parser = PokemonParser(Path('.'))
parser.load_constants()

# Load macros
species_dir = Path('.') / "src" / "data" / "pokemon" / "species_info"
for gen_file in species_dir.glob("gen_*.h"):
    parser.parse_macros(gen_file)

print("Testing recursive macro expansion...")
print("=" * 50)

# Test ELECTRODE_MISC_INFO expansion
if 'ELECTRODE_MISC_INFO' in parser.macro_definitions:
    original_macro = parser.macro_definitions['ELECTRODE_MISC_INFO']
    print("Original ELECTRODE_MISC_INFO:")
    print(original_macro[:200])
    
    print("\nAfter recursive expansion:")
    expanded_macro = parser.expand_macros(original_macro)
    print(expanded_macro[:500])
    
    # Check for abilities in expanded version
    abilities_match = re.search(r'\.abilities\s*=\s*\{\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*\}', expanded_macro)
    if abilities_match:
        print(f"\n✓ SUCCESS! Found abilities after expansion:")
        print(f"  {abilities_match.group(1)}, {abilities_match.group(2)}, {abilities_match.group(3)}")
    else:
        print("\n✗ Still no abilities found after expansion")
else:
    print("ELECTRODE_MISC_INFO macro not found")

# Test with a simple ELECTRODE data block
print("\n" + "=" * 50)
print("Testing with ELECTRODE data block...")

electrode_data = "ELECTRODE_MISC_INFO, .types = { TYPE_ELECTRIC, TYPE_ELECTRIC }"
print("Original data:", electrode_data)

expanded_data = parser.expand_macros(electrode_data)
print("Expanded data:")
print(expanded_data[:300])

# Check for abilities
abilities_match = re.search(r'\.abilities\s*=\s*\{\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*\}', expanded_data)
if abilities_match:
    print(f"\n✓ Found abilities: {abilities_match.group(1)}, {abilities_match.group(2)}, {abilities_match.group(3)}")
else:
    print("\n✗ No abilities found")
