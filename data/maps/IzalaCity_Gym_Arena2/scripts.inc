.set LOCALID_BRAWLY, 1
.set LOCALID_ALICE, 2

IzalaCity_Gym_Arena2_MapScripts::
	.byte 0

IzalaCity_Gym_Arena2_EventScript_Battle_Event_Start::
	applymovement OBJ_EVENT_ID_PLAYER, IzalaCity_Gym_Arena2_Movement_PlayerWalkUp
	waitmovement 0
	goto IzalaCity_Gym_Arena2_EventScript_Battle_Event
	end

IzalaCity_Gym_Arena2_EventScript_Battle_Event::

IzalaCity_Gym_Arena2_Movement_PlayerWalkUp:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

IzalaCity_Gym_Arena2_Movement_AliceWalkUp:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_down
	step_end

IzalaCity_Gym_Arena2_Movement_Face_Left:
	face_left
	step_end

IzalaCity_Gym_Arena2_Movement_Face_Right:
	face_right
	step_end

IzalaCity_Gym_Arena2_Movement_BrawlyStepBack:
	walk_right
	step_end

IzalaCity_Gym_Arena1_Text_1:
	.string "BRAWLY: needs dialogue\n"
	.string "needs dialogue$"

IzalaCity_Gym_Arena1_Text_2:
	.string "???: WAIT!!!$"

IzalaCity_Gym_Arena1_Text_3:
	.string "ALICE: not so fast, I still\n"
	.string "have a bone to pick with you for\l"
	.string "interupting my time with Wally!$"

IzalaCity_Gym_Arena1_Text_4:
	.string "ALICE: sorry bro, but I'm going\n"
	.string "destroy {PLAYER} before you can!$"

IzalaCity_Gym_Arena1_Text_5:
	.string "BRAWLY: OK OK...\n"
	.string "Sorry {PLAYER}, but you'll have\l"
	.string "deal with my sister first.\p"
	.string "She won't back down from a fight\n"
	.string "ones she get's her sights set on\l"
	.string "someone\p"
	.string "hihihi... she got that from me$"

IzalaCity_Gym_Arena1_Text_6:
	.string "ALICE: Shut up!\n"
	.string "Don't be so embarassing!$"

IzalaCity_Gym_Arena1_Text_7:
	.string "ALICE: Let's go {PLAYER}!\n"
	.string "Time to take responsibility\l"
	.string "and lose!$"