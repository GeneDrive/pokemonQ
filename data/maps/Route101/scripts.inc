.set LOCALID_BIRCH, 2
.set LOCALID_ZIGZAGOON, 4
.set LOCALID_BIRCH_CAVE, 7
.set LOCALID_JADE, 12
.set LOCALID_OLD_MAN, 13
.set LOCALID_OLD_MAN2, 14

Route101_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route101_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnResume:
	setstepcallback STEP_CB_ASH
	end

Route101_OnTransition:
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

Route101_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE101_STATE, 1
	end

Route101_EventScript_Destroy_Old_Man::
	removeobject LOCALID_OLD_MAN
	return

Route101_EventScript_StartBirchRescue::
	lockall
	playbgm MUS_HELP, TRUE
	setflag FLAG_ITEM_ROUTE_101_HIDE_RIVAL
	setflag FLAG_ROUTE101_HIDE_OLD_MAN
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
	closemessage
	setobjectxy LOCALID_BIRCH, 0, 20
	setobjectxy LOCALID_ZIGZAGOON, 0, 21
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_EnterScene
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunAway1
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
	waitmovement 0
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunInCircles
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
	applymovement LOCALID_BIRCH, Route101_Movement_BirchFaceZigzagoon
	waitmovement 0
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE101_STATE, 2
	releaseall
	end

Route101_EventScript_PreventExitSouth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitWest::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitNorth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitNorth
	waitmovement 0
	releaseall
	end

Route101_Movement_PreventExitSouth:
	walk_up
	step_end

Route101_Movement_PreventExitWest:
	walk_right
	step_end

Route101_Movement_PreventExitNorth:
	walk_down
	step_end

Route101_Movement_Face_Down:
	face_down
	step_end

Route101_Movement_PreventExitEast:
	walk_left
	step_end

Route101_Movement_ZigzagoonChaseInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_ZigzagoonChase1:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_ZigzagoonFaceBirch:
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route101_Movement_EnterScene:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_faster_left
	step_end

Route101_Movement_BirchRunInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_BirchRunAway1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_BirchFaceZigzagoon:
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Route101_Movement_Unused1:
	walk_up
	walk_up
	step_end

Route101_Movement_Unused2:
	walk_up
	walk_left
	walk_up
	step_end

Route101_EventScript_Youngster::
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route101_EventScript_Boy::
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_BirchsBag::
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ZIGZAGOON
	setobjectxy OBJ_EVENT_ID_PLAYER, 6, 18
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	special ChooseStarter
	waitstate
	applymovement LOCALID_BIRCH, Route101_Movement_BirchApproachPlayer
	waitmovement 0
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
	special HealPlayerParty
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
	waitstate
	release
	end

Route101_EventScript_HideMayInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Movement_BirchApproachPlayer:
	walk_right
	step_end

Route101_Movement_JadeApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

Route101_Movement_JadeLeavePlayer:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route101_EventScript_Help_South::
	msgbox Route101_Text_ComeOverEast MSGBOX_NPC
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route101_EventScript_Help_South2::
	msgbox Route101_Text_ComeOverEast MSGBOX_NPC
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end

Route101_EventScript_See_May_First::
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103, Route101_EventScript_City_Go
	applymovement LOCALID_BIRCH_CAVE, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_BIRCH_CAVE, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route101_Text_GoSeeMayFirst MSGBOX_NPC
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitEast
	waitmovement 0
	releaseall
	end

Route101_EventScript_City_Go::
	applymovement LOCALID_BIRCH_CAVE, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_BIRCH_CAVE, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route101_Text_GoCity MSGBOX_NPC
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitEast
	waitmovement 0
	releaseall
	end

Route101_EventScript_Help_Pokemon::
	applymovement LOCALID_BIRCH_CAVE, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_ROUTE103_TALK_EVENT_DONE, 2
	msgbox Route101_Text_HelpProtector MSGBOX_NPC
	closemessage
	releaseall
	end

Route101_EventScript_Go::
	applymovement LOCALID_BIRCH_CAVE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route101_Text_GO MSGBOX_NPC
	closemessage
	releaseall
	end

