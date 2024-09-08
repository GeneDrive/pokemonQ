FrigidFalls_3F_MapScripts::
	.byte 0

FrigidFalls_3F_EventScript_Georgia::
	trainerbattle_double TRAINER_GEORGIA, FrigidFalls_3F_Text_GeorgiaIntro, FrigidFalls_3F_Text_GeorgiaDefeat, FrigidFalls_3F_Text_GeorgiaDefeat
	msgbox FrigidFalls_3F_Text_GeorgiaPostBattle, MSGBOX_AUTOCLOSE
	end

FrigidFalls_3F_Text_GeorgiaIntro:
	.string "I want to make my own GYM one day.\n"
	.string "So, I'm studying how to slide around.$"

FrigidFalls_3F_Text_GeorgiaDefeat:
	.string "I didn't study battling enough!$"

FrigidFalls_3F_Text_GeorgiaPostBattle:
	.string "You're strong, aren't you?\n"
	.string "Maybe even enough to be a GYM LEADER!$"
