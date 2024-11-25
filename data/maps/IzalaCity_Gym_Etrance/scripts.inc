IzalaCity_Gym_Etrance_MapScripts::
	.byte 0

IzalaCity_Gym_Etrance_EventScript_TalkToNurse::
	lockall
	applymovement LOCALID_STARTGIRL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox IzalaCity_Gym_Etrance_Text_TalkToNurseStart, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, IzalaCity_Gym_Etrance_EventScript_Heal
	waitmessage
	msgbox IzalaCity_Gym_Etrance_Text_TalkToEnd, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

IzalaCity_Gym_Etrance_EventScript_Heal::
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	special HealPlayerParty
	return

IzalaCity_Gym_Etrance_EventScript_GymGuide::
	lockall
	faceplayer
	goto_if_set FLAG_GYM_TWO_ASSIST_DONE, IzalaCity_Gym_Etrance_EventScript_GymGuide2
	msgbox IzalaCity_Gym_Etrance_Text_GymGuideAdvice1, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_FRESH_WATER
	msgbox IzalaCity_Gym_Etrance_Text_GymGuideAdvice2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GYM_TWO_ASSIST_DONE
	releaseall
	end

IzalaCity_Gym_Etrance_EventScript_GymGuide2::
	msgbox IzalaCity_Gym_Etrance_Text_GymGuideAdvice2, MSGBOX_DEFAULT
	closemessage
	release
	end

IzalaCity_Gym_Etrance_Text_TalkToNurseStart:
	.string "Hello there brave trainer!\n"
	.string "You must be here to take on \l"
	.string "the GYM CHALLENGE! \p"
	.string "I'm the nurse here at the gym \n"
	.string "and I'm here to help you \l"
	.string "prepare for your battle! \p"
	.string "Would you like me to heal your \l"
	.string "pokemon before you go?$"

IzalaCity_Gym_Etrance_Text_TalkToEnd:
	.string "Good luck with the challenge\n"
	.string "ahead trainer trainer! \p"
	.string "I hope to see you return a victor!$"

IzalaCity_Gym_Etrance_Text_GymGuideAdvice1:
	.string "Yo, how's it going?\p"
	.string "Listen, my friend!\n"
	.string "Would you like to become the CHAMPION?\p"
	.string "I'm no TRAINER, not me, but I can\n"
	.string "sure give you winning advice.\p"
	.string "That's settled, then! We'll aim for the\n"
	.string "POKéMON CHAMPIONSHIP together!\p"
	.string "It's your job as a TRAINER to collect\n"
	.string "GYM BADGES, am I right?\p"
	.string "But GYM LEADERS aren't pushovers!\p"
	.string "And that's where I come in!\n"
	.string "I'm here to provide expert advice!\p"
	.string "BRAWLY, the GYM LEADER, is a user\n"
	.string "of FIGHTING-type POKéMON.\p"
	.string "And you can't forget about his spunky\n"
	.string "sister GRETA of course.\p"
	.string "She's also a GYM LEADER here and uses\n"
	.string "FAIRY-type POKéMON to spite her brother.\p"
	.string "But even when they clash they make\n"
	.string "a fierce combination.\p"
	.string "The FIGHTING type is very strong, but\n"
	.string "it can't stand FAIRY-type, \l"
	.string "PSYCHIC-type and FLYING-type moves.\p"
	.string "For the equally strong FAIRY-type you\n"
	.string "should use STEEL-type \l"
	.string "and POISON-type moves.\p"
	.string "This GYM CHALLENGE is a bit different\n"
	.string "than the others.\p"
	.string "Here you have to defeat every trainer\n"
	.string "in succession without any breaks and \l"
	.string "then the two GYM LEADERS.\p"
	.string "Making this a test of endurance and \n"
	.string "long term team planning planning.\p"
	.string "This GYM is a lot more difficult\n"
	.string "than the last one so it would be wise \l"
	.string "to prepare yourself well.\p"
	.string "Here's something to help you prepare.$"

	IzalaCity_Gym_Etrance_Text_GymGuideAdvice2:
		.string "Well, go for it and good luck!$"