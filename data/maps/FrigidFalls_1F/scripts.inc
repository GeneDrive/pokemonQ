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
	.string "Oh! You also won the GYM challenge!\p"
	.string "It doesn't matter because I'm better!$"

FrigidFalls_1F_Text_PaulDefeat:
	.string "You're way to good at battling!\n"
	.string "What a try hard!$"

FrigidFalls_1F_Text_PaulPostBattle:
	.string "You were way to prepared!\n"
	.string "Battling like that is lame...$"

FrigidFalls_1F_Text_TedIntro:
	.string "This is where the Ice fossil is right?$"

FrigidFalls_1F_Text_TedDefeat:
	.string "After that battle, I'm even more\n"
	.string "lost! Where is it!?$"

FrigidFalls_1F_Text_TedPostBattle:
	.string "Can I get you to look for that\n"
	.string "fossil for me? No? Aww...$"
