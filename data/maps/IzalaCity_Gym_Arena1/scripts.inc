.set LOCALID_TRAINER_1, 1
.set LOCALID_TRAINER_2, 2
.set LOCALID_TRAINER_3, 3

IzalaCity_Gym_Arena1_MapScripts::
	.byte 0

IzalaCity_Gym_Arena1_EventScript_Battle_Event_Start::
	applymovement OBJ_EVENT_ID_PLAYER, IzalaCity_Gym_Arena1_Movement_PlayerWalkUp
	waitmovement 0
	goto IzalaCity_Gym_Arena1_EventScript_Battle_Event
	end

IzalaCity_Gym_Arena1_EventScript_Battle_Event::
	msgbox IzalaCity_Gym_Arena1_Text_Trainer1, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	trainerbattle_no_intro TRAINER_JOSH, IzalaCity_Gym_Arena1_Text_Trainer1After
	applymovement LOCALID_TRAINER_1, IzalaCity_Gym_Arena1_Movement_PlayerWalkUp
	waitmovement 0
	applymovement LOCALID_TRAINER_2, IzalaCity_Gym_Arena1_Movement_TrainerWalkUp
	waitmovement 0
	msgbox IzalaCity_Gym_Arena1_Text_Trainer2, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	trainerbattle_no_intro TRAINER_PAULA, IzalaCity_Gym_Arena1_Text_Trainer2After
	applymovement LOCALID_TRAINER_2, IzalaCity_Gym_Arena1_Movement_PlayerWalkUp
	waitmovement 0
	applymovement LOCALID_TRAINER_3, IzalaCity_Gym_Arena1_Movement_TrainerWalkUp
	waitmovement 0
	msgbox IzalaCity_Gym_Arena1_Text_Trainer3, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	trainerbattle_no_intro TRAINER_CORA, IzalaCity_Gym_Arena1_Text_Trainer3After
	msgbox IzalaCity_Gym_Arena1_Text_Trainer3After2, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	setvar VAR_GYM_2_STATE, 1
	warp MAP_IZALA_CITY_GYM_WAITING_ROOM, 1, 12
	end

IzalaCity_Gym_Arena1_Movement_PlayerWalkUp:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

IzalaCity_Gym_Arena1_Movement_TrainerWalkUp:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

IzalaCity_Gym_Arena1_Text_Trainer1:
	.string "needs dialogue\n"
	.string "needs dialogue$"

IzalaCity_Gym_Arena1_Text_Trainer1After:
	.string "needs dialogue\n"
	.string "needs dialogue$"

IzalaCity_Gym_Arena1_Text_Trainer2:
	.string "needs dialogue\n"
	.string "needs dialogue$"

IzalaCity_Gym_Arena1_Text_Trainer2After:
	.string "needs dialogue\n"
	.string "needs dialogue$"

IzalaCity_Gym_Arena1_Text_Trainer3:
	.string "needs dialogue\n"
	.string "needs dialogue$"

IzalaCity_Gym_Arena1_Text_Trainer3After:
	.string "needs dialogue\n"
	.string "needs dialogue$"

IzalaCity_Gym_Arena1_Text_Trainer3After2:
	.string "Good job, Trainer!\n"
	.string "You've defeated the gauntlet!\p"
	.string "That means you're ready to\n"
	.string "challange the Gym Leader!\p"
	.string "Head back to the waiting room and\n"
	.string "rest up for a bit before you take\l"
	.string "on the Gym Leader!$"