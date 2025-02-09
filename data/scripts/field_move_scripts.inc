@ Interact with cuttable tree
EventScript_CutTree::
	lockall
	goto_if_unset FLAG_RECEIVED_HM_CUT, EventScript_CheckTreeCantCut
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

@ Use cut from party menu
EventScript_UseCut::
	lockall
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

EventScript_CutTreeDown::
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

Movement_CutTreeDown:
	cut_tree
	step_end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut::
	closemessage
	releaseall
	end

Text_WantToCut:
	.string "This tree looks like it can be\n"
	.string "CUT down!\p"
	.string "Would you like to CUT it?$"

Text_MonUsedFieldMove:
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

Text_CantCut:
	.string "This tree looks like it can be\n"
	.string "CUT down!$"

@ Interact with smashable rock
EventScript_RockSmash::
	lockall
	goto_if_unset FLAG_BADGE03_GET, EventScript_CantSmashRock
	checkpartymove MOVE_ROCK_SMASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

EventScript_SmashRock::
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

EventScript_EndSmash::
	releaseall
	end

Movement_SmashRock:
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash::
	closemessage
	releaseall
	end

Text_WantToSmash:
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use ROCK SMASH?$"

Text_CantSmash:
	.string "It's a rugged rock, but a POKéMON\n"
	.string "may be able to smash it.$"

EventScript_StrengthBoulder::
	lockall
	goto_if_unset FLAG_BADGE04_GET, EventScript_CantStrength
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	checkpartymove MOVE_STRENGTH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantStrength
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToStrength, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelStrength
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_UseStrength::
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder::
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength::
	closemessage
	releaseall
	end

Text_WantToStrength:
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use STRENGTH?$"

Text_MonUsedStrength:
	.string "{STR_VAR_1} used STRENGTH!\p"
	.string "{STR_VAR_1}'s STRENGTH made it\n"
	.string "possible to move boulders around!$"

Text_CantStrength:
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.$"

Text_StrengthActivated:
	.string "STRENGTH made it possible to move\n"
	.string "boulders around.$"

EventScript_UseWaterfall::
	lockall
	checkpartymove MOVE_WATERFALL
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantWaterfall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_WATERFALL
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall::
	lockall

EventScript_CantWaterfall::
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall::
	releaseall
	end

Text_CantWaterfall:
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"

Text_WantToWaterfall:
	.string "It's a large waterfall.\n"
	.string "Would you like to use WATERFALL?$"

Text_MonUsedWaterfall:
	.string "{STR_VAR_1} used WATERFALL.$"

EventScript_UseDive::
	lockall
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantDive
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToDive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive::
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive::
	releaseall
	end

EventScript_UseDiveUnderwater::
	lockall
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndSurface
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface::
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface::
	releaseall
	end

EventScript_StartTrash::
	msgbox Text_TrashWhat, MSGBOX_DEFAULT
	waitmessage
	multichoice 20, 0, MULTI_UNUSED_ASH_VENDOR, FALSE
	switch VAR_RESULT
	case 0, EventScript_TrashSuperPotion
	case 1, EventScript_TrashPokeball
	case 2, EventScript_TrashPokedoll
	case 3, EventScript_TrashReaperCloth
	case 4, EventScript_TrashNugget
	case 5, EventScript_TrashPearl
	case 6, EventScript_Trash4
	end

EventScript_TrashSuperPotion::
	checkitem ITEM_SUPER_POTION
	goto_if_eq VAR_RESULT, FALSE, EventScript_TrashNoItem
	removeitem ITEM_SUPER_POTION
	goto EventScript_Trash1
	end


EventScript_TrashPokeball::
	checkitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, EventScript_TrashNoItem
	removeitem ITEM_GREAT_BALL
	goto EventScript_Trash1
	end

EventScript_TrashPokedoll::
	checkitem ITEM_POKE_DOLL
	goto_if_eq VAR_RESULT, FALSE, EventScript_TrashNoItem
	removeitem ITEM_POKE_DOLL
	goto EventScript_Trash2
	end

