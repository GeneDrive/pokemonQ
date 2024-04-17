.set LOCALID_WINONAEVENT, 1
.set LOCALID_WINONALEADER, 2
.set LOCALID_WALLY, 3
.set LOCALID_PROFESSOR, 4

PetalburgCity_Gym_Real_MapScripts::
	.byte 0

PetalburgCity_Gym_Real_Walked_In_First_Time::
	applymovement LOCALID_WINONAEVENT, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Real_Walk_To_Winona
	waitmovement 0
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona2, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_Gym_Real_Text_Hello_Wally, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona3, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_Gym_Real_Text_Hello_Wally2, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona4, MSGBOX_DEFAULT
	closemessage
	goto PetalburgCity_Gym_Real_Wally_Give_Magikarp
	end

PetalburgCity_Gym_Real_Walk_To_Winona::
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Real_Wally_Walk_Down::
	walk_down
	walk_down
	face_left
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

PetalburgCity_Gym_Real_Wally_Give_Magikarp::
	msgbox PetalburgCity_Gym_Real_Text_Receive_Magikarp, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	closemessage
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona5, MSGBOX_DEFAULT
	closemessage
	goto PetalburgCity_Gym_Real_Wally_Start_Battle
	end

PetalburgCity_Gym_Real_Wally_Start_Battle::
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Real_Wally_Walk_Down
	waitmovement 0
	msgbox PetalburgCity_Gym_Real_Text_Hello_Wally3, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MARY, PetalburgCity_Gym_Real_Text_Wally_Defeat
	setvar VAR_PETALBURG_REAL_GYM_STATE, 1
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona6, MSGBOX_DEFAULT
	closemessage
	call PetalburgCity_Gym_Real_Move_Birch_To_Entrance
	playse SE_EXIT
	waitse
	applymovement LOCALID_PROFESSOR, PetalburgCity_Gym_Real_Professor_Walk_In
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Real_Block_Player_Face_Down
	waitmovement 0
	msgbox PetalburgCity_Gym_Real_Text_Professor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PROFESSOR, PetalburgCity_Gym_Real_Professor_Walk_Out
	waitmovement 0
	call PetalburgCity_Gym_Real_Remove_Birch
	playse SE_EXIT
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Real_Block_Player_Face_Up
	waitmovement 0
	msgbox PetalburgCity_Gym_Real_Text_Hello_Winona7, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE101_STATE, 5
	setvar VAR_ROUTE103_TALK_EVENT_DONE, 1
	end

PetalburgCity_Gym_Real_Block_Exit::
	msgbox PetalburgCity_Gym_Real_Text_Dont_Go, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Real_Block_Exit_Walk
	waitmovement 0
	releaseall
	end

PetalburgCity_Gym_Real_Move_Birch_To_Entrance::
	setobjectxyperm LOCALID_PROFESSOR, 42, 49
	return


PetalburgCity_Gym_Real_Remove_Birch::
	removeobject LOCALID_PROFESSOR
	return


PetalburgCity_Gym_Real_Professor_Walk_In::
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Real_Professor_Walk_Out::
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Real_Text_Hello_Winona:
	.string "Hey, speak of the devil. If it\n"
	.string "isn't {PLAYER} who i've heard so much about.\p"
	.string "Come over here for a second.$"

PetalburgCity_Gym_Real_Text_Hello_Winona2:
	.string "This is Wally, he wants to become \n"
	.string "a strong trainer just like you.\p"
	.string "Come on, say hello!$"

PetalburgCity_Gym_Real_Text_Hello_Winona3:
	.string "HAHAHA with this cold weather? come \n"
	.string "on kiddo don't be so nervous!\p"
	.string "Why don't you two try having a battle \n"
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
	.string "You can get you're gymbadge afterwards!\p"
	.string "I'll continue training with this kiddo.$"

PetalburgCity_Gym_Real_Text_Hello_Wally:
	.string "H-h-hello I'm Wally \n"
	.string " n-n-nice to meet you.\p"
	.string "Nice weather we're having right?$"
	
PetalburgCity_Gym_Real_Text_Hello_Wally2:
	.string "B-b-but I only have one pokemon...$"

PetalburgCity_Gym_Real_Text_Hello_Wally3:
	.string "O-o-oké, here I go!$"

PetalburgCity_Gym_Real_Text_Wally_Defeat:
	.string "I knew it!$"

PetalburgCity_Gym_Real_Text_Receive_Magikarp:
	.string "Wally received a Magikarp!$"

PetalburgCity_Gym_Real_Text_Dont_Go:
	.string "Hey, go help the professor.$"

PetalburgCity_Gym_Real_Text_Professor:
	.string "HELP, a group is disturbing our gaurdian\n"
	.string "Pokemon on ROUTE 101!\p"
	.string "Quickly come help me and may over there!$"