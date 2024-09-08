.set LOCALID_NURSE, 1
.set LOCALID_FISHERMAN, 2

PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_Fisherman::
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, PetalburgCity_PokemonCenter_1F_EventScript_FishermanDone
	msgbox PetalburgCity_PokemonCenter_1F_Text_LikeFishing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_PokemonCenter_1F_EventScript_FishermanYes
	goto_if_eq VAR_RESULT, NO, PetalburgCity_PokemonCenter_1F_EventScript_FishermanNo
	end

PetalburgCity_PokemonCenter_1F_EventScript_FishermanYes::
	msgbox PetalburgCity_PokemonCenter_1F_Text_LikeFishingYes, MSGBOX_DEFAULT
	waitmessage
	trainerbattle_no_intro TRAINER_BERKE, PetalburgCity_PokemonCenter_1F_Text_Fisherman_Defeat
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox PetalburgCity_PokemonCenter_1F_Text_GiveRod, MSGBOX_DEFAULT
	waitmessage
	delay 5
	giveitem ITEM_OLD_ROD, 1
	msgbox PetalburgCity_PokemonCenter_1F_Text_WhatDoYouMean, MSGBOX_DEFAULT
	closemessage
	end

PetalburgCity_PokemonCenter_1F_EventScript_FishermanNo::
	msgbox PetalburgCity_PokemonCenter_1F_Text_LikeFishingNo, MSGBOX_DEFAULT
	closemessage
	end

PetalburgCity_PokemonCenter_1F_EventScript_FishermanDone::
	msgbox PetalburgCity_PokemonCenter_1F_Text_WhatDoYouMean, MSGBOX_DEFAULT
	closemessage
	end

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "That PC-based POKéMON Storage\n"
	.string "System…\p"
	.string "Whoever made it must be some kind\n"
	.string "of a scientific wizard!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "When my POKéMON ate an\n"
	.string "ORAN BERRY, it regained HP!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "There are many types of POKéMON.\p"
	.string "All types have their strengths and\n"
	.string "weaknesses against other types.\p"
	.string "Depending on the types of POKéMON,\n"
	.string "a battle could be easy or hard.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "For example, your Chespin\n"
	.string "is a GRASS/NORMAL type.\p"
	.string "It's strong against the WATER and\n"
	.string "GROUND types.\p"
	.string "But, it's weak against FIRE-type\n"
	.string "and FIGHTING-type POKéMON.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "For example, your Chimchar\n"
	.string "is a FIRE type.\p"
	.string "It's strong against the GRASS and\n"
	.string "BUG types.\p"
	.string "But, it's weak against WATER-type\n"
	.string "and ROCK-type POKéMON.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "For example, your Totodile\n"
	.string "is a WATER type.\p"
	.string "It's strong against the FIRE type.\p"
	.string "But, it's weak against GRASS-type\n"
	.string "and ELECTRIC-type POKéMON.$"

PetalburgCity_PokemonCenter_1F_Text_LikeFishing:
	.string "Hey young trainer, have you thought\n"
	.string "Of having a relaxed fishing session?$"

PetalburgCity_PokemonCenter_1F_Text_LikeFishingNo:
	.string "YOU HAVEN'T!?! You should really\n"
	.string "reconsider, it's very calming.$"

PetalburgCity_PokemonCenter_1F_Text_LikeFishingYes:
	.string "Good on you kid! It's always nice\n"
	.string "To find a fellow enthusiast.\p"
	.string "If you can defeat me I'll give you\n"
	.string "A new FISHING ROD.\p"
	.string "But don't take me lightly I've \n"
	.string "defeated many trainers in my day!$"

PetalburgCity_PokemonCenter_1F_Text_GiveRod:
	.string "Alright here is your \n"
	.string "new FISHING ROD.$"

PetalburgCity_PokemonCenter_1F_Text_Fisherman_Defeat:
	.string "Maybe I should stick to fishing…$"

PetalburgCity_PokemonCenter_1F_Text_WhatDoYouMean:
	.string "What do you mean the rod is old? \n"
	.string "It's looks very new to me.$"
	