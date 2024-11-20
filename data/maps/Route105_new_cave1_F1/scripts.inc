.set LOCALID_FATGUY, 1

Route105_new_cave1_F1_MapScripts::
	.byte 0

Route105_new_cave1_F1_EventScript_TalkToFatGuy::
	lockall
	applymovement LOCALID_FATGUY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route105_new_cave1_F1_Text_RarePokemon, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route105_new_cave1_F1_Text_RarePokemon:
	.string "I heard from someone that one of\n"
	.string "these cave exits has a legendary\l"
	.string "pokemon!\p"
	.string "I gotta keep looking. I will find\n"
	.string "it before anyone else and finally\l"
	.string "defeat the gym leader!$"