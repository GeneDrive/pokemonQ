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
	msgbox FrigidFalls_6F_R2_Text_Archie_6, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement LOCALID_JADE, FrigidFalls_6F_R2_Movement_FaceUp
	waitmovement 0
	msgbox FrigidFalls_6F_R2_Text_Jade_8, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox FrigidFalls_6F_R2_Text_Jade_9, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox FrigidFalls_6F_R2_Text_Archie_7, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox FrigidFalls_6F_R2_Text_Archie_8, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox FrigidFalls_6F_R2_Text_Archie_9, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox FrigidFalls_6F_R2_Text_Archie_10, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox FrigidFalls_6F_R2_Text_Boom, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement LOCALID_JADE, FrigidFalls_6F_R2_Movement_FaceDown
	waitmovement 0
	msgbox FrigidFalls_6F_R2_Text_Jade_10, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement LOCALID_JADE, FrigidFalls_6F_R2_Movement_FaceUp
	waitmovement 0
	msgbox FrigidFalls_6F_R2_Text_Archie_11, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox FrigidFalls_6F_R2_Text_Archie_12, MSGBOX_DEFAULT
	closemessage
	delay 5
	fadescreen FADE_TO_BLACK
	delay 20
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 20
	applymovement LOCALID_JADE, FrigidFalls_6F_R2_Movement_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, FrigidFalls_6F_R2_Movement_FaceLeft
	waitmovement 0
	msgbox FrigidFalls_6F_R2_Text_Jade_11, MSGBOX_DEFAULT
	closemessage
	delay 5
	setvar VAR_FRIGID_FALLS_STATE, 2
	warp MAP_FRIGID_FALLS_6F, 7, 12
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
	.string "I'll let you two go this time,\p"
	.string "But next time I recommend staying\n"
	.string "Out of our way!\p"
	.string "Because there will be consequences!$"

FrigidFalls_6F_R2_Text_Jade_8:
	.string "JADE: Good job {PLAYER}!\n"
	.string "I just finished here to!$"

FrigidFalls_6F_R2_Text_Jade_9:
	.string "JADE: What did you just say?\n"
	.string "Next time? There won't be a next time!\p"
	.string "I already called the authorities before\n"
	.string "we went in here, so we won't let\p"
	.string "you get away like last time!$"

FrigidFalls_6F_R2_Text_Archie_7:
	.string "ARCHIE: HAHAHA\n"
	.string "I don't think so kid!\p"
	.string "Unlike the last time, we made preperations\n"
	.string "To cover our tracks!\p"
	.string "So I don't think you'll have a choice!$"

FrigidFalls_6F_R2_Text_Archie_8:
	.string "GRUNT: But boss, what about the POKéMON!?$"

FrigidFalls_6F_R2_Text_Archie_9:
	.string "ARCHIE: Leave it! \n"
	.string "There are other fish in the sea!\p"
	.string "We had another lead anyway, so\n"
	.string "we'll just follow that one!\p"
	.string "If this POKéMON can be defeated by a\n"
	.string "child, It won't be useful anyway!\p"
	.string "So I don't think you'll have a choice!$"

FrigidFalls_6F_R2_Text_Archie_10:
	.string "ARCHIE: You heared me!\n"
	.string "We're LEAVING!!!\p"
	.string "'CLICK'$"

FrigidFalls_6F_R2_Text_Boom:
	.string "'BOOM!!!'$"

FrigidFalls_6F_R2_Text_Jade_10:
	.string "JADE: Wh- what was that!?$"

FrigidFalls_6F_R2_Text_Archie_11:
	.string "ARCHIE: You better leave kids, or else\n"
	.string "this place will become your tomb!$"

FrigidFalls_6F_R2_Text_Archie_12:
	.string "ARCHIE: HAHAHA!!! \n"
	.string "Now you'll understand what you're\l"
	.string "dealing with!\p"
	.string "This is just a fraction of what\n"
	.string "team aqua is capable of!\l"
	.string "So you'd better stay out of our way!\p"
	.string "HAHAHA!!!$"

FrigidFalls_6F_R2_Text_Jade_11:
	.string "JADE: Come on we've gotta get out of here!\n"
	.string "I'll help the Pokémon get out, just \l"
	.string "run quickly! I'll be right behind you!$"
