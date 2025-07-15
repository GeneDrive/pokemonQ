from pokemon_parser import PokemonParser
from pathlib import Path

parser = PokemonParser(Path('.'))
parser.load_constants()
parser.parse_species_files()

print("Checking for Pokemon with missing abilities...")
print("=" * 50)

# Find Pokemon with no abilities
no_abilities = []
incomplete_abilities = []
all_pokemon = []

for name, pokemon in parser.species_data.items():
    all_pokemon.append(name)
    
    if not pokemon['abilities']:
        no_abilities.append((name, pokemon['display_name']))
    elif len(pokemon['abilities']) < 1:  # Should have at least one ability
        incomplete_abilities.append((name, pokemon['display_name'], pokemon['abilities']))

print(f"Total Pokemon: {len(all_pokemon)}")
print(f"Pokemon with no abilities: {len(no_abilities)}")
print(f"Pokemon with incomplete abilities: {len(incomplete_abilities)}")

if no_abilities:
    print("\nPokemon with NO abilities found:")
    for i, (name, display_name) in enumerate(no_abilities[:20]):  # Show first 20
        print(f"  {i+1}. {name}: {display_name}")
    if len(no_abilities) > 20:
        print(f"  ... and {len(no_abilities) - 20} more")

if incomplete_abilities:
    print("\nPokemon with incomplete abilities:")
    for name, display_name, abilities in incomplete_abilities[:10]:
        print(f"  {name}: {display_name} - {abilities}")

# Let's also check a few specific Pokemon to see their raw data
print("\nChecking specific Pokemon raw data:")
test_pokemon = ['BULBASAUR', 'CHARMANDER', 'SQUIRTLE', 'PIKACHU']

for poke_name in test_pokemon:
    if poke_name in parser.species_data:
        pokemon = parser.species_data[poke_name]
        print(f"\n{poke_name}:")
        print(f"  Display: {pokemon['display_name']}")
        print(f"  Abilities: {pokemon['abilities']}")
        print(f"  Types: {pokemon['types']}")
        print(f"  Has stats: {bool(pokemon['stats'])}")
    else:
        print(f"\n{poke_name}: NOT FOUND in data")

# Check if some Pokemon might be getting filtered out
print(f"\nTotal Pokemon found: {len(parser.species_data)}")
print("First 10 Pokemon names in data:")
for i, name in enumerate(list(parser.species_data.keys())[:10]):
    print(f"  {i+1}. {name}")
