.set LOCALID_WINONAEVENT, 1
.set LOCALID_WINONALEADER, 2
.set LOCALID_WALLY, 3
.set LOCALID_PROFESSOR, 4

PetalburgCity_Gym_Real_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_Gym_Real_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Gym_Real_OnWarp
	.byte 0

PetalburgCity_Gym_Real_OnTransition:
	special RotatingGate_InitPuzzle
	end

PetalburgCity_Gym_Real_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, PetalburgCity_Gym_Real_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
PetalburgCity_Gym_Real_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end
	
PetalburgCity_Gym_Real_Walked_In_First_Time::
	applymovement LOCALID_WINONAEVENT, Common_Movement_FacePlayer
	waitmovement 0
	goto PetalburgCity_Gym_Real_Walked_In_First_Time_2
	end
	
PetalburgCity_Gym_Real_Walked_In_First_Time_Left::
	applymovement LOCALID_WINONAEVENT, Common_Movement_FacePlayer
	waitmovement 0
	goto PetalburgCity_Gym_Real_Walked_In_First_Time_2_left
	end

PetalburgCity_Gym_Real_Walked_In_First_Time_2::
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Real_Block_Player_Face_Down
	waitmovement 0
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Real_Walk_To_Winona
	waitmovement 0
	delay 5
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona2, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox PetalburgCity_Gym_Real_Text_Hello_Wally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WINONAEVENT, PetalburgCity_Gym_Real_Block_Player_Face_Right
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Real_Block_Player_Face_Left
	waitmovement 0
	delay 5
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona3, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox PetalburgCity_Gym_Real_Text_Hello_Wally2, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona4, MSGBOX_DEFAULT
	closemessage
	delay 5
	goto PetalburgCity_Gym_Real_Wally_Give_Piplup
	end

PetalburgCity_Gym_Real_Walked_In_First_Time_2_left::
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Real_Block_Player_Face_Down
	waitmovement 0
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Real_Walk_To_Winona_Left
	waitmovement 0
	delay 5
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona2, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox PetalburgCity_Gym_Real_Text_Hello_Wally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WINONAEVENT, PetalburgCity_Gym_Real_Block_Player_Face_Right
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Real_Block_Player_Face_Left
	waitmovement 0
	delay 5
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona3, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox PetalburgCity_Gym_Real_Text_Hello_Wally2, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona4, MSGBOX_DEFAULT
	closemessage
	delay 5
	goto PetalburgCity_Gym_Real_Wally_Give_Piplup
	end

PetalburgCity_Gym_Real_Walk_To_Winona::
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Real_Walk_To_Winona_Left::
	walk_up
	walk_right
	walk_up
	step_end

PetalburgCity_Gym_Real_Wally_Walk_Down::
	walk_down
	walk_down
	face_left
	step_end

PetalburgCity_Gym_Real_Wally_Walk_Up::
	walk_up
	walk_up
	face_down
	step_end

PetalburgCity_Gym_Real_Block_Exit_Walk::
	walk_down
	step_end

PetalburgCity_Gym_Real_Block_Player_Face_Up::
	face_up
	step_end

PetalburgCity_Gym_Real_Block_Player_Face_Down::
	face_down
	step_end

PetalburgCity_Gym_Real_Block_Player_Face_Left::
	face_left
	step_end

PetalburgCity_Gym_Real_Block_Player_Face_Right::
	face_right
	step_end

PetalburgCity_Gym_Real_Wally_Give_Piplup::
	playfanfare MUS_OBTAIN_ITEM
	msgbox PetalburgCity_Gym_Real_Text_Receive_Piplup, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 5
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona5, MSGBOX_DEFAULT
	closemessage
	delay 5
	goto PetalburgCity_Gym_Real_Wally_Start_Battle
	end

PetalburgCity_Gym_Real_Wally_Start_Battle::
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Real_Wally_Walk_Down
	waitmovement 0
	applymovement LOCALID_WINONAEVENT, PetalburgCity_Gym_Real_Block_Player_Face_Down
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Real_Block_Player_Face_Right
	waitmovement 0
	msgbox PetalburgCity_Gym_Real_Text_Hello_Wally3, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MARY, PetalburgCity_Gym_Real_Text_Wally_Defeat
	setvar VAR_PETALBURG_REAL_GYM_STATE, 1
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Real_Wally_Walk_Up
	waitmovement 0
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Real_Block_Player_Face_Left
	waitmovement 0
	applymovement LOCALID_WINONAEVENT, PetalburgCity_Gym_Real_Block_Player_Face_Right
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Real_Block_Player_Face_Up
	waitmovement 0
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona6, MSGBOX_DEFAULT
	closemessage
	delay 5
	pokenavcall PetalburgCity_Gym_Real_Text_Professor
	waitmessage
	delay 5
	applymovement LOCALID_WINONAEVENT, PetalburgCity_Gym_Real_Block_Player_Face_Down
	waitmovement 0
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona7, MSGBOX_DEFAULT
	closemessage
	delay 5
	setvar VAR_ROUTE101_STATE, 5
	setvar VAR_ROUTE103_TALK_EVENT_DONE, 1
	setflag FLAG_GYM_1_WALLY_DEFEATED
	applymovement LOCALID_WINONAEVENT, PetalburgCity_Gym_Real_Block_Player_Face_Right
	waitmovement 0
	end

