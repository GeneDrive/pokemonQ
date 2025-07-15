from pokemon_parser import PokemonParser
from pathlib import Path
import re

parser = PokemonParser(Path('.'))
parser.load_constants()

# Let's search for VOLTORB_FAMILY_MISC_INFO macro
species_dir = Path('.') / "src" / "data" / "pokemon" / "species_info"

print("Searching for VOLTORB_FAMILY_MISC_INFO macro...")
print("=" * 50)

for gen_file in species_dir.glob("gen_*.h"):
    with open(gen_file, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Look for the macro definition
    if 'VOLTORB_FAMILY_MISC_INFO' in content:
        print(f"\nFound VOLTORB_FAMILY_MISC_INFO in {gen_file.name}")
        
        # Find the macro definition
        macro_pattern = r'#define\s+VOLTORB_FAMILY_MISC_INFO\s*\\?\s*(.*?)(?=\n#define|\n\[|$)'
        macro_match = re.search(macro_pattern, content, re.DOTALL)
        
        if macro_match:
            macro_content = macro_match.group(1)
            print("VOLTORB_FAMILY_MISC_INFO macro content:")
            print("-" * 40)
            print(macro_content)
            print("-" * 40)
            
            # Check for abilities in the macro
            abilities_match = re.search(r'\.abilities\s*=\s*\{\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*\}', macro_content)
            if abilities_match:
                print(f"✓ Found abilities in macro:")
                print(f"  Ability 1: {abilities_match.group(1)}")
                print(f"  Ability 2: {abilities_match.group(2)}")
                print(f"  Ability 3: {abilities_match.group(3)}")
            else:
                print("✗ No abilities found in macro")
        else:
            print("Could not extract macro definition")

# Let's also check how ELECTRODE uses this macro
print("\n" + "=" * 50)
print("Checking how ELECTRODE uses VOLTORB_FAMILY_MISC_INFO...")

for gen_file in species_dir.glob("gen_*.h"):
    with open(gen_file, 'r', encoding='utf-8') as f:
        content = f.read()
    
    if 'SPECIES_ELECTRODE' in content:
        # Find ELECTRODE entry
        electrode_pattern = r'\[SPECIES_ELECTRODE\]\s*=\s*\{([^}]+)\}'
        electrode_match = re.search(electrode_pattern, content, re.DOTALL)
        
        if electrode_match:
            electrode_data = electrode_match.group(1)
            print(f"\nELECTRODE entry in {gen_file.name}:")
            print("-" * 30)
            print(electrode_data)
            print("-" * 30)
            
            if 'VOLTORB_FAMILY_MISC_INFO' in electrode_data:
                print("✓ ELECTRODE uses VOLTORB_FAMILY_MISC_INFO macro")
            else:
                print("✗ ELECTRODE does not use VOLTORB_FAMILY_MISC_INFO macro")

# Let's also check VOLTORB for comparison
print("\n" + "=" * 50)
print("Checking VOLTORB for comparison...")

for gen_file in species_dir.glob("gen_*.h"):
    with open(gen_file, 'r', encoding='utf-8') as f:
        content = f.read()
    
    if 'SPECIES_VOLTORB' in content:
        voltorb_pattern = r'\[SPECIES_VOLTORB\]\s*=\s*\{([^}]+)\}'
        voltorb_match = re.search(voltorb_pattern, content, re.DOTALL)
        
        if voltorb_match:
            voltorb_data = voltorb_match.group(1)
            print(f"\nVOLTORB entry in {gen_file.name}:")
            print("-" * 30)
            print(voltorb_data[:300])  # First 300 chars
            print("-" * 30)