Route101_EventScript_Jade_After_Cave_Start::
	msgbox Route101_Text_Jade_After_Cave1, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route101_EventScript_Jade_After_Cave_Mus_M
	goto_if_eq VAR_RESULT, FEMALE, Route101_EventScript_Jade_After_Cave_Mus_F
	end

Route101_EventScript_Jade_After_Cave_Mus_M::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	goto Route101_EventScript_Jade_After_Cave_Mid
	end

Route101_EventScript_Jade_After_Cave_Mus_F::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	goto Route101_EventScript_Jade_After_Cave_Mid
	end

Route101_EventScript_Jade_After_Cave_Mid::
	applymovement LOCALID_JADE, Route101_Movement_JadeApproachPlayer
	waitmovement 0
	msgbox Route101_Text_Jade_After_Cave2, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route101_EventScript_Jade_After_Cave_M
	goto_if_eq VAR_RESULT, FEMALE, Route101_EventScript_Jade_After_Cave_F
	end

Route101_EventScript_Jade_After_Cave_M::
	msgbox Route101_Text_Jade_After_Cave3_M, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	goto Route101_EventScript_Jade_After_Cave_End
	end

Route101_EventScript_Jade_After_Cave_F::
	msgbox Route101_Text_Jade_After_Cave3_F, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	goto Route101_EventScript_Jade_After_Cave_End
	end

Route101_EventScript_Jade_After_Cave_End::
	msgbox Route101_Text_Jade_After_Cave4, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	msgbox Route101_Text_Jade_After_Cave5, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	releaseall
	applymovement LOCALID_JADE, Route101_Movement_JadeLeavePlayer
	waitmovement 0
	removeobject LOCALID_JADE
	setflag FLAG_ITEM_ROUTE_101_HIDE_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	setvar VAR_ROUTE101_STATE, 7
	end

Route101_EventScript_Old_Man1::
	applymovement LOCALID_OLD_MAN, Common_Movement_FacePlayer
	msgbox Route101_Text_Old_Man_Stop, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	goto_if_unset FLAG_BADGE01_GET, Route101_EventScript_Old_Man2
	goto_if_set FLAG_BADGE01_GET, Route101_EventScript_Old_Man3
	end

Route101_EventScript_Old_Man2::
	msgbox Route101_Text_Old_Man_Stop2, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	end

Route101_EventScript_Old_Man3::
	msgbox Route101_Text_Old_Man_Go, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	applymovement LOCALID_OLD_MAN, Route101_Movement_BirchApproachPlayer
	waitmovement 0
	applymovement LOCALID_OLD_MAN, Route101_Movement_Face_Down
	waitmovement 0
	clearflag FLAG_ROUTE101_HIDE_OLD_MAN
	setflag FLAG_ROUTE101_HIDE_OLD_MAN_2
	releaseall
	end

Route101_EventScript_Old_Man4::
	msgbox Route101_Text_Old_Man_Sleep, MSGBOX_AUTOCLOSE
	waitmessage
	delay 5
	releaseall
	end

Route101_Text_HelpMe:
	.string "H-help me!$"

Route101_Text_PleaseHelp:
	.string "Hello! You over there!\n"
	.string "Please! Help!\p"
	.string "In my BAG!\n"
	.string "There's a POKé BALL!$"

Route101_Text_DontLeaveMe:
	.string "Wh-Where are you going?!\n"
	.string "Don't leave me like this!$"

Route101_Text_YouSavedMe:
	.string "PROF. BIRCH: Whew…\p"
	.string "I was in the tall grass studying wild\n"
	.string "POKéMON when I was jumped.\p"
	.string "You saved me.\n"
	.string "Thanks a lot!\p"
	.string "Oh?\p"
	.string "Hi, you're {PLAYER}{KUN}!\p"
	.string "This is not the place to chat, so come\n"
	.string "by my POKéMON LAB later, okay?$"

Route101_Text_TakeTiredPokemonToPokeCenter:
	.string "If POKéMON get tired, take them to\n"
	.string "a POKéMON CENTER.\p"
	.string "There's a POKéMON CENTER in KEVANO\n"
	.string "TOWN right close by.$"

Route101_Text_WildPokemonInTallGrass:
	.string "Wild POKéMON will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch POKéMON, you have\n"
	.string "to go into the tall grass and search.$"

