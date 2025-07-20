.set LOCALID_RED, 3

FallarborTown_Mart_MapScripts::
	.byte 0

FallarborTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FallarborTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_NONE
	release
	end

FallarborTown_Mart_EventScript_Woman::
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_PokefanM::
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	
FallarborTown_Mart_EventScript_StartBattle::
	applymovement LOCALID_RED, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RED, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox FallarborTown_Mart_Text_BattleIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MARTHA, FallarborTown_Mart_Text_BattleIntro
	msgbox FallarborTown_Mart_Text_BattleEnd, MSGBOX_DEFAULT
	closemessage
	bufferspeciesname STR_VAR_1, SPECIES_NICKIT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_NICKIT
	givemon SPECIES_NICKIT, 10
	playfanfare MUS_OBTAIN_ITEM
	message FallarborTown_Mart_Text_Received
	waitfanfare
	call Common_EventScript_TransferredToPC
	msgbox FallarborTown_Mart_Text_BattleEnd2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_PETALBURG_SECRET_DONE
	warp MAP_PETALBURG_CITY, 14, 3
	releaseall
	end

FallarborTown_Mart_Text_BattleIntro:
	.string "...$"

FallarborTown_Mart_Text_BattleEnd:
	.string "...\n"
	.string "...$"

FallarborTown_Mart_Text_BattleEnd2:
	.string "...\p"
	.string "...$"

FallarborTown_Mart_Text_Received:
	.string "{PLAYER} received a Yamask!$"

FallarborTown_Mart_Text_DecidingSkittyEvolve:
	.string "I'm having a hard time deciding if I\n"
	.string "should make my SKITTY evolve or not.\p"
	.string "I only have to use this MOON STONE,\n"
	.string "but it's so hard to decide…\p"
	.string "If I make it evolve, it will become\n"
	.string "much stronger.\p"
	.string "But it will look so different, too.$"

FallarborTown_Mart_Text_Skitty:
	.string "SKITTY: Miyao?$"

FallarborTown_Mart_Text_SellNuggetIFound:
	.string "This NUGGET I found here…\n"
	.string "I suppose I'll have to sell it, seeing\l"
	.string "as how it has no other use.$"

