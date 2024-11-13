.set LOCALID_GUY, 1

Route105_new_cave1_F2_MapScripts::
	.byte 0

Route105_new_cave1_F2_EventScript_TalkToGuy::
	lockall
	applymovement LOCALID_GUY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route105_new_cave1_F2_Text_BoredOfTraining, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route105_new_cave1_F2_Text_BoredOfTraining:
	.string "Man I'm sick of training here...\n"
	.string "It makes you just want to go\l"
	.string "take a rest you know?$"