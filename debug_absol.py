from pokemon_parser import PokemonParser
from pathlib import Path

parser = PokemonParser(Path('.'))
parser.load_constants()
parser.parse_species_files()

# Look for Absol variants
absol_variants = []
for key, pokemon in parser.species_data.items():
    if 'ABSOL' in key:
        absol_variants.append((key, pokemon))

print('Found Absol variants:')
for key, pokemon in absol_variants:
    form_name = parser.get_form_display_name(key, pokemon['display_name'])
    print(f'{key}: {form_name}')
    print(f'  Types: {pokemon["types"]}')
    print(f'  Abilities: {pokemon["abilities"]}')
    print()
