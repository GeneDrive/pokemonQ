.set LOCALID_Grunt3, 3
.set LOCALID_Archie, 4
.set LOCALID_Steven, 5

NewMap1_MapScripts::
	.byte 0

NewMap1_EventScript_Grunt1_Battle::
	trainerbattle_double TRAINER_GRUNT_1_101_CAVE, NewMap1_Text_Grunt1_Intro, NewMap1_Text_Grunt1_Outro, NewMap1_Text_Grunt1_NotEnoughMons
	msgbox NewMap1_Text_Grunt1_PostBattle, MSGBOX_AUTOCLOSE
	waitmessage
	end

NewMap1_EventScript_Grunt2_Battle::
	trainerbattle_double TRAINER_GRUNT_2_101_CAVE, NewMap1_Text_Grunt2_Intro, NewMap1_Text_Grunt2_Outro, NewMap1_Text_Grunt2_NotEnoughMons
	msgbox NewMap1_Text_Grunt2_PostBattle, MSGBOX_AUTOCLOSE
	waitmessage
	end

NewMap1_EventScript_Grunt3_Battle::
	applymovement LOCALID_Grunt3, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_Grunt3, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox NewMap1_Text_Grunt3_Intro, MSGBOX_AUTOCLOSE
	waitmessage
	trainerbattle_no_intro TRAINER_GRUNT_3_101_CAVE, NewMap1_Text_Grunt3_Outro
	goto NewMap1_EventScript_Grunt3_BattleAfter
	end

NewMap1_EventScript_Grunt3_BattleAfter::
	msgbox NewMap1_Text_Grunt3_Give, MSGBOX_AUTOCLOSE
	bufferspeciesname STR_VAR_1, SPECIES_AMAURA
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_AMAURA
	givemon SPECIES_AMAURA, 9
	playfanfare MUS_OBTAIN_ITEM
	message NewMap1_Text_ReceivedAmaura
	waitfanfare
	call Common_EventScript_TransferredToPC
	msgbox NewMap1_Text_Grunt3_After_Give, MSGBOX_AUTOCLOSE
	waitmessage
	setvar VAR_ROUTE101_CAVE_STATE, 1
	end

NewMap1_EventScript_Grunt3_BattleAfter2::
	msgbox NewMap1_Text_Grunt3_After_Give, MSGBOX_AUTOCLOSE
	waitmessage
	end

NewMap1_EventScript_Archie_Start::
	msgbox NewMap1_Text_Archie1, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox NewMap1_Text_Steven1, MSGBOX_AUTOCLOSE
	waitmessage
	msgbox NewMap1_Text_Archie2, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement LOCALID_Steven, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_Steven, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox NewMap1_Text_Steven2, MSGBOX_AUTOCLOSE
	waitmessage
	setvar VAR_ROUTE103_TALK_EVENT_DONE, 3
	setvar VAR_ROUTE101_STATE, 6
	setflag FLAG_ITEM_ROUTE_101_CAVE_DONE
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 12
	end

NewMap1_Text_Grunt1_Intro:
	.string "Don't you dare to interupt our mission!$"

NewMap1_Text_Grunt1_Outro:
	.string "Who is this kid!?$"

NewMap1_Text_Grunt1_PostBattle:
	.string "It doesn't matter, you'll never beat my boss!$"

NewMap1_Text_Grunt2_Intro:
	.string "What is a kid doing here?\p"
	.string "No matter, I just have to send you home crying\n"
	.string "Like the baby you are!$"

NewMap1_Text_Grunt2_Outro:
	.string "sniff$"

NewMap1_Text_Grunt2_PostBattle:
	.string "BUHUHU!$"

NewMap1_Text_Grunt3_Intro:
	.string "This special pokemon is MINE!$"

NewMap1_Text_Grunt3_Outro:
	.string "How can I be defeated by some kid!?$"

NewMap1_Text_Grunt3_PostBattle:
	.string "How could this happen?!$"

NewMap1_Text_Grunt3_Give:
	.string "Here take the stupid pokemon$"

NewMap1_Text_Grunt3_After_Give:
	.string "We won't need it once we summon the mighty...\p"
	.string "Shucks, I almost said to much.\p"
	.string "You wont get away with this!!!.$"

NewMap1_Text_Grunt1_NotEnoughMons:
	.string "Not enough pokemon!$"

NewMap1_Text_Grunt2_NotEnoughMons:
	.string "Not enough pokemon!$"

NewMap1_Text_Grunt3_NotEnoughMons:
	.string "Not enough pokemon!$"

NewMap1_Text_ReceivedAmaura:
	.string "{PLAYER} received the mighty Amaura!$"

NewMap1_Text_Archie1:
	.string "OI!$"

NewMap1_Text_Archie2:
	.string "OI!$"

NewMap1_Text_Steven1:
	.string "OI!$"

NewMap1_Text_Steven2:
	.string "OI!$"