Route101_Text_RouteSign:
	.string "ROUTE 101\n"
	.string "{UP_ARROW} KEVANO TOWN$"

Route101_Text_GoSeeMayFirst:
	.string "You should go see JADE first,\n"
	.string "she likes to explore ROUTE 143.\l"
	.string "we'll talk after!$"

Route101_Text_GoCity:
	.string "I the hear petalburg city GYM LEADER\n"
	.string "is helping up and coming trainers,\l"
	.string "which may be good experience for you.\p"
	.string "You should be able to reach the city \n"
	.string "by going through ROUTE 142.\p"
	.string "You should go see her, we'll talk after!$"

Route101_Text_ComeOverEast:
	.string "Birch: Hey, {PLAYER}{KUN}!\n"
	.string "Come help me to the east.$"

Route101_Text_HelpProtector:
	.string "Hey, {PLAYER}{KUN}!\p"
	.string "Did you know that EVERY route,\n"
	.string "city or location has a special\l"
	.string "habitat where that area's \l"
	.string "Gaurdian POKéMON resides.\p"
	.string "These are special POKéMON,\n"
	.string "that are not normaly found\l"
	.string "in the area.\p"
	.string "So try exploring in order,\n"
	.string "to find these special POKéMON.\p"
	.string "Some weird group is disturbing the \n"
	.string "hibitat of this route's POKéMON by \l"
	.string "trying to steal its gaurdian.\p"
	.string "Jade is already in there \n"
	.string "trying to stop them, but could \l"
	.string "you help her rescue the gaurdian?\p"
	.string "PLEASE!?$"

Route101_Text_GO:
	.string "What are you talking to me for?!\n"
	.string "GO!$"

Route101_Text_Jade_After_Cave1:
	.string "Darn, he got away...$"

Route101_Text_Jade_After_Cave2:
	.string "What were you even doing in there?\n"
	.string "I could have stopped him!$"

Route101_Text_Jade_After_Cave3_M:
	.string "Wait? You defeated all the grunts?\n"
	.string "WOW! You're getting a lot better!\p"
	.string "Those guys were pretty tough...\n"
	.string "Winning might not be as easy \l"
	.string "as I thought next time.\p"
	.string "I don't know what that Archie guy\n"
	.string "is planning but it can't be good!\p"
	.string "But this doesn't have to do with\n"
	.string "I'll defeat that Archie for sure\l"
	.string "next time we meet!$"

Route101_Text_Jade_After_Cave3_F:
	.string "Wait? You defeated all the grunts?\n"
	.string "HAHA, No way! Dad must have helped\l"
	.string "you through.\p"
	.string "There's no way those tough trainers\n"
	.string "would lose to you.\p"
	.string "I don't know what that Archie guy\n"
	.string "is planning but it can't be good!\p"
	.string "But this doesn't have to do with\n"
	.string "I'll defeat that Archie for sure\l"
	.string "next time we meet! \p"
	.string "He's waaaaaay to tough for you\n"
	.string "to beat!$"

Route101_Text_Jade_After_Cave4:
	.string "Have you started the GYM CHALLENGE\n"
	.string "yet?$"

Route101_Text_Jade_After_Cave5:
	.string "Oh, you got interrupted by dad?\n"
	.string "Then you should probably go \l"
	.string "and try to beat Winona. \p"
	.string "I've already earned my badge so\n"
	.string "I'll go home and report to dad \l"
	.string "about team aqua. \p"
	.string "I'll see you later! $"

Route101_Text_Old_Man_Stop:
	.string "Wait! only people with a ticket\n"
	.string "or a GYM BADGE are allowed \l"
	.string "to enter this cave.$"

Route101_Text_Old_Man_Go:
	.string "Ah I see you have a badge!\n"
	.string "Allow me to step aside.$"

Route101_Text_Old_Man_Stop2:
	.string "Seeing that you have neither\n"
	.string "I can't allow you to enter.$"

Route101_Text_Old_Man_Sleep:
	.string "ZZZzzz... ZZZzzz...\n"
	.string "He's in a deep sleep...\l"
	.string "I'd better leave him alone...$"
