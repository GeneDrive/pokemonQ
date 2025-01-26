.set LOCALID_POKEMON, 1
PetalburgCity_pyramid_room1_MapScripts::
	.byte 0

PetalburgCity_pyramid_room1_EventScript_Pokemon::
	lockall
	waitse
	playmoncry SPECIES_PATRAT, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_PATRAT, 18
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PetalburgCity_pyramid_room1_EventScript_Pokemon_Return
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, PetalburgCity_pyramid_room1_EventScript_Pokemon_Return
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PetalburgCity_pyramid_room1_EventScript_Pokemon_Return2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PetalburgCity_pyramid_room1_EventScript_Pokemon_Return2
	releaseall
	end

PetalburgCity_pyramid_room1_EventScript_Pokemon_Return::
	setflag FLAG_DESSERT_PUZZLE_POKEMON_GET
	fadescreen FADE_TO_BLACK
	delay 10
	removeobject LOCALID_POKEMON
	fadescreen FADE_FROM_BLACK
	return

PetalburgCity_pyramid_room1_EventScript_Pokemon_Return2::
	releaseall
	end