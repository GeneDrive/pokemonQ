FrigidFalls_5F_MapScripts::
	.byte 0

FrigidFalls_5F_EventScript_Jade_Hide_Grunts::
	setflag FLAG_ITEM_FRIGGIDFALLS_F6_HIDE_GRUNTS
	releaseall
	end

FrigidFalls_5F_EventScript_Justin::
	trainerbattle_double TRAINER_JUSTIN, FrigidFalls_5F_Text_JustinIntro, FrigidFalls_5F_Text_JustinDefeat, FrigidFalls_5F_Text_JustinDefeat
	msgbox FrigidFalls_5F_Text_JustinPostBattle, MSGBOX_AUTOCLOSE
	end

FrigidFalls_5F_Text_JustinIntro:
	.string "I keep coming back to this same place!\n"
	.string "This ice doesn't make any sense!$"

FrigidFalls_5F_Text_JustinDefeat:
	.string "I'm already having trouble, and then\n"
	.string "you have to beat me? It's not fair!$"

FrigidFalls_5F_Text_JustinPostBattle:
	.string "It's full of ice here!\n"
	.string "It's too slippery in here! Help!$"
