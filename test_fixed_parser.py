from pokemon_parser import PokemonParser
from pathlib import Path

# Test the updated parser on ELECTRODE specifically
parser = PokemonParser(Path('.'))
parser.load_constants()

# Parse the files to load all data
parser.parse_species_files()

print("Testing updated parser on ELECTRODE...")
print("=" * 50)

# Check if ELECTRODE now has abilities
electrode_found = False
for species_id, pokemon_data in parser.species_data.items():
    if pokemon_data['name'] == 'ELECTRODE':
        electrode_found = True
        print(f"ELECTRODE (ID: {species_id}):")
        print(f"  Name: {pokemon_data['name']}")
        print(f"  Types: {pokemon_data['types']}")
        print(f"  Abilities: {pokemon_data['abilities']}")
        print(f"  Base HP: {pokemon_data['stats']['hp']}")
        break

if not electrode_found:
    print("ELECTRODE not found in parsed data")

print("\n" + "=" * 50)
print("Testing a few other previously problematic Pokemon...")

problem_pokemon = ['GASTLY', 'GENGAR', 'VOLTORB', 'MEW']
for target_name in problem_pokemon:
    found = False
    for species_id, pokemon_data in parser.species_data.items():
        if pokemon_data['name'] == target_name:
            found = True
            print(f"\n{target_name}:")
            print(f"  Abilities: {pokemon_data['abilities']}")
            break
    
    if not found:
        print(f"\n{target_name}: Not found")

print("\n" + "=" * 50)
print("Quick count of Pokemon with and without abilities...")

total_pokemon = len(parser.species_data)
pokemon_with_abilities = 0
pokemon_without_abilities = 0

for species_id, pokemon_data in parser.species_data.items():
    if pokemon_data['abilities'] and pokemon_data['abilities'] != ['Ability not found']:
        pokemon_with_abilities += 1
    else:
        pokemon_without_abilities += 1

print(f"Total Pokemon: {total_pokemon}")
print(f"With abilities: {pokemon_with_abilities}")
print(f"Without abilities: {pokemon_without_abilities}")
print(f"Improvement: {pokemon_without_abilities} Pokemon still missing abilities (was 196)")
