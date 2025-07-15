#!/usr/bin/env python3
"""
Test script to debug Pokemon parsing
"""

import re

# Test data from the file
test_data = """
    [SPECIES_BULBASAUR] =
    {
        .baseHP        = 45,
        .baseAttack    = 49,
        .baseDefense   = 49,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = { TYPE_GRASS, TYPE_POISON },
        .catchRate = 45,
        .expYield = 64,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_GRASS },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CHLOROPHYLL },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Bulbasaur"),
        .cryId = CRY_BULBASAUR,
        .natDexNum = NATIONAL_DEX_BULBASAUR,
        .categoryName = _("Seed"),
        .height = 7,
        .weight = 69,
        .description = COMPOUND_STRING(
            "Bulbasaur can be seen napping in bright\\n"
            "sunlight. There is a seed on its back.\\n"
            "By soaking up the sun's rays, the seed\\n"
            "grows progressively larger."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Bulbasaur, 40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Bulbasaur,
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        BACK_PIC(Bulbasaur, 56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Bulbasaur),
        ICON(Bulbasaur, 4),
        .footprint = gMonFootprint_Bulbasaur,
        LEARNSETS(Bulbasaur),
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_IVYSAUR}),
    },
"""

print("Testing regex patterns...")

# Test types parsing
types_pattern = r'\.types\s*=\s*\{\s*TYPE_(\w+)\s*,\s*TYPE_(\w+)\s*\}'
types_match = re.search(types_pattern, test_data)
print(f"Types match: {types_match}")
if types_match:
    print(f"Type 1: {types_match.group(1)}")
    print(f"Type 2: {types_match.group(2)}")

# Test abilities parsing
abilities_pattern = r'\.abilities\s*=\s*\{\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*,\s*ABILITY_(\w+)\s*\}'
abilities_match = re.search(abilities_pattern, test_data)
print(f"Abilities match: {abilities_match}")
if abilities_match:
    print(f"Ability 1: {abilities_match.group(1)}")
    print(f"Ability 2: {abilities_match.group(2)}")
    print(f"Ability 3: {abilities_match.group(3)}")

# Test species pattern
species_pattern = r'\[SPECIES_(\w+)\]\s*=\s*\{([^}]*(?:\{[^}]*\}[^}]*)*)\}'
species_match = re.search(species_pattern, test_data, re.DOTALL)
print(f"Species match: {species_match is not None}")
if species_match:
    print(f"Species name: {species_match.group(1)}")
    print(f"Data block length: {len(species_match.group(2))}")
