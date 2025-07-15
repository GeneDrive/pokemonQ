from pokemon_parser import PokemonParser
from pathlib import Path

parser = PokemonParser(Path('.'))
parser.load_constants()
parser.parse_species_files()

# Check if these Pokemon exist in the data
test_names = ['SPECIES_CHARIZARD_MEGA_X', 'SPECIES_ARCANINE_HISUIAN', 'SPECIES_MEWTWO_MEGA_Y']
for name in test_names:
    if name in parser.species_data:
        pokemon = parser.species_data[name]
        print(f'{name}: {pokemon["display_name"]}')
    else:
        print(f'{name}: NOT FOUND')
        
# Check some that might exist
print('\nChecking actual data:')
count = 0
for key, pokemon in parser.species_data.items():
    if count < 20:
        print(f'{key}: {pokemon["display_name"]}')
        count += 1
    else:
        break

# Look for forms in the data
print('\nLooking for forms:')
form_count = 0
for key, pokemon in parser.species_data.items():
    if any(form in key for form in ['MEGA', 'HISUIAN', 'GALARIAN', 'ALOLAN', 'PRIMAL']):
        print(f'{key}: {pokemon["display_name"]}')
        form_count += 1
        if form_count >= 10:
            break

# Test the form display name method
print('\nTesting form display names:')
test_forms = [
    ('ARCANINE_HISUIAN', 'Arcanine'),
    ('CHARIZARD_MEGA_X', 'Charizard'),
    ('CHARIZARD_MEGA_Y', 'Charizard'),
    ('ARTICUNO_GALARIAN', 'Articuno'),
    ('ALAKAZAM_MEGA', 'Alakazam'),
    ('PIKACHU', 'Pikachu')  # Regular form test
]

for species_name, display_name in test_forms:
    if species_name in parser.species_data:
        form_name = parser.get_form_display_name(species_name, display_name)
        print(f'{species_name} -> {form_name}')
    else:
        print(f'{species_name}: NOT IN DATA')
