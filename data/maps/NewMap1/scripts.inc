.set LOCALID_Grunt3, 3
.set LOCALID_Archie, 4
.set LOCALID_Jade, 5

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
	applymovement LOCALID_Grunt3, NewMap1_Face_Down
	waitmovement 0
	applymovement LOCALID_Grunt3, Common_Movement_ExclamationMark
	playbgm MUS_ENCOUNTER_AQUA, TRUE
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
	savebgm MUS_DUMMY
	fadedefaultbgm
	end

NewMap1_EventScript_Grunt3_BattleAfter2::
	msgbox NewMap1_Text_Grunt3_After_Give, MSGBOX_AUTOCLOSE
	waitmessage
	end

NewMap1_EventScript_Archie_Start::
	msgbox NewMap1_Text_Archie1, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	msgbox NewMap1_Text_Jade1, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	msgbox NewMap1_Text_Archie2, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	msgbox NewMap1_Text_Jade2, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	msgbox NewMap1_Text_Archie3, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	msgbox NewMap1_Text_Jade3, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	applymovement LOCALID_Jade, NewMap1_Face_Right
	waitmovement 0
	applymovement LOCALID_Jade, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox NewMap1_Text_Jade4, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	applymovement LOCALID_Archie, NewMap1_Walk_Out
	waitmovement 0
	applymovement LOCALID_Jade, NewMap1_Face_Left
	applymovement LOCALID_Jade, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox NewMap1_Text_Jade5, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	applymovement LOCALID_Jade, NewMap1_Face_Right
	waitmovement 0
	msgbox NewMap1_Text_Jade6, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	applymovement LOCALID_Jade, NewMap1_Walk_Out
	waitmovement 0
	removeobject LOCALID_Jade
	removeobject LOCALID_Archie
	setvar VAR_ROUTE103_TALK_EVENT_DONE, 3
	setvar VAR_ROUTE101_STATE, 6
	setvar VAR_PETALBURG_REAL_GYM_STATE, 2
	setflag FLAG_ITEM_ROUTE_101_CAVE_DONE
	setflag FLAG_ROUTE101_HIDE_OLD_MAN
	clearflag FLAG_ITEM_ROUTE_101_HIDE_RIVAL
	releaseall
	end

NewMap1_Walk_Out::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

NewMap1_Face_Left::
	face_left
	step_end

NewMap1_Face_Right::
	face_right
	step_end

NewMap1_Face_Down::
	face_down
	step_end

NewMap1_Text_Grunt1_Intro:
	.string "Don't you dare to interupt our mission!$"

NewMap1_Text_Grunt1_Outro:
	.string "Who is this kid!?$"

NewMap1_Text_Grunt1_PostBattle:
	.string "It doesn't matter,\n"
	.string "you'll never beat my boss!$"

NewMap1_Text_Grunt2_Intro:
	.string "What is a kid doing here? No matter,\n"
	.string "I just have to send you home crying!\l"
	.string "Like the baby you are!$"

NewMap1_Text_Grunt2_Outro:
	.string "sniff$"

NewMap1_Text_Grunt2_PostBattle:
	.string "BUHUHU!$"

NewMap1_Text_Grunt3_Intro:
	.string "This special POKéMON is MINE!$"

NewMap1_Text_Grunt3_Outro:
	.string "How can I be defeated by some kid!?$"

NewMap1_Text_Grunt3_PostBattle:
	.string "How could this happen?!$"

NewMap1_Text_Grunt3_Give:
	.string "Here take the stupid POKéMON$"

NewMap1_Text_Grunt3_After_Give:
	.string "We won't need it once we\n"
	.string "summon the mighty... \l"
	.string "Shucks, I almost said to much.\p"
	.string "You wont get away with this!!!$"

NewMap1_Text_Grunt1_NotEnoughMons:
	.string "Not enough POKéMON!$"

NewMap1_Text_Grunt2_NotEnoughMons:
	.string "Not enough POKéMON!$"

NewMap1_Text_Grunt3_NotEnoughMons:
	.string "Not enough POKéMON!$"

NewMap1_Text_ReceivedAmaura:
	.string "{PLAYER} received the mighty Amaura!$"

NewMap1_Text_Archie1:
	.string "???: HAHAHA!\n"
	.string "You're pretty good kid,\l"
	.string "But not good enough! HAHAHA!$"

NewMap1_Text_Archie2:
	.string "???: My name is Archie!\n"
	.string "I'm the leader of the\l"
	.string "mighty team aqua!$"

NewMap1_Text_Archie3:
	.string "Archie: That's none of your\n"
	.string "concern kid!\p"
	.string "We were looking for a strong\n"
	.string "POKéMON to increase our battle power,\p"
	.string "but it seems our informant sent us \n"
	.string "to the wrong place where only weak \l"
	.string "POKéMON reside.\p"
	.string "So, we'll be leaving now. $"

NewMap1_Text_Jade1:
	.string "JADE: Grrr! How could I lose again!\n"
	.string "Who even are you!?$"

NewMap1_Text_Jade2:
	.string "JADE: Team aqua? $"

NewMap1_Text_Jade3:
	.string "JADE: How exactly? Do you think \n"
	.string "I'll just let you leave!$"

NewMap1_Text_Jade4:
	.string "JADE: {PLAYER}?\n"
	.string "What are you doing here?$"

NewMap1_Text_Jade5:
	.string "JADE: He ran!?!$"

NewMap1_Text_Jade6:
	.string "JADE: Don't just stand there!\n"
	.string "Help me chase after him!$"
