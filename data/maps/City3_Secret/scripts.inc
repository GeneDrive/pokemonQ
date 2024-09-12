.set LOCALID_RED, 0

City3_Secret_MapScripts::
	.byte 0

City3_Secret_EventScript_StartBattle::
	msgbox City3_Secret_Text_BattleIntro, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalGiveBalls
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, City3_Secret_Text_BattleIntro
	

City3_Secret_Text_BattleIntro:
	.string "...$"

City3_Secret_Text_BattleEnd:
	.string "Good job, here's something\n"
	.string "For your trouble.$"

City3_Secret_Text_BattleEnd2:
	.string "Now leave me alone...\p"
	.string "I have to continue development...$"