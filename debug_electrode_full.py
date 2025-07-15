from pokemon_parser import PokemonParser
from pathlib import Path
import re

parser = PokemonParser(Path('.'))
parser.load_constants()

# Let's look at the complete ELECTRODE entry to see its full structure
species_dir = Path('.') / "src" / "data" / "pokemon" / "species_info"

print("Full ELECTRODE entry analysis...")
print("=" * 50)

gen1_file = species_dir / "gen_1.h"
with open(gen1_file, 'r', encoding='utf-8') as f:
    content = f.read()

# Find the complete ELECTRODE entry with manual brace matching
electrode_start = content.find('[SPECIES_ELECTRODE]')
if electrode_start != -1:
    # Find the opening brace
    brace_start = content.find('{', electrode_start)
    if brace_start != -1:
        # Simple manual brace matching
        brace_count = 0
        brace_end = brace_start
        for i, char in enumerate(content[brace_start:], start=brace_start):
            if char == '{':
                brace_count += 1
            elif char == '}':
                brace_count -= 1
                if brace_count == 0:
                    brace_end = i
                    break
        
        if brace_end > brace_start:
            full_entry = content[electrode_start:brace_end+1]
            print("COMPLETE ELECTRODE ENTRY:")
            print("-" * 40)
            print(full_entry)
            print("-" * 40)
            
            # Check if abilities appear anywhere in the full entry
            if '.abilities' in full_entry:
                print("✓ Abilities found in complete entry!")
                abilities_match = re.search(r'\.abilities\s*=\s*\{\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*\}', full_entry)
                if abilities_match:
                    print(f"Abilities: {abilities_match.group(1)}, {abilities_match.group(2)}, {abilities_match.group(3)}")
            else:
                print("✗ No abilities in complete entry")

print("\n" + "=" * 50)
print("Comparing with a Pokemon that HAS abilities...")

# Let's check a Pokemon we know has abilities (like Bulbasaur)
bulbasaur_start = content.find('[SPECIES_BULBASAUR]')
if bulbasaur_start != -1:
    brace_start = content.find('{', bulbasaur_start)
    if brace_start != -1:
        # Manual brace matching for Bulbasaur too
        brace_count = 0
        brace_end = brace_start
        for i, char in enumerate(content[brace_start:], start=brace_start):
            if char == '{':
                brace_count += 1
            elif char == '}':
                brace_count -= 1
                if brace_count == 0:
                    brace_end = i
                    break
        
        if brace_end > brace_start:
            full_entry = content[bulbasaur_start:brace_end+1]
            print("BULBASAUR ENTRY (for comparison):")
            print("-" * 40)
            print(full_entry[:800])  # First 800 chars
            print("-" * 40)

print("\n" + "=" * 50)
print("Checking ability definitions for these Pokemon...")

# Check if there are any global ability definitions or if Gen 1 Pokemon work differently
ability_constants_file = Path('.') / "include" / "constants" / "abilities.h"
if ability_constants_file.exists():
    with open(ability_constants_file, 'r', encoding='utf-8') as f:
        abilities_content = f.read()
        
    print("Looking for patterns in abilities.h...")
    if 'ELECTRODE' in abilities_content:
        print("ELECTRODE mentioned in abilities.h")
    if 'STATIC' in abilities_content:
        print("STATIC ability found in abilities.h")
    if 'SOUNDPROOF' in abilities_content:
        print("SOUNDPROOF ability found in abilities.h")

# Check if there are conditional compilation directives affecting Gen 1 Pokemon
print("\nChecking for conditional compilation...")
conditional_patterns = [
    r'#if.*P_UPDATED_ABILITIES.*',
    r'#if.*GEN_[0-9].*',
    r'#ifdef.*ABILITIES.*'
]

for pattern in conditional_patterns:
    matches = re.findall(pattern, content, re.IGNORECASE)
    if matches:
        print(f"Found conditional compilation: {matches}")
