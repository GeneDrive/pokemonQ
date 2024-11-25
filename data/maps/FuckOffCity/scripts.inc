.set LOCALID_BRAWLY, 13
.set LOCALID_ATTENDENT, 14

FuckOffCity_MapScripts::
	.byte 0

FuckOffCity_EventScript_TalkToAttendent::
	lockall
	applymovement LOCALID_ATTENDENT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FuckOffCity_Text_Attendent, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

FuckOffCity_EventScript_BrawlyWalkUpLeft::
	lockall
	msgbox FuckOffCity_Text_Brawly1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRAWLY, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_BRAWLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BRAWLY, FuckOffCity_Movement_WalkUpLeft
	waitmovement 0
	goto FuckOffCity_EventScript_TalkToBrawly
	end

FuckOffCity_EventScript_BrawlyWalkUpMiddle::
	lockall
	msgbox FuckOffCity_Text_Brawly1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRAWLY, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_BRAWLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BRAWLY, FuckOffCity_Movement_WalkUpMiddle
	waitmovement 0
	goto FuckOffCity_EventScript_TalkToBrawly
	end

FuckOffCity_EventScript_BrawlyWalkUpRight::
	lockall
	msgbox FuckOffCity_Text_Brawly1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRAWLY, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_BRAWLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BRAWLY, FuckOffCity_Movement_WalkUpRight
	waitmovement 0
	goto FuckOffCity_EventScript_TalkToBrawly
	end

FuckOffCity_EventScript_TalkToBrawly::
	msgbox FuckOffCity_Text_Brawly2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuckOffCity_EventScript_TalkToBrawlyYes
	goto_if_eq VAR_RESULT, NO, FuckOffCity_EventScript_TalkToBrawlyNo
	waitmessage
	end

FuckOffCity_EventScript_TalkToBrawlyYes::
	msgbox FuckOffCity_Text_BrawlyYes1, MSGBOX_DEFAULT
	closemessage
	goto FuckOffCity_EventScript_TalkToBrawly2
	end

FuckOffCity_EventScript_TalkToBrawlyNo::
	msgbox FuckOffCity_Text_BrawlyNo1, MSGBOX_DEFAULT
	closemessage
	msgbox FuckOffCity_Text_Brawly3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuckOffCity_EventScript_TalkToBrawlyYes2
	goto_if_eq VAR_RESULT, NO, FuckOffCity_EventScript_TalkToBrawlyNo2
	waitmessage
	end

FuckOffCity_EventScript_TalkToBrawlyYes2::
	msgbox FuckOffCity_Text_BrawlyYes2, MSGBOX_DEFAULT
	closemessage
	goto FuckOffCity_EventScript_TalkToBrawly2
	end

FuckOffCity_EventScript_TalkToBrawlyNo2::
	msgbox FuckOffCity_Text_BrawlyNo2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuckOffCity_EventScript_TalkToBrawlyYes2
	goto_if_eq VAR_RESULT, NO, FuckOffCity_EventScript_TalkToBrawlyNo2
	waitmessage
	end

FuckOffCity_EventScript_TalkToBrawly2::
	msgbox FuckOffCity_Text_Brawly4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuckOffCity_EventScript_TalkToBrawlyYes3
	goto_if_eq VAR_RESULT, NO, FuckOffCity_EventScript_TalkToBrawlyNo3
	waitmessage
	end

FuckOffCity_EventScript_TalkToBrawlyYes3::
	msgbox FuckOffCity_Text_BrawlyYes2, MSGBOX_DEFAULT
	closemessage
	goto FuckOffCity_EventScript_TalkToBrawly3
	end

FuckOffCity_EventScript_TalkToBrawlyNo3::
	msgbox FuckOffCity_Text_BrawlyNo2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuckOffCity_EventScript_TalkToBrawlyYes3
	goto_if_eq VAR_RESULT, NO, FuckOffCity_EventScript_TalkToBrawlyNo3
	waitmessage
	end

FuckOffCity_EventScript_TalkToBrawly3::
	msgbox FuckOffCity_Text_Brawly5, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_PROTEIN, 2
	msgbox FuckOffCity_Text_Brawly6, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRAWLY, FuckOffCity_Movement_WalkUpOut
	waitmovement 0
	setflag FLAG_IZALA_CITY_HIDE_BRAWLY
	setflag FLAG_HIDE_UXIE
	setflag FLAG_HIDE_AZELF
	setflag FLAG_HIDE_MESPRIT
	setvar VAR_IZALA_CITY_STATE, 1
	releaseall
	end

FuckOffCity_Movement_WalkUpLeft:
	walk_left
	walk_down
	walk_down
	step_end

FuckOffCity_Movement_WalkUpMiddle:
	walk_down
	walk_down
	step_end

FuckOffCity_Movement_WalkUpRight:
	walk_right
	walk_down
	walk_down
	step_end

FuckOffCity_Movement_WalkUpOut:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FuckOffCity_Text_Attendent:
	.string "I'm sorry, but the gym is closed\n"
	.string "right now. Both Gymleaders are out\l"
	.string "at the moment.\p"
	.string "We're sorry for the inconvenience.$"

FuckOffCity_Text_Brawly1:
	.string "She just had to run off with that\n"
	.string "when we're this busy!\p"
	.string "Where did they go?$"

FuckOffCity_Text_Brawly2:
	.string "Hey, kid! Did you come here to\n"
	.string "take on the Gym Challenge by chance?$"

FuckOffCity_Text_BrawlyYes1:
	.string "Wow, good on you kid!\n"
	.string "But sadly your timing couldn't\l"
	.string "have been any worse...$"

FuckOffCity_Text_BrawlyNo1:
	.string "Oh, really?\n"
	.string "You seem like the type.$"

FuckOffCity_Text_Brawly3:
	.string "But since you're here, could you\n"
	.string "you help a guy out for a bit?$"

FuckOffCity_Text_BrawlyYes2:
	.string "GREAT, you're a huge help!$"

FuckOffCity_Text_BrawlyNo2:
	.string "Come on, I'll give you something\n"
	.string "for your troubles.$"

FuckOffCity_Text_Brawly4:
	.string "My sister ran off with some boy\n"
	.string "who was also taking on the\l"
	.string "Gym Challenge.\p"
	.string "Now we have keep the gym closed\n"
	.string "until she returns, and we've\l"
	.string "got a bunch of people waiting.\p"
	.string "Sooo... Could you help me\n"
	.string "Search for her?$"

FuckOffCity_Text_Brawly5:
	.string "Here, have this.$"

FuckOffCity_Text_Brawly6:
	.string "This search will be quite the \n"
	.string "workout. So you should drink it\l"
	.string "before or after to recover strength.\p"
	.string "I'll go look around ROUTE 106,\n"
	.string "but you should check ROUTE 105\l"
	.string "to the east.\p"
	.string "I have a suspision that's where\n"
	.string "They'll be, but you can't be to sure.\p"
	.string "I'll follow behind you after I'm done\n"
	.string "Looking, So I'll see you in a bit!\l"
	.string "LETS GO, time to get a good sweat going!$"