PetalburgCity_Gym_Real_Block_Exit::
	applymovement LOCALID_WINONAEVENT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox PetalburgCity_Gym_Real_Text_Dont_Go, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Real_Block_Exit_Walk
	waitmovement 0
	releaseall
	end

PetalburgCity_Gym_Real_Wally_Talk::
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox PetalburgCity_Gym_Real_Text_After_Wally, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

PetalburgCity_Gym_Real_Winona_Talk::
	applymovement LOCALID_WINONAEVENT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox PetalburgCity_Gym_Real_Text_Dont_Go, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

PetalburgCity_Gym_Real_Professor_Walk_In::
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Real_Professor_Walk_Out::
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Real_EventScript_Alexia::
	trainerbattle_double TRAINER_ALEXIA, PetalburgCity_Gym_Real_Text_AlexiaIntro, PetalburgCity_Gym_Real_Text_AlexiaDefeat, PetalburgCity_Gym_Real_Text_Hello_Winona6
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_Real_EventScript_AlexiaPostBadge
	msgbox PetalburgCity_Gym_Real_Text_AlexiaPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_Real_EventScript_AlexiaPostBadge::
	msgbox PetalburgCity_Gym_Real_Text_AlexiaPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_Real_EventScript_George::
	trainerbattle_double TRAINER_GEORGE, PetalburgCity_Gym_Real_Text_GeorgeIntro, PetalburgCity_Gym_Real_Text_GeorgeDefeat, PetalburgCity_Gym_Real_Text_Hello_Winona6
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_Real_EventScript_GeorgePostBadge
	msgbox PetalburgCity_Gym_Real_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_Real_EventScript_GeorgePostBadge::
	msgbox PetalburgCity_Gym_Real_Text_GeorgePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_Real_EventScript_Parker::
	trainerbattle_double TRAINER_PARKER, PetalburgCity_Gym_Real_Text_ParkerIntro, PetalburgCity_Gym_Real_Text_ParkerDefeat, PetalburgCity_Gym_Real_Text_Hello_Winona6
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_Real_EventScript_ParkerPostBadge
	msgbox PetalburgCity_Gym_Real_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_Real_EventScript_ParkerPostBadge::
	msgbox PetalburgCity_Gym_Real_Text_ParkerPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_Real_EventScript_Winona::
	goto_if_set FLAG_RECEIVED_TM_AERIAL_ACE, PetalburgCity_Gym_Real_EventScript_WinonaDefeatedAfter
	trainerbattle_double TRAINER_WINONA_1, PetalburgCity_Gym_Real_Text_WinonaIntro, PetalburgCity_Gym_Real_Text_WinonaDefeat, PetalburgCity_Gym_Real_Text_Hello_Winona6, PetalburgCity_Gym_Real_EventScript_WinonaDefeated, NO_MUSIC
	release
	end

PetalburgCity_Gym_Real_EventScript_WinonaDefeated::
	message PetalburgCity_Gym_Real_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PetalburgCity_Gym_Real_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	closemessage
	goto PetalburgCity_Gym_Real_EventScript_GiveAerialAce
	end

PetalburgCity_Gym_Real_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox PetalburgCity_Gym_Real_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	msgbox PetalburgCity_Gym_Real_Text_ExplainBadge, MSGBOX_DEFAULT
	closemessage
	delay 5
	goto PetalburgCity_Gym_Real_EventScript_WinonaDefeatedAfter
	end

PetalburgCity_Gym_Real_EventScript_WinonaDefeatedAfter::
	msgbox PetalburgCity_Gym_Real_Text_WinonaPostBattle, MSGBOX_DEFAULT
	closemessage
	delay 5
	releaseall
	end

