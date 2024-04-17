.set LOCALID_PokeGuy, 2

OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	goto OldaleTown_House2_StartGivePokemon
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "When POKéMON battle, they eventually\n"
	.string "level up and become stronger.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "If the POKéMON with you become\n"
	.string "stronger, you'll be able to go farther\l"
	.string "away from here.$"

OldaleTown_House2_Text_Wow:
	.string "Oh wow you got a starter pokemon form the professor!\n"
	.string "Which one did you pick?$"

OldaleTown_House2_Text_Chespin:
	.string "Cool you picked CHESPIN!\n"
	.string "then you could use a FINNEON,\l"
	.string "would you like one?$"

OldaleTown_House2_Text_Chimchar:
	.string "Cool you picked CHIMCHAR!\n"
	.string "then you could use a SUNKERN,\l"
	.string "would you like one?$"

OldaleTown_House2_Text_Totodile:
	.string "Cool you picked TOTODILE!\n"
	.string "then you could use a SLUGMA,\l"
	.string "would you like one?$"

OldaleTown_House2_Text_ReceivedPokemon1:
	.string "{PLAYER} received a Chespin!$"

OldaleTown_House2_Text_ReceivedPokemon2:
	.string "{PLAYER} received a Sunkern!$"

OldaleTown_House2_Text_ReceivedPokemon3:
	.string "{PLAYER} received a Slugma!$"

OldaleTown_House2_Text_GoodLuck:
	.string "Good luck!$"

OldaleTown_House2_StartGivePokemon:
	applymovement LOCALID_PokeGuy, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_RECEIVED_STARTER_BASED_POKEMON, OldaleTown_House2_GoodLuck
	switch VAR_STARTER_MON
	case 0, OldaleTown_House2_StartGivePokemonDialog1
	case 1, OldaleTown_House2_StartGivePokemonDialog2
	case 2, OldaleTown_House2_StartGivePokemonDialog3
	end
	
OldaleTown_House2_StartGivePokemonDialog1:
	msgbox OldaleTown_House2_Text_Chespin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OldaleTown_House2_GivePokemon1
	goto_if_eq VAR_RESULT, NO, OldaleTown_House2_GoodLuck
	end

OldaleTown_House2_StartGivePokemonDialog2:
	msgbox OldaleTown_House2_Text_Chimchar, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OldaleTown_House2_GivePokemon2
	goto_if_eq VAR_RESULT, NO, OldaleTown_House2_GoodLuck
	end

OldaleTown_House2_StartGivePokemonDialog3:
	msgbox OldaleTown_House2_Text_Totodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OldaleTown_House2_GivePokemon3
	goto_if_eq VAR_RESULT, NO, OldaleTown_House2_GoodLuck
	end

OldaleTown_House2_GivePokemon1:
	givemon SPECIES_FINNEON, 5
	playfanfare MUS_OBTAIN_ITEM
	message OldaleTown_House2_Text_ReceivedPokemon1
	waitfanfare
	msgbox OldaleTown_House2_Text_GoodLuck, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_STARTER_BASED_POKEMON
	closemessage
	end


OldaleTown_House2_GivePokemon2:
	givemon SPECIES_SUNKERN, 5
	playfanfare MUS_OBTAIN_ITEM
	message OldaleTown_House2_Text_ReceivedPokemon2
	waitfanfare
	msgbox OldaleTown_House2_Text_GoodLuck, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_STARTER_BASED_POKEMON
	closemessage
	end

OldaleTown_House2_GivePokemon3:
	givemon SPECIES_SLUGMA, 5 
	playfanfare MUS_OBTAIN_ITEM
	message OldaleTown_House2_Text_ReceivedPokemon3
	waitfanfare
	msgbox OldaleTown_House2_Text_GoodLuck, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_STARTER_BASED_POKEMON
	closemessage
	end

OldaleTown_House2_GoodLuck:
	msgbox OldaleTown_House2_Text_GoodLuck, MSGBOX_DEFAULT
	end