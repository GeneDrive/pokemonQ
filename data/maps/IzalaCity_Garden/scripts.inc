.set LOCALID_POKEMON, 1

IzalaCity_Garden_MapScripts::
	.byte 0

IzalaCity_Garden_EventScript_Pokemon::
	lockall
	waitse
	playmoncry SPECIES_HAKAMO_O, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_HAKAMO_O, 28
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, IzalaCity_Garden_EventScript_Pokemon_Return
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IzalaCity_Garden_EventScript_Pokemon_Return2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IzalaCity_Garden_EventScript_Pokemon_Return2
	releaseall
	end

IzalaCity_Garden_EventScript_Pokemon_Return::
	setflag FLAG_DEFEATED_IZALA_GARDEN
	fadescreen FADE_TO_BLACK
	delay 10
	removeobject LOCALID_POKEMON
	fadescreen FADE_FROM_BLACK
	return

IzalaCity_Garden_EventScript_Pokemon_Return2::
	releaseall
	end