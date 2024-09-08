.set LOCALID_JADE, 1
.set LOCALID_GRUNT_1, 2
.set LOCALID_GRUNT_2, 3

FrigidFalls_6F_MapScripts::
	.byte 0

FrigidFalls_6F_EventScript_Jade_Start_Movement1::
	applymovement OBJ_EVENT_ID_PLAYER, FrigidFalls_6F_Movement_WalkToRival1
	waitmovement 0
	goto FrigidFalls_6F_EventScript_Jade_Start
	end

FrigidFalls_6F_EventScript_Jade_Start_Movement2::
	applymovement OBJ_EVENT_ID_PLAYER, FrigidFalls_6F_Movement_WalkToRival2
	waitmovement 0
	goto FrigidFalls_6F_EventScript_Jade_Start
	end

FrigidFalls_6F_EventScript_Jade_Start_Movement3::
	applymovement OBJ_EVENT_ID_PLAYER, FrigidFalls_6F_Movement_WalkToRival3
	waitmovement 0
	goto FrigidFalls_6F_EventScript_Jade_Start
	end

FrigidFalls_6F_EventScript_Jade_Start_Movement4::
	applymovement OBJ_EVENT_ID_PLAYER, FrigidFalls_6F_Movement_WalkToRival4
	waitmovement 0
	goto FrigidFalls_6F_EventScript_Jade_Start
	end

FrigidFalls_6F_EventScript_Jade_Start_Movement5::
	applymovement OBJ_EVENT_ID_PLAYER, FrigidFalls_6F_Movement_WalkToRival5
	waitmovement 0
	goto FrigidFalls_6F_EventScript_Jade_Start
	end

FrigidFalls_6F_EventScript_Jade_Start::
	applymovement LOCALID_JADE, FrigidFalls_6F_Movement_Face_Down
	waitmovement 0
	applymovement LOCALID_JADE, Common_Movement_ExclamationMark
	waitmovement 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, FrigidFalls_6F_EventScript_Jade_Mus_M
	goto_if_eq VAR_RESULT, FEMALE, FrigidFalls_6F_EventScript_Jade_Mus_F
	end

FrigidFalls_6F_EventScript_Jade_Mus_M::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	msgbox FrigidFalls_6F_Text_Jade1, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	goto FrigidFalls_6F_EventScript_Jade_Mid
	end

FrigidFalls_6F_EventScript_Jade_Mus_F::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	msgbox FrigidFalls_6F_Text_Jade1, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	goto FrigidFalls_6F_EventScript_Jade_Mid
	end

FrigidFalls_6F_EventScript_Jade_Mid::
	msgbox FrigidFalls_6F_Text_Jade2, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, FrigidFalls_6F_EventScript_Jade_M
	goto_if_eq VAR_RESULT, FEMALE, FrigidFalls_6F_EventScript_Jade_F
	end

FrigidFalls_6F_EventScript_Jade_M::
	msgbox FrigidFalls_6F_Text_Jade3_M, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	goto FrigidFalls_6F_EventScript_Jade_BattleStart
	end

FrigidFalls_6F_EventScript_Jade_F::
	msgbox FrigidFalls_6F_Text_Jade3_F, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	goto FrigidFalls_6F_EventScript_Jade_BattleStart
	end

FrigidFalls_6F_EventScript_Jade_BattleStart::
	switch VAR_STARTER_MON
	case 0, FrigidFalls_6F_EventScript_Jade_BattleStart1
	case 1, FrigidFalls_6F_EventScript_Jade_BattleStart2
	case 2, FrigidFalls_6F_EventScript_Jade_BattleStart3
	end

FrigidFalls_6F_EventScript_Jade_BattleStart1::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, FrigidFalls_6F_Text_JadeDefeated
	goto FrigidFalls_6F_EventScript_Jade_End
	end

FrigidFalls_6F_EventScript_Jade_BattleStart2::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, FrigidFalls_6F_Text_JadeDefeated
	goto FrigidFalls_6F_EventScript_Jade_End
	end

FrigidFalls_6F_EventScript_Jade_BattleStart3::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, FrigidFalls_6F_Text_JadeDefeated
	goto FrigidFalls_6F_EventScript_Jade_End
	end

FrigidFalls_6F_EventScript_Jade_End::
	msgbox FrigidFalls_6F_Text_Jade4, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	msgbox FrigidFalls_6F_Text_Grunt_Late, MSGBOX_AUTOCLOSE
	waitmessage
	clearflag FLAG_ITEM_FRIGGIDFALLS_F6_HIDE_GRUNTS
	delay 5
	applymovement LOCALID_GRUNT_1, FrigidFalls_6F_Movement_Grunt_Run
	applymovement LOCALID_GRUNT_2, FrigidFalls_6F_Movement_Grunt_Run
	waitmovement 0
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	setflag FLAG_ITEM_FRIGGIDFALLS_F6_HIDE_GRUNTS
	msgbox FrigidFalls_6F_Text_Jade5, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	applymovement LOCALID_JADE, FrigidFalls_6F_Movement_Jade_Go
	waitmovement 0
	releaseall
	savebgm MUS_DUMMY
	fadedefaultbgm
	setvar VAR_FRIGID_FALLS_STATE, 1
	end

FrigidFalls_6F_EventScript_Prevent_Exit_South::
	msgbox FrigidFalls_6F_Text_No_leave, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, FrigidFalls_6F_Movement_Prevent_Exit_South
	waitmovement 0
	releaseall
	end

FrigidFalls_6F_EventScript_Prevent_Exit_West::
	msgbox FrigidFalls_6F_Text_No_leave, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, FrigidFalls_6F_Movement_Prevent_Exit_West
	waitmovement 0
	releaseall
	end

