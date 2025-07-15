from pathlib import Path
import re

# Check if there are any global ability assignments or default patterns
base_path = Path('.')

print("Searching for ability assignments outside of species files...")
print("=" * 60)

# Search in include files for any ability mappings
include_dir = base_path / "include"
if include_dir.exists():
    for header_file in include_dir.rglob("*.h"):
        if "species" not in header_file.name:  # Skip species files, we already checked those
            try:
                with open(header_file, 'r', encoding='utf-8') as f:
                    content = f.read()
                
                # Look for patterns like ELECTRODE abilities
                if 'ELECTRODE' in content and 'ABILITY' in content:
                    print(f"\nFound ELECTRODE and ABILITY in {header_file.relative_to(base_path)}")
                    
                    # Find relevant lines
                    lines = content.split('\n')
                    for i, line in enumerate(lines):
                        if 'ELECTRODE' in line and 'ABILITY' in line:
                            print(f"  Line {i+1}: {line.strip()}")
                            
                # Look for ability assignment patterns
                ability_patterns = [
                    r'SPECIES_ELECTRODE.*ABILITY_\w+',
                    r'ABILITY_\w+.*SPECIES_ELECTRODE',
                    r'\.abilities.*ELECTRODE',
                    r'ELECTRODE.*\.abilities'
                ]
                
                for pattern in ability_patterns:
                    matches = re.findall(pattern, content, re.IGNORECASE)
                    if matches:
                        print(f"\nFound ability pattern in {header_file.relative_to(base_path)}: {matches}")
                        
            except Exception as e:
                pass  # Skip files that can't be read

# Check src directory for any ability assignments
src_dir = base_path / "src"
if src_dir.exists():
    print(f"\n{'='*60}")
    print("Searching in src directory...")
    
    for c_file in src_dir.rglob("*.c"):
        if c_file.name in ['pokemon.c', 'abilities.c', 'species.c']:  # Focus on likely files
            try:
                with open(c_file, 'r', encoding='utf-8') as f:
                    content = f.read()
                
                # Look for electrode ability assignments
                if 'ELECTRODE' in content and 'ABILITY' in content:
                    print(f"\nFound ELECTRODE and ABILITY in {c_file.relative_to(base_path)}")
                    
                    lines = content.split('\n')
                    for i, line in enumerate(lines):
                        if 'ELECTRODE' in line and 'ABILITY' in line:
                            print(f"  Line {i+1}: {line.strip()}")
                            
            except Exception as e:
                pass

# Check for any conditional compilation that might affect abilities
print(f"\n{'='*60}")
print("Checking for conditional ability compilation...")

species_files = list((base_path / "src" / "data" / "pokemon" / "species_info").glob("*.h"))
for species_file in species_files:
    try:
        with open(species_file, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # Look for conditional blocks that might contain abilities for problematic Pokemon
        conditional_blocks = re.findall(r'#if[^#]*?ELECTRODE[^#]*?#endif', content, re.DOTALL | re.IGNORECASE)
        if conditional_blocks:
            print(f"\nFound conditional ELECTRODE block in {species_file.name}:")
            for block in conditional_blocks:
                print(block[:300])  # First 300 chars
                
    except Exception as e:
        pass

print(f"\n{'='*60}")
print("Summary of investigation:")
print("- ELECTRODE entry has no .abilities field")
print("- BULBASAUR and other working Pokemon have explicit .abilities fields")
print("- Some Pokemon data structures may be incomplete or use different formats")
print("- This affects ~196 Pokemon (17% of total)")
print("- The issue appears to be missing ability data in the source files themselves")