EventScript_TrashReaperCloth::
	checkitem ITEM_REAPER_CLOTH
	goto_if_eq VAR_RESULT, FALSE, EventScript_TrashNoItem
	removeitem ITEM_REAPER_CLOTH
	goto EventScript_Trash2
	end

EventScript_TrashNugget::
	checkitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, EventScript_TrashNoItem
	removeitem ITEM_NUGGET
	goto EventScript_Trash3
	end

EventScript_TrashPearl::
	checkitem ITEM_PEARL
	goto_if_eq VAR_RESULT, FALSE, EventScript_TrashNoItem
	removeitem ITEM_PEARL
	goto EventScript_Trash3
	end

EventScript_Trash1::
	closemessage
	special TrashWildEncounterCommon
	switch VAR_RESULT
	case 0, EventScript_Trash_Nothing
	case 1, EventScript_Trash_Trubbish
	case 2, EventScript_Trash_Chingling
	case 3, EventScript_Trash_Shuppet
	case 4, EventScript_Trash_Meltan
	case 5, EventScript_Trash_Gimmighoul
	waitstate
	releaseall
	end

EventScript_Trash2::
	closemessage
	special TrashWildEncounterCommon
	switch VAR_RESULT
	case 0, EventScript_Trash_Nothing
	case 1, EventScript_Trash_Shuppet
	case 2, EventScript_Trash_Chingling
	case 3, EventScript_Trash_Trubbish
	case 4, EventScript_Trash_Gimmighoul
	case 5, EventScript_Trash_Meltan
	waitstate
	releaseall
	end

EventScript_Trash3::
	closemessage
	special TrashWildEncounterCommon
	switch VAR_RESULT
	case 0, EventScript_Trash_Nothing
	case 1, EventScript_Trash_Chingling
	case 2, EventScript_Trash_Gimmighoul
	case 3, EventScript_Trash_Meltan
	case 4, EventScript_Trash_Trubbish
	case 5, EventScript_Trash_Shuppet
	waitstate
	releaseall
	end

EventScript_Trash4::
	releaseall
	end

EventScript_Trash_Nothing::
	msgbox Text_TrashNothing, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EventScript_TrashNoItem::
	msgbox Text_TrashFailed, MSGBOX_DEFAULT
	closemessage
	goto EventScript_StartTrash
	end

EventScript_Trash_Trubbish::
	waitse
	msgbox Text_TrashSomething, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_TRUBBISH, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_TRUBBISH, 5
	dowildbattle
	goto EventScript_Trash_Nothing
	end

EventScript_Trash_Chingling::
	waitse
	msgbox Text_TrashSomething, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_CHINGLING, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CHINGLING, 5
	dowildbattle
	goto EventScript_Trash_Nothing
	end

EventScript_Trash_Shuppet::
	waitse
	msgbox Text_TrashSomething, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_SHUPPET, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_SHUPPET, 5
	dowildbattle
	goto EventScript_Trash_Nothing
	end

EventScript_Trash_Meltan::
	waitse
	msgbox Text_TrashSomething, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_MELTAN, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MELTAN, 5
	dowildbattle
	goto EventScript_Trash_Nothing
	end

EventScript_Trash_Gimmighoul::
	waitse
	msgbox Text_TrashSomething, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_GIMMIGHOUL, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_GIMMIGHOUL, 5
	dowildbattle
	goto EventScript_Trash_Nothing
	end

Text_CantDive:
	.string "The sea is deep here. A POKéMON\n"
	.string "may be able to go underwater.$"

Text_WantToDive:
	.string "The sea is deep here.\n"
	.string "Would you like to use DIVE?$"

Text_MonUsedDive:
	.string "{STR_VAR_1} used DIVE.$"

Text_CantSurface:
	.string "Light is filtering down from above.\n"
	.string "A POKéMON may be able to surface.$"

Text_WantToSurface:
	.string "Light is filtering down from above.\n"
	.string "Would you like to use DIVE?$"

EventScript_FailSweetScent::
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent:
	.string "Looks like there's nothing here…$"

Text_TrashNothing:
	.string "Thank you for depositing!$"

Text_TrashSomething:
	.string "Something jumped out!$"

Text_TrashFailed:
	.string "You do not have this item!$"

Text_TrashWhat:
	.string "What do you want\n"
	.string "to throw out?$"