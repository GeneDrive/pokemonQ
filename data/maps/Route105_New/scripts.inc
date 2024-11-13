.set LOCALID_STARTGIRL, 3

Route105_New_MapScripts::
	.byte 0

Route105_New_EventScript_TalkStartGirl::
	lockall
	applymovement LOCALID_STARTGIRL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route105_New_Text_LoveTheWind, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route105_New_Text_LoveTheWind:
	.string "I just love coming here and\n"
	.string "Feeling the wind through my hair$"