PetalburgCity_Gym_Real_EventScript_GymGuide::
	lockall
	faceplayer
	goto_if_set FLAG_GYM_ONE_ASSIST_DONE, PetalburgCity_Gym_Real_EventScript_GymGuide2
	msgbox PetalburgCity_Gym_Real_Text_GymGuideAdvice1, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_FRESH_WATER
	msgbox PetalburgCity_Gym_Real_Text_GymGuideAdvice2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GYM_ONE_ASSIST_DONE
	releaseall
	end

PetalburgCity_Gym_Real_EventScript_GymGuide2::
	msgbox PetalburgCity_Gym_Real_Text_GymGuideAdvice2, MSGBOX_DEFAULT
	closemessage
	release
	end

PetalburgCity_Gym_Real_Text_Hello_Winona:
	.string "Hey, speak of the devil. If it isn't\n"
	.string "{PLAYER} who i've heard so much about.\l"
	.string "Come over here for a second.$"

PetalburgCity_Gym_Real_Text_After_Wally:
	.string "I-I-I'll train a lot for next\n"
	.string "time {PLAYER}.\p"
	.string "I won't lose like that again!$"

PetalburgCity_Gym_Real_Text_Hello_Winona2:
	.string "This is Wally, he wants to become \n"
	.string "a strong trainer just like you.\p"
	.string "Come on, say hello!$"

PetalburgCity_Gym_Real_Text_Hello_Winona3:
	.string "HAHAHA with this cold weather? \n"
	.string "come on kiddo don't be so nervous!\l"
	.string "Why don't you two try having a battle \l"
	.string "to get him into the spirit!\p"
	.string "Come on, it'll be fun!$"

PetalburgCity_Gym_Real_Text_Hello_Winona4:
	.string "And a strange one at that, I've \n"
	.string "never seen a pokemon like that before!\p"
	.string "Here take one of mine.$"

PetalburgCity_Gym_Real_Text_Hello_Winona5:
	.string "Now go gettem.$"

PetalburgCity_Gym_Real_Text_Hello_Winona6:
	.string "See you two did fine.$"

PetalburgCity_Gym_Real_Text_Hello_Winona7:
	.string "You should go over there quickly! \n"
	.string "You can earn you're badge afterwards!\p"
	.string "I'll continue training with this kiddo.$"

PetalburgCity_Gym_Real_Text_Hello_Wally:
	.string "H-h-hello I'm Wally \n"
	.string "n-n-nice to meet you.\l"
	.string "Nice weather we're having right?$"
	
PetalburgCity_Gym_Real_Text_Hello_Wally2:
	.string "B-b-but I only have one pokemon...$"

PetalburgCity_Gym_Real_Text_Hello_Wally3:
	.string "O-o-oké, here I go!$"

PetalburgCity_Gym_Real_Text_Wally_Defeat:
	.string "I told her this would happen...$"

PetalburgCity_Gym_Real_Text_Receive_Piplup:
	.string "Wally received Winona's Piplup!$"

PetalburgCity_Gym_Real_Text_Dont_Go:
	.string "Hey, go help the professor first!\n"
	.string "You can earn you badge afterwards!$"

PetalburgCity_Gym_Real_Text_Professor:
	.string "HELP, a group is disturbing our \n"
	.string "gaurdian Pokemon on ROUTE 141!\p"
	.string "Quickly come help me and \n"
	.string "Jade over on ROUTE 141!$"

PetalburgCity_Gym_Real_Text_ParkerIntro:
	.string "You will never defeat me!\n"
	.string "Winona took me under her wing\n"
	.string "and I became her right hand woman.\p"
	.string "But then that Wally kid took\n"
	.string "My place next to her!\p"
	.string "I will defeat you and then\n"
	.string "that stupid kid and\l"
	.string "return to where I belong!$"

PetalburgCity_Gym_Real_Text_ParkerDefeat:
	.string "Wow you actually beat me!\n"
	.string "Maybe you're just to strong\n"
	.string "But I'll get that kid for sure.$"

PetalburgCity_Gym_Real_Text_ParkerPostBattle:
	.string "Good luck beating Winona.\n"
	.string "Don't let her blow you away.$"

PetalburgCity_Gym_Real_Text_ParkerPostBadge:
	.string "After you beat our LEADER, I\n"
	.string "still lost to that kid.$"

PetalburgCity_Gym_Real_Text_GeorgeIntro:
	.string "Winona made us do follow a bootcamp\n"
	.string "In the mountains close to here.\p"
	.string "That's why me and my partners\n"
	.string "can take the cold!$"

PetalburgCity_Gym_Real_Text_GeorgeDefeat:
	.string "I guess your training must\n"
	.string "have been even more frigid...$"