FrigidFalls_6F_EventScript_Prevent_Exit_North::
	msgbox FrigidFalls_6F_Text_Collapsed, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, FrigidFalls_6F_Movement_Prevent_Exit_North
	waitmovement 0
	releaseall
	end

FrigidFalls_6F_EventScript_Ready::
	applymovement LOCALID_JADE, FrigidFalls_6F_Movement_Face_Right
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, FrigidFalls_6F_Movement_Face_Left
	waitmovement 0
	msgbox FrigidFalls_6F_Text_Prepared, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FrigidFalls_6F_EventScript_Ready_Mid
	goto_if_eq VAR_RESULT, NO, FrigidFalls_6F_EventScript_Ready_End
	end

FrigidFalls_6F_EventScript_Ready_2::
	applymovement LOCALID_JADE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FrigidFalls_6F_Text_Prepared, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FrigidFalls_6F_EventScript_Ready_Mid_2
	goto_if_eq VAR_RESULT, NO, FrigidFalls_6F_EventScript_Ready_End_2
	waitmessage
	end

FrigidFalls_6F_EventScript_Ready_Mid::
	msgbox FrigidFalls_6F_Text_Prepared_2, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, FrigidFalls_6F_Movement_Prevent_Exit_South
	waitmovement 0
	warp MAP_FRIGID_FALLS_6F_R2, 7, 12 
	end

FrigidFalls_6F_EventScript_Ready_Mid_2::
	msgbox FrigidFalls_6F_Text_Prepared_2, MSGBOX_AUTOCLOSE
	waitmessage
	warp MAP_FRIGID_FALLS_6F_R2, 7, 12
	end

FrigidFalls_6F_EventScript_Ready_End::
	applymovement OBJ_EVENT_ID_PLAYER, FrigidFalls_6F_Movement_Prevent_Exit_North
	waitmovement 0
	releaseall
	end

FrigidFalls_6F_EventScript_Ready_End_2::
	releaseall
	end

FrigidFalls_6F_Movement_WalkToRival1:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end

FrigidFalls_6F_Movement_WalkToRival2:
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

FrigidFalls_6F_Movement_WalkToRival3:
	walk_up
	walk_up
	walk_up
	step_end

FrigidFalls_6F_Movement_WalkToRival4:
	walk_up
	walk_up
	walk_left
	walk_up
	step_end

FrigidFalls_6F_Movement_WalkToRival5:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

FrigidFalls_6F_Movement_Prevent_Exit_South:
	walk_up
	step_end

FrigidFalls_6F_Movement_Prevent_Exit_West:
	walk_right
	step_end

FrigidFalls_6F_Movement_Prevent_Exit_North:
	walk_down
	step_end

FrigidFalls_6F_Movement_Face_Down::
	face_down
	step_end

FrigidFalls_6F_Movement_Face_Left::
	face_left
	step_end

FrigidFalls_6F_Movement_Face_Right::
	face_right
	step_end

FrigidFalls_6F_Movement_Grunt_Run::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

FrigidFalls_6F_Movement_Jade_Go::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_down
	step_end

FrigidFalls_6F_Text_Jade1:
	.string "Oh, hey {PLAYER}!\n"
	.string "What are you doing here?!$"

FrigidFalls_6F_Text_Jade2:
	.string "Wait!? you actually got your\n"
	.string "first gym badge?!$"

FrigidFalls_6F_Text_Jade3_M:
	.string "Wow, you really are all I'd\n"
	.string "hope you'd be!\p"
	.string "I really can't wait to have\n"
	.string "that rematch! I really wanna\l"
	.string "go all out for once!\p"
	.string "You know what I'm sick of\n"
	.string "Waiting. Let's have a battle\l"
	.string "Now before you leave here.\p"
	.string "I hope you're ready!.\n"
	.string "Let's go!!!$"

FrigidFalls_6F_Text_Jade3_F:
	.string "There's no way!?\n"
	.string "She must have been holding back…\l"
	.string "I thought it was very difficult…\p"
	.string "grrr!\p"
	.string "I just remembered, you still owe me\n"
	.string "a rematch for our battle earlier!\p"
	.string "Let's have that match right now,\n"
	.string "because I'm sick of waiting!\p"
	.string "This time I won't be holding back\n"
	.string "and if you lose, you should just\l"
	.string "give up being a Trainer!\p"
	.string "Just go home and stop wasting\n"
	.string "your time on this!\p"
	.string "Well, For what it's worth\n"
	.string "I hope you're ready!\p"
	.string "Let's get this over with!$"

FrigidFalls_6F_Text_Jade4:
	.string "No way! I lost again…$"

FrigidFalls_6F_Text_Jade5:
	.string "Wait were those guys with team aqua?\p"
	.string "They must be up to something bad,\n"
	.string "we've got to go after them!\p"
	.string "Come on, follow me!$"

FrigidFalls_6F_Text_Grunt_Late:
	.string "Hurry up! the boss is gonna \n"
	.string "be angry if we're late!$"

FrigidFalls_6F_Text_No_leave:
	.string "I should probably follow after Jade… $"

FrigidFalls_6F_Text_JadeDefeated:
	.string "Okay… it seems I went to easy!\n"
	.string "You're just like what I'd hoped!$"

FrigidFalls_6F_Text_Collapsed:
	.string "The cave seems to be collapsed…\n"
	.string "I shouldn't go in here…$"

FrigidFalls_6F_Text_Prepared:
	.string "We're probably gonna have to battle\n"
	.string "them. Are you prepared to go in?$"

FrigidFalls_6F_Text_Prepared_2:
	.string "Okay, Let's go!$"