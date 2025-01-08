.set LOCALID_NURSE, 1
.set LOCALID_MOVE_RELEARNER, 5

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "My POKéMON has a NAIVE nature, and my\n"
	.string "friend's has a JOLLY nature.\p"
	.string "It's fascinating how POKéMON have\n"
	.string "personalities!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Just like people, there are male and\n"
	.string "female POKéMON.\p"
	.string "But no one seems to have any idea how\n"
	.string "they're different.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "The man next door gave me an HM!\p"
	.string "I used it to teach my POKéMON how to\n"
	.string "CUT down skinny trees.$"

RustboroCity_PokemonCenter_1F_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, RustboroCity_PokemonCenter_1F_EventScript_AskTeachMove
	msgbox RustboroCity_PokemonCenter_1F_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto RustboroCity_PokemonCenter_1F_EventScript_AskTeachMove
	end

RustboroCity_PokemonCenter_1F_EventScript_AskTeachMove::
	msgbox RustboroCity_PokemonCenter_1F_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, RustboroCity_PokemonCenter_1F_EventScript_ComeBackWithHeartScale
	goto RustboroCity_PokemonCenter_1F_EventScript_ChooseMon
	end

RustboroCity_PokemonCenter_1F_EventScript_ChooseMon::
	msgbox RustboroCity_PokemonCenter_1F_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_PokemonCenter_1F_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_PokemonCenter_1F_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, RustboroCity_PokemonCenter_1F_EventScript_NoMoveToTeachMon
	goto RustboroCity_PokemonCenter_1F_EventScript_ChooseMove
	end

RustboroCity_PokemonCenter_1F_EventScript_ChooseMove::
	msgbox RustboroCity_PokemonCenter_1F_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, RustboroCity_PokemonCenter_1F_EventScript_ChooseMon
	msgbox RustboroCity_PokemonCenter_1F_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto RustboroCity_PokemonCenter_1F_EventScript_ComeBackWithHeartScale
	end

RustboroCity_PokemonCenter_1F_EventScript_NoMoveToTeachMon::
	msgbox RustboroCity_PokemonCenter_1F_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto RustboroCity_PokemonCenter_1F_EventScript_ChooseMon
	end

RustboroCity_PokemonCenter_1F_EventScript_CantTeachEgg::
	msgbox RustboroCity_PokemonCenter_1F_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto RustboroCity_PokemonCenter_1F_EventScript_ChooseMon
	end

RustboroCity_PokemonCenter_1F_EventScript_ComeBackWithHeartScale::
	msgbox RustboroCity_PokemonCenter_1F_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_PokemonCenter_1F_Text_ImTheMoveTutor:
	.string "I'm the MOVE TUTOR.\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--every one of them--and I can\l"
	.string "teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours if you'd like.\p"
	.string "And I have good news for you...\n"
	.string "I'll do it for a FREE!\p"
	.string "Okay... not totally free...\n"
	.string "Just give me a handshake and I'm happy!$"

RustboroCity_PokemonCenter_1F_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "Let me guess, you want me to teach\n"
	.string "a move?$"

RustboroCity_PokemonCenter_1F_Text_TutorWhichMon:
	.string "Which POKéMON needs tutoring?$"

RustboroCity_PokemonCenter_1F_Text_TeachWhichMove:
	.string "Which move should I teach?$"

RustboroCity_PokemonCenter_1F_Text_DontHaveMoveToTeachPokemon:
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"

RustboroCity_PokemonCenter_1F_Text_HandedOverHeartScale:
	.string "{PLAYER} firmly shook his hand in exchange.$"

RustboroCity_PokemonCenter_1F_Text_ComeBackWithHeartScale:
	.string "If your POKéMON need to learn a move,\n"
	.string "come back and see me.$"

RustboroCity_PokemonCenter_1F_Text_CantTeachEgg:
	.string "What are you? An EGG HEAD!?\p"
	.string "There isn't a single move that\n"
	.string "I can teach an EGG.$"