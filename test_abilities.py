from pokemon_parser import PokemonParser
from pathlib import Path

parser = PokemonParser(Path('.'))
parser.load_constants()
parser.parse_species_files()

# Test different ability configurations
test_pokemon = [
    'PIKACHU',      # Should have different abilities in each slot
    'ALAKAZAM',     # Should have different abilities
    'CHARIZARD',    # Should have different abilities
    'ARCANINE',     # May have only one regular ability
    'MEWTWO'        # Check ability setup
]

print('Testing different ability configurations:')
for name in test_pokemon:
    if name in parser.species_data:
        pokemon = parser.species_data[name]
        form_name = parser.get_form_display_name(name, pokemon['display_name'])
        print(f'\n{name}: {form_name}')
        print(f'  Abilities: {pokemon["abilities"]}')
    else:
        print(f'\n{name}: NOT FOUND')

# Also test some megas
mega_test = [
    'CHARIZARD_MEGA_X',
    'CHARIZARD_MEGA_Y',
    'ALAKAZAM_MEGA'
]

print('\n\nTesting Mega abilities:')
for name in mega_test:
    if name in parser.species_data:
        pokemon = parser.species_data[name]
        form_name = parser.get_form_display_name(name, pokemon['display_name'])
        print(f'\n{name}: {form_name}')
        print(f'  Abilities: {pokemon["abilities"]}')
    else:
        print(f'\n{name}: NOT FOUND')
