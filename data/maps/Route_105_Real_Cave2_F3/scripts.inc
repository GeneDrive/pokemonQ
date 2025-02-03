.set LOCALID_POKEMON_UXIE, 1
.set LOCALID_POKEMON_AZELF, 2
.set LOCALID_POKEMON_MESPRIT, 3

Route_105_Real_Cave2_F3_MapScripts::
	.byte 0

IzalaCity_Garden_EventScript_Pokemon_Uxie::
	lockall
	waitse
	playmoncry SPECIES_UXIE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_UXIE, 30
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, IzalaCity_Garden_EventScript_Pokemon_Return_Uxie
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, IzalaCity_Garden_EventScript_Pokemon_Return_Uxie
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IzalaCity_Garden_EventScript_Pokemon_Return2_Uxie
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IzalaCity_Garden_EventScript_Pokemon_Return2_Uxie
	releaseall
	end

IzalaCity_Garden_EventScript_Pokemon_Return_Uxie::
	setflag FLAG_HIDE_UXIE
	fadescreen FADE_TO_BLACK
	delay 10
	removeobject LOCALID_POKEMON_UXIE
	fadescreen FADE_FROM_BLACK
	return

IzalaCity_Garden_EventScript_Pokemon_Return2_Uxie::
	releaseall

IzalaCity_Garden_EventScript_Pokemon_Azelf::
	lockall
	waitse
	playmoncry SPECIES_AZELF, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_AZELF, 30
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, IzalaCity_Garden_EventScript_Pokemon_Return_Azelf
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, IzalaCity_Garden_EventScript_Pokemon_Return_Azelf
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IzalaCity_Garden_EventScript_Pokemon_Return2_Azelf
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IzalaCity_Garden_EventScript_Pokemon_Return2_Azelf
	releaseall
	end

IzalaCity_Garden_EventScript_Pokemon_Return_Azelf::
	setflag FLAG_HIDE_AZELF
	fadescreen FADE_TO_BLACK
	delay 10
	removeobject LOCALID_POKEMON_AZELF
	fadescreen FADE_FROM_BLACK
	return

IzalaCity_Garden_EventScript_Pokemon_Return2_Azelf::
	releaseall

IzalaCity_Garden_EventScript_Pokemon_Mesprit::
	lockall
	waitse
	playmoncry SPECIES_MESPRIT, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MESPRIT, 30
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, IzalaCity_Garden_EventScript_Pokemon_Return_Mesprit
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, IzalaCity_Garden_EventScript_Pokemon_Return_Mesprit
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IzalaCity_Garden_EventScript_Pokemon_Return2_Mesprit
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IzalaCity_Garden_EventScript_Pokemon_Return2_Mesprit
	releaseall
	end

IzalaCity_Garden_EventScript_Pokemon_Return_Mesprit::
	setflag FLAG_HIDE_MESPRIT
	fadescreen FADE_TO_BLACK
	delay 10
	removeobject LOCALID_POKEMON_MESPRIT
	fadescreen FADE_FROM_BLACK
	return

IzalaCity_Garden_EventScript_Pokemon_Return2_Mesprit::
	releaseall