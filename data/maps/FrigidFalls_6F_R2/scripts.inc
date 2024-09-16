.set LOCALID_JADE, 3
.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 2
.set LOCALID_ARCHIE, 4

FrigidFalls_6F_R2_MapScripts::
	.byte 0

FrigidFalls_6F_R2_StartEvent::
	applymovement LOCALID_JADE, FrigidFalls_6F_R2_Movement_WalkRival
	applymovement OBJ_EVENT_ID_PLAYER, FrigidFalls_6F_R2_Movement_WalkToArchie
	waitmovement 0
	applymovement LOCALID_JADE, FrigidFalls_6F_R2_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_GRUNT_1, FrigidFalls_6F_R2_Movement_WalkGrunt1
	applymovement LOCALID_GRUNT_2, FrigidFalls_6F_R2_Movement_WalkGrunt2
	waitmovement 0
	msgbox FrigidFalls_6F_R2_Text_Jade_1, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox FrigidFalls_6F_R2_Text_Archie_1, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement LOCALID_JADE, FrigidFalls_6F_R2_Movement_FaceDown
	waitmovement 0
	msgbox FrigidFalls_6F_R2_Text_Jade_2, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement LOCALID_JADE, FrigidFalls_6F_R2_Movement_FaceUp
	waitmovement 0
	msgbox FrigidFalls_6F_R2_Text_Jade_3, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox FrigidFalls_6F_R2_Text_Archie_2, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox FrigidFalls_6F_R2_Text_Jade_4, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox FrigidFalls_6F_R2_Text_Archie_3, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox FrigidFalls_6F_R2_Text_Jade_5, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox FrigidFalls_6F_R2_Text_Archie_4, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox FrigidFalls_6F_R2_Text_Jade_6, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement LOCALID_JADE, FrigidFalls_6F_R2_Movement_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, FrigidFalls_6F_R2_Movement_FaceLeft
	waitmovement 0
	msgbox FrigidFalls_6F_R2_Text_Jade_7, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement LOCALID_JADE, FrigidFalls_6F_R2_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, FrigidFalls_6F_R2_Movement_FaceUp
	waitmovement 0
	msgbox FrigidFalls_6F_R2_Text_Archie_5, MSGBOX_DEFAULT
	closemessage
	delay 5
	trainerbattle_no_intro TRAINER_ALAN, FrigidFalls_6F_R2_Text_Archie_Defeat
	releaseall
	end

FrigidFalls_6F_R2_Movement_WalkRival:
	walk_up
	walk_left
	step_end

FrigidFalls_6F_R2_Movement_WalkToArchie:
	walk_up
	walk_up
	step_end

FrigidFalls_6F_R2_Movement_WalkGrunt1:
	walk_right
	walk_up
	step_end

FrigidFalls_6F_R2_Movement_WalkGrunt2:
	walk_left
	walk_left
	walk_up
	step_end

FrigidFalls_6F_R2_Movement_FaceUp:
	face_up
	step_end

FrigidFalls_6F_R2_Movement_FaceLeft:
	face_left
	step_end

FrigidFalls_6F_R2_Movement_FaceRight:
	face_right
	step_end

FrigidFalls_6F_R2_Movement_FaceDown:
	face_down
	step_end

FrigidFalls_6F_R2_Text_Jade_1:
	.string "JADE: Archie! I knew the\n"
	.string "disturbance had to be you!$"

FrigidFalls_6F_R2_Text_Archie_1:
	.string "ARCHIE: Grrr… those annoying kids\n"
	.string "again… We're prepared for you this time,\l"
	.string "just look at your situation!!$"

FrigidFalls_6F_R2_Text_Jade_2:
	.string "JADE: Oh No… we're surrounded!$"

FrigidFalls_6F_R2_Text_Jade_3:
	.string "JADE: What are you doing this time?\n"
	.string "Trying to steal another POKéMON!$"

FrigidFalls_6F_R2_Text_Archie_2:
	.string "ARCHIE: Oh no kid, no longer trying.\n"
	.string "I've already captured this freezing\l"
	.string "monster!\p"
	.string "With this we can finaly achieve\n"
	.string "our goal!$"

FrigidFalls_6F_R2_Text_Jade_4:
	.string "JADE: Wait you actually did it!?!$"

FrigidFalls_6F_R2_Text_Archie_3:
	.string "ARCHIE: With this power we will freeze\n"
	.string "the ocean, which will start a new\l"
	.string "ice age around the globe!\p"
	.string "This will make the sea gaurdian appear,\n"
	.string "which we'll use to flood the earth \l"
	.string "and start anew!$"

FrigidFalls_6F_R2_Text_Jade_5:
	.string "JADE: You'd hurt all those people,\n"
	.string "just so you can play god!?!$"

FrigidFalls_6F_R2_Text_Archie_4:
	.string "ARCHIE: Well you've got to break\n"
	.string "a few eggs to make an omelet.\l"
	.string "And the two of you will become stepping\l"
	.string "stones in our path.\p"
	.string "Now that you know our plan\l"
	.string "I can't just let you go kiddo's.\p"
	.string "I'm going to freeze you solid and then\l"
	.string "we will take the world!$"

FrigidFalls_6F_R2_Text_Jade_6:
	.string "JADE: Oh no!!!$"

FrigidFalls_6F_R2_Text_Jade_7:
	.string "JADE: We can't lose this {PLAYER}!\n"
	.string "You should take care of ARCHIE, since\l"
	.string "I've already lost to him…\p"
	.string "And you just beat me so, please win\n"
	.string "this for both of our sake. I'll take\l"
	.string "care of these 2. Now go gettem!$"

FrigidFalls_6F_R2_Text_Archie_5:
	.string "ARCHIE: HAHAHA I'll entertain this\n"
	.string "plan of yours to test my new POKéMON!\p"
	.string "Feel the power of the new world order!$"

FrigidFalls_6F_R2_Text_Archie_Defeat:
	.string "I lost… With this power…$"

FrigidFalls_6F_R2_Text_Archie_6:
	.string "ARCHIE: How did I lose to this kid!\n"
	.string "GRRRRRRRRRRR!\p"
	.string "I must admit you're pretty good kid.\n"
	.string "I'll let you two go this time,\l"
	.string "But next time I recommend staying\l"
	.string "Out of our way!\p"
	.string "Because there will be consequences!$"