.set LOCALID_RED, 0

City3_Secret_MapScripts::
	.byte 0

City3_Secret_EventScript_StartBattle::
	applymovement LOCALID_RED, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RED, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox City3_Secret_Text_BattleIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MARTHA, City3_Secret_Text_BattleIntro
	msgbox City3_Secret_Text_BattleEnd, MSGBOX_DEFAULT
	closemessage
	bufferspeciesname STR_VAR_1, SPECIES_NICKIT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_NICKIT
	givemon SPECIES_NICKIT, 10
	playfanfare MUS_OBTAIN_ITEM
	message City3_Secret_Text_Received
	waitfanfare
	call Common_EventScript_TransferredToPC
	msgbox City3_Secret_Text_BattleEnd2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_PETALBURG_SECRET_DONE
	warp MAP_PETALBURG_CITY, 14, 3
	releaseall
	end

City3_Secret_Text_BattleIntro:
	.string "...$"

City3_Secret_Text_BattleEnd:
	.string "Good job, here's something\n"
	.string "For your trouble.$"

City3_Secret_Text_BattleEnd2:
	.string "Now leave me alone...\p"
	.string "I have to continue development...$"

City3_Secret_Text_Received:
	.string "{PLAYER} received a Yamask!$"