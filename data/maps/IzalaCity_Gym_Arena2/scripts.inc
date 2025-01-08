.set LOCALID_BRAWLY, 1
.set LOCALID_ALICA, 2

IzalaCity_Gym_Arena2_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IzalaCity_Gym_Arena2_EventScript_OnFrame
	.byte 0

IzalaCity_Gym_Arena2_EventScript_OnFrame:
	map_script_2 VAR_TEMP_0, 0, IzalaCity_Gym_Arena2_EventScript_Battle_Event_Start
	.2byte 0

IzalaCity_Gym_Arena2_EventScript_Battle_Event_Start::
	applymovement OBJ_EVENT_ID_PLAYER, IzalaCity_Gym_Arena2_Movement_PlayerWalkUp
	waitmovement 0
	goto IzalaCity_Gym_Arena2_EventScript_Battle_Event
	end

IzalaCity_Gym_Arena2_EventScript_Battle_Event::
	msgbox IzalaCity_Gym_Arena2_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	msgbox IzalaCity_Gym_Arena2_Text_2, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	applymovement LOCALID_BRAWLY, Common_Movement_ExclamationMark
	applymovement LOCALID_BRAWLY, IzalaCity_Gym_Arena2_Movement_Face_Right
	applymovement LOCALID_ALICA, IzalaCity_Gym_Arena2_Movement_AlicaWalkUp
	waitmovement 0
	applymovement LOCALID_ALICA, IzalaCity_Gym_Arena2_Movement_Face_Left
	waitmovement 0
	applymovement LOCALID_BRAWLY, IzalaCity_Gym_Arena2_Movement_Face_Left
	msgbox IzalaCity_Gym_Arena2_Text_3, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	applymovement LOCALID_ALICA, IzalaCity_Gym_Arena2_Movement_Face_Right
	waitmovement 0
	msgbox IzalaCity_Gym_Arena2_Text_4, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	applymovement LOCALID_ALICA, IzalaCity_Gym_Arena2_Movement_Face_Left
	waitmovement 0
	msgbox IzalaCity_Gym_Arena2_Text_5, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	applymovement LOCALID_BRAWLY, IzalaCity_Gym_Arena2_Movement_BrawlyStepBack
	waitmovement 0
	applymovement LOCALID_BRAWLY, IzalaCity_Gym_Arena2_Movement_Face_Left
	waitmovement 0
	applymovement LOCALID_ALICA, IzalaCity_Gym_Arena2_Movement_Face_Right
	waitmovement 0
	msgbox IzalaCity_Gym_Arena2_Text_6, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	applymovement LOCALID_ALICA, IzalaCity_Gym_Arena2_Movement_Face_Left
	waitmovement 0
	msgbox IzalaCity_Gym_Arena2_Text_7, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	trainerbattle_no_intro TRAINER_ROXANNE_1, IzalaCity_Gym_Arena2_Text_Alica_Defeated
	msgbox IzalaCity_Gym_Arena2_Text_8, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	applymovement LOCALID_ALICA, IzalaCity_Gym_Arena2_Movement_AlicaStepBack
	waitmovement 0
	applymovement LOCALID_ALICA, IzalaCity_Gym_Arena2_Movement_Face_Left
	applymovement LOCALID_BRAWLY, IzalaCity_Gym_Arena2_Movement_BrawlyStepForward
	waitmovement 0
	msgbox IzalaCity_Gym_Arena2_Text_9, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	msgbox IzalaCity_Gym_Arena2_Text_10, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	msgbox IzalaCity_Gym_Arena2_Text_11, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	msgbox IzalaCity_Gym_Arena2_Text_BrawlyIntro, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	trainerbattle_no_intro TRAINER_ROXANNE_2, IzalaCity_Gym_Arena2_Text_BrawlyDefeat
	end

IzalaCity_Gym_Arena2_Movement_PlayerWalkUp:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

IzalaCity_Gym_Arena2_Movement_AlicaWalkUp:
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

IzalaCity_Gym_Arena2_Movement_AlicaStepBack:
	walk_up
	walk_right
	walk_right
	step_end

IzalaCity_Gym_Arena2_Movement_BrawlyStepForward:
	walk_left
	step_end

IzalaCity_Gym_Arena2_Text_1:
	.string "BRAWLY: Hey {PLAYER}!\n"
	.string "Good to see you again!\p"
	.string "Thanks for helping with my sister\n"
	.string "earlier! We were worried we couldn't\l"
	.string "open the gym today because of her.\p"
	.string "She helps a bit around the gym,\n"
	.string "so we can't open without her.\p"
	.string "I also wanted to congratulate you\n"
	.string "on getting through our trainers!\p"
	.string "This gym is known as a roadblock\n"
	.string "for many trainers.\p"
	.string "Most of them give up on being a trainer\n"
	.string "after losing to the 2nd or 3rd trainer.\p"
	.string "But I'm happy to see you made it\n"
	.string "all the way to me!\p"
	.string "So let's get started!$"

IzalaCity_Gym_Arena2_Text_2:
	.string "???: STOP RIGHT THERE!!!$"

IzalaCity_Gym_Arena2_Text_3:
	.string "ALICA: Not so fast!\n"
	.string "I still have a bone to pick with you\l"
	.string "for interrupting my time with Wally!$"

IzalaCity_Gym_Arena2_Text_4:
	.string "ALICA: Sorry bro, but I'm going\n"
	.string "destroy {PLAYER} before you can!$"

IzalaCity_Gym_Arena2_Text_5:
	.string "BRAWLY: OK OK...\n"
	.string "Sorry {PLAYER}, but you'll have\l"
	.string "deal with my sister first.\p"
	.string "She won't back down from a fight once\n"
	.string "she's got her sights set on it.\p"
	.string "Hihihi... she got that from me.$"

IzalaCity_Gym_Arena2_Text_6:
	.string "ALICA: Shut up!\n"
	.string "Don't be so embarassing!$"

IzalaCity_Gym_Arena2_Text_7:
	.string "ALICA: Let's go {PLAYER}!\n"
	.string "Time to take responsibility and lose!$"

IzalaCity_Gym_Arena2_Text_8:
	.string "ALICA: Alright bro, I softened\n"
	.string "{PLAYER} up for you!\p"
	.string "Now you can send them packing!$"

IzalaCity_Gym_Arena2_Text_9:
	.string "BRAWLY: Um doesn't this seem a bit\n"
	.string "unfair to you? I mean their pokemon\l"
	.string "are already tired from fighting you.$"

IzalaCity_Gym_Arena2_Text_10:
	.string "ALICA: Isn't that the whole theme of\n"
	.string "of your gym?\p"
	.string "Having multiple battles in a row\n"
	.string "to test the endurance of the trainer.\p"
	.string "I'm just helping you out by\n"
	.string "updating your gym to the new standard.$"

IzalaCity_Gym_Arena2_Text_11:
	.string "BRAWLY: ...\p"
	.string "It feels like I'm being used here...\n"
	.string "But I actually like the idea.\p"
	.string "So you better step up from now on\n"
	.string "sis and help out with the challenge.\p"
	.string "...\n"
	.string "...\p"
	.string "Alright... let's get into\n"
	.string "Gymleader mode...$"

IzalaCity_Gym_Arena2_Text_Alica_Defeated:
	.string "Just like I thought! But now\n"
	.string "but my brother will take you down!$"

IzalaCity_Gym_Arena2_Text_BrawlyIntro:
	.string "I'm BRAWLY!\n"
	.string "DEWFORD's GYM LEADER!\p"
	.string "I've been churned in the rough waves\n"
	.string "of these parts, and I've grown tough\l"
	.string "in the pitch-black cave!\p"
	.string "So you wanted to challenge me?\n"
	.string "Let me see what you're made of!$"

IzalaCity_Gym_Arena2_Text_BrawlyDefeat:
	.string "Whoah, wow! You made a much bigger\n"
	.string "splash than I expected!\p"
	.string "You swamped me!\p"
	.string "Okay, you've got me.\n"
	.string "Take this GYM BADGE!$"

IzalaCity_Gym_Arena2_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} received the KNUCKLE BADGE\n"
	.string "from BRAWLY.$"

IzalaCity_Gym_Arena2_Text_KnuckleBadgeInfoTakeThis:
	.string "The KNUCKLE BADGE makes all POKéMON\n"
	.string "up to Level 30, even those you get in\l"
	.string "trades, obey without question.\p"
	.string "If you'd like, use this TECHNICAL\n"
	.string "MACHINE, too.$"

IzalaCity_Gym_Arena2_Text_ExplainBulkUp:
	.string "That TM08 contains BULK UP.\p"
	.string "It's a move that raises both ATTACK\n"
	.string "and DEFENSE stats.\p"
	.string "… … … … … …$"

IzalaCity_Gym_Arena2_Text_RegisteredBrawly:
	.string "Registered GYM LEADER BRAWLY\n"
	.string "in the POKéNAV.$"

IzalaCity_Gym_Arena2_Text_BrawlyPostBattle:
	.string "I can see your talent becoming a giant\n"
	.string "wave to cause a storm of astonishment\l"
	.string "among TRAINERS one day!$"