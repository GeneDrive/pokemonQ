from pokemon_parser import PokemonParser
from pathlib import Path

print("Testing improved parser - checking ability coverage...")
print("=" * 60)

# Create parser and parse all data
parser = PokemonParser(Path('.'))
parser.load_constants()
parser.parse_species_files()

# Count Pokemon with and without abilities
total_pokemon = len(parser.species_data)
pokemon_with_abilities = 0
pokemon_without_abilities = 0
missing_abilities_list = []

for species_id, pokemon_data in parser.species_data.items():
    if pokemon_data['abilities'] and pokemon_data['abilities'] != ['Ability not found']:
        pokemon_with_abilities += 1
    else:
        pokemon_without_abilities += 1
        missing_abilities_list.append(pokemon_data['name'])

print(f"RESULTS:")
print(f"  Total Pokemon: {total_pokemon}")
print(f"  ✅ With abilities: {pokemon_with_abilities}")
print(f"  ❌ Still missing abilities: {pokemon_without_abilities}")
print(f"  🎯 Success rate: {(pokemon_with_abilities/total_pokemon)*100:.1f}%")

# Show improvement
original_missing = 196
fixed_count = original_missing - pokemon_without_abilities
print(f"\nIMPROVEMENT:")
print(f"  🔧 Fixed {fixed_count} Pokemon that were missing abilities")
print(f"  📉 Reduced missing abilities from {original_missing} to {pokemon_without_abilities}")

# Show some examples of fixed Pokemon
print(f"\nEXAMPLES OF FIXED POKEMON:")
fixed_examples = ['ELECTRODE', 'VOLTORB']
for name in fixed_examples:
    for species_id, pokemon_data in parser.species_data.items():
        if pokemon_data['name'] == name:
            print(f"  {name}: {pokemon_data['abilities']}")
            break

# Show remaining problematic Pokemon (first 10)
if missing_abilities_list:
    print(f"\nSTILL MISSING ABILITIES (first 10):")
    for name in missing_abilities_list[:10]:
        print(f"  - {name}")
    if len(missing_abilities_list) > 10:
        print(f"  ... and {len(missing_abilities_list) - 10} more")

print(f"\n" + "=" * 60)