PetalburgCity_Gym_Real_Text_GeorgePostBattle:
	.string "I should have expected no less from\n"
	.string "her kid.\p"
	.string "No I don't mean Winona, Oh \n"
	.string "wait you don't know?\p"
	.string "Then she must have had a reason\n"
	.string "not to tell you.\p"
	.string "Forget I said anything.$"

PetalburgCity_Gym_Real_Text_GeorgePostBadge:
	.string "I'm going to keep going to bootcamp.\n"
	.string "One day, I may become a gymleader...$"

PetalburgCity_Gym_Real_Text_AlexiaIntro:
	.string "variation is the spice of life, \n"
	.string "as they say.\p"
	.string "So prepare yourself for my \n"
	.string "variety of flying POKéMON.$"

PetalburgCity_Gym_Real_Text_AlexiaDefeat:
	.string "How is this possible…$"

PetalburgCity_Gym_Real_Text_AlexiaPostBattle:
	.string "I think you've taught me a valuable\n"
	.string "lesson here.\p"
	.string "It seems I have become a Jack of\n"
	.string "all trades and a master of none.\p"
	.string "I will reflect on this so I\n"
	.string "can defeat you next time we face!$"

PetalburgCity_Gym_Real_Text_AlexiaPostBadge:
	.string "Hi! Have ever wanted to fly a plane?$"

PetalburgCity_Gym_Real_Text_WinonaIntro:
	.string "Hey there you are! Good job making\n"
	.string "it through my disciples!\p"
	.string "I still need to thank you for\n"
	.string "helping me with Wally earlier!\p"
	.string "I really saw a spark in him after\n"
	.string "he fought you and your POKéMON!\p"
	.string "I hope you two can become rivals\n"
	.string "to become even better trainers!\p"
	.string "Oh wait, sorry this should be your \n"
	.string "moment, let me get more serious.\p"
	.string "I am WINONA. I am the LEADER of\n"
	.string "the AUROPEAK POKéMON GYM.\p"
	.string "I have become strong with my POKéMON \n"
	.string "and we have soared the skies…\p"
	.string "However grueling the battle, we have\n"
	.string "triumphed with our great strength…\p"
	.string "Witness the overwelming strategie\n"
	.string "of me and my BIRD POKéMON!$"

PetalburgCity_Gym_Real_Text_WinonaDefeat:
	.string "You did really good kid,\n"
	.string "I can see why Wally enjoyed\l"
	.string "your battle so much…\p"
	.string "Take this GYM BADGE to show\n"
	.string "of your accomplishment!$"

PetalburgCity_Gym_Real_Text_WinonaPostBattle:
	.string "You better not start slacking off kid!\p"
	.string "Because I'll make sure to get way \n"
	.string "stronger for the next time we battle!$"

PetalburgCity_Gym_Real_Text_ReceivedFeatherBadge:
	.string "{PLAYER} received the FEATHER BADGE\n"
	.string "from WINONA.$"

PetalburgCity_Gym_Real_Text_ExplainFeatherBadgeTakeThis:
	.string "With the FEATHER BADGE, all POKéMON up\n"
	.string "to LV 24, even those received through\l"
	.string "trades, will obey your every command.\p"
	.string "You will also be able to use\n"
	.string "the HM move CUT outside of battle.\p"
	.string "And here you go…\n"
	.string "This is a gift from me.$"

PetalburgCity_Gym_Real_Text_ExplainAerialAce:
	.string "TM40 contains AERIAL ACE.\p"
	.string "Its speed…\n"
	.string "No POKéMON should be able to avoid it.\p"
	.string "… … … … … …$"

PetalburgCity_Gym_Real_Text_ExplainBadge:
	.string "With this badge you should be allowed\n"
	.string "to leave this area though the cave \l"
	.string "on ROUTE 101.\p"
	.string "So I wish you good luck on\n"
	.string "your travels.\p"
	.string "… … … … … …$"

PetalburgCity_Gym_Real_Text_RegisteredWinona:
	.string "Registered GYM LEADER WINONA\n"
	.string "in the POKéNAV.$"

PetalburgCity_Gym_Real_Text_GymGuideAdvice1:
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
	.string "WINONA, the GYM LEADER, is a user\n"
	.string "of FLYING-type POKéMON.\p"
	.string "The FLYING type is very tough, but\n"
	.string "it can't stand ELECTRIC-type, \l"
	.string "ICE-type and ROCK-type moves.\p"
	.string "But don't think those types\n"
	.string "will be enough, because the trainers\l"
	.string "here use some tough type combo's.\p"
	.string "Here's something to keep you refreshed.$"

	PetalburgCity_Gym_Real_Text_GymGuideAdvice2:
		.string "Well, go for it and good luck!$"