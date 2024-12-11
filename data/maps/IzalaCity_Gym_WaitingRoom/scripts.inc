.set LOCALID_ATT_LEFT, 1
.set LOCALID_ATT_RIGHT, 2
.set LOCALID_GIRL, 3
.set LOCALID_BOY, 4

IzalaCity_Gym_WaitingRoom_MapScripts::
	.byte 0

IzalaCity_Gym_WaitingRoom_EventScript_Attendant1::
	applymovement LOCALID_ATT_LEFT, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_GYM_2_STATE, 1, IzalaCity_Gym_WaitingRoom_EventScript_Attendant1_Declined
	goto_if_eq VAR_GYM_2_STATE, 0, IzalaCity_Gym_WaitingRoom_EventScript_Attendant1_Allowed
	end

IzalaCity_Gym_WaitingRoom_EventScript_Attendant1_Allowed::
	applymovement LOCALID_ATT_LEFT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox IzalaCity_Gym_WaitingRoom_Text_Attendant1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, IzalaCity_Gym_WaitingRoom_EventScript_Attendant1_Yes
	goto_if_eq VAR_RESULT, NO, IzalaCity_Gym_WaitingRoom_EventScript_Attendant1_No
	end

IzalaCity_Gym_WaitingRoom_EventScript_Attendant1_Declined::
	msgbox IzalaCity_Gym_WaitingRoom_Text_Attendant1_Declined, MSGBOX_AUTOCLOSE
	waitmessage
	releaseall
	end

IzalaCity_Gym_WaitingRoom_EventScript_Attendant1_Yes::
	msgbox IzalaCity_Gym_WaitingRoom_Text_Attendant1_Go, MSGBOX_AUTOCLOSE
	waitmessage
	warp MAP_IZALA_CITY_GYM_ARENA1, 0, 6
	end

IzalaCity_Gym_WaitingRoom_EventScript_Attendant1_No::
	msgbox IzalaCity_Gym_WaitingRoom_Text_Attendant1_No, MSGBOX_AUTOCLOSE
	waitmessage
	releaseall
	end

IzalaCity_Gym_WaitingRoom_EventScript_Attendant2::
	applymovement LOCALID_ATT_LEFT, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_GYM_2_STATE, 0, IzalaCity_Gym_WaitingRoom_EventScript_Attendant2_Declined
	goto_if_eq VAR_GYM_2_STATE, 1, IzalaCity_Gym_WaitingRoom_EventScript_Attendant2_Allowed
	end

IzalaCity_Gym_WaitingRoom_EventScript_Attendant2_Allowed::
	applymovement LOCALID_ATT_LEFT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox IzalaCity_Gym_WaitingRoom_Text_Attendant2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, IzalaCity_Gym_WaitingRoom_EventScript_Attendant2_Yes
	goto_if_eq VAR_RESULT, NO, IzalaCity_Gym_WaitingRoom_EventScript_Attendant2_No
	end

IzalaCity_Gym_WaitingRoom_EventScript_Attendant2_Declined::
	msgbox IzalaCity_Gym_WaitingRoom_Text_Attendant2_Declined, MSGBOX_AUTOCLOSE
	waitmessage
	releaseall
	end

IzalaCity_Gym_WaitingRoom_EventScript_Attendant2_Yes::
	msgbox IzalaCity_Gym_WaitingRoom_Text_Attendant2_Go, MSGBOX_AUTOCLOSE
	waitmessage
	warp MAP_IZALA_CITY_GYM_ARENA2, 0, 6
	end

IzalaCity_Gym_WaitingRoom_EventScript_Attendant2_No::
	msgbox IzalaCity_Gym_WaitingRoom_Text_Attendant2_No, MSGBOX_AUTOCLOSE
	waitmessage
	releaseall
	end

IzalaCity_Gym_WaitingRoom_EventScript_Trainer1::
	applymovement LOCALID_GIRL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox IzalaCity_Gym_WaitingRoom_Text_Trainer1, MSGBOX_AUTOCLOSE
	waitmessage
	end

IzalaCity_Gym_WaitingRoom_EventScript_Trainer2::
	applymovement LOCALID_BOY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox IzalaCity_Gym_WaitingRoom_Text_Trainer2, MSGBOX_AUTOCLOSE
	waitmessage
	end

IzalaCity_Gym_WaitingRoom_Text_Attendant1:
	.string "Hey there young Trainer!\n"
	.string "It's your turn to take on our gym\l"
	.string "challenge's trainers!\p"
	.string "Are you fully prepared?$"

IzalaCity_Gym_WaitingRoom_Text_Attendant1_Go:
	.string "Alright then, Good luck!$"

IzalaCity_Gym_WaitingRoom_Text_Attendant1_Declined:
	.string "Hey there young Trainer!\n"
	.string "You already defeated our our trainers.\p"
	.string "Please talk to the other attendant\n"
	.string "To take on the Gym Leader!$"

IzalaCity_Gym_WaitingRoom_Text_Attendant1_No:
	.string "Alright then, Take your time!$"

IzalaCity_Gym_WaitingRoom_Text_Attendant2:
	.string "Hey there young Trainer!\n"
	.string "It's your turn to take on \l"
	.string "the GYM LEADER!\p"
	.string "Are you fully prepared?$"

IzalaCity_Gym_WaitingRoom_Text_Attendant2_Go:
	.string "Alright then, Good luck!$"

IzalaCity_Gym_WaitingRoom_Text_Attendant2_Declined:
	.string "Hey there young Trainer!\n"
	.string "You haven't defeated our trainers yet.\p"
	.string "Please talk to the other attendant\n"
	.string "To take them on!$"

IzalaCity_Gym_WaitingRoom_Text_Attendant2_No:
	.string "Alright then, Take your time!$"

IzalaCity_Gym_WaitingRoom_Text_Trainer1:
	.string "Man, I'm still waiting for my turn…\n"
	.string "Lucky you being allowed to go first\l"
	.string "I wish it was me!$"

IzalaCity_Gym_WaitingRoom_Text_Trainer2:
	.string "I'm so nervous! I don't know if I'm\n"
	.string "ready for this!\p"
	.string "maybe I should just go home…$"