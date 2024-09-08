FrigidFalls_1F_MapScripts::
	.byte 0

FrigidFalls_1F_EventScript_Paul::
	trainerbattle_double TRAINER_PAUL, FrigidFalls_1F_Text_PaulIntro, FrigidFalls_1F_Text_PaulDefeat, FrigidFalls_1F_Text_PaulDefeat
	msgbox FrigidFalls_1F_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
	end

FrigidFalls_1F_EventScript_Ted::
	trainerbattle_double TRAINER_TED, FrigidFalls_1F_Text_TedIntro, FrigidFalls_1F_Text_TedDefeat, FrigidFalls_1F_Text_TedDefeat
	msgbox FrigidFalls_1F_Text_TedPostBattle, MSGBOX_AUTOCLOSE
	end

FrigidFalls_1F_Text_PaulIntro:
	.string "Oh! You're on your second TRICK HOUSE\n"
	.string "challenge!$"

FrigidFalls_1F_Text_PaulDefeat:
	.string "You're good at battling too?$"

FrigidFalls_1F_Text_PaulPostBattle:
	.string "The TRICK MASTER rigged all the tricks\n"
	.string "in this house all by himself.$"

FrigidFalls_1F_Text_TedIntro:
	.string "Which switch closes which hole?$"

FrigidFalls_1F_Text_TedDefeat:
	.string "After that battle, I'm even more\n"
	.string "confused!$"

FrigidFalls_1F_Text_TedPostBattle:
	.string "Can I get you to push all the buttons\n"
	.string "for me?$"
