.set LOCALID_NURSE, 1
.set LOCALID_MOVE_RELEARNER, 5

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "That PC in the corner there is\n"
	.string "for any POKéMON TRAINER to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON CENTERS are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.$"

OldaleTown_PokemonCenter_1F_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, OldaleTown_PokemonCenter_1F_EventScript_AskTeachMove
	msgbox OldaleTown_PokemonCenter_1F_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto OldaleTown_PokemonCenter_1F_EventScript_AskTeachMove
	end

OldaleTown_PokemonCenter_1F_EventScript_AskTeachMove::
	msgbox OldaleTown_PokemonCenter_1F_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, OldaleTown_PokemonCenter_1F_EventScript_ComeBackWithHeartScale
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	end

OldaleTown_PokemonCenter_1F_EventScript_ChooseMon::
	msgbox OldaleTown_PokemonCenter_1F_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_PokemonCenter_1F_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_PokemonCenter_1F_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, OldaleTown_PokemonCenter_1F_EventScript_NoMoveToTeachMon
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMove
	end

OldaleTown_PokemonCenter_1F_EventScript_ChooseMove::
	msgbox OldaleTown_PokemonCenter_1F_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	msgbox OldaleTown_PokemonCenter_1F_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto OldaleTown_PokemonCenter_1F_EventScript_ComeBackWithHeartScale
	end

OldaleTown_PokemonCenter_1F_EventScript_NoMoveToTeachMon::
	msgbox OldaleTown_PokemonCenter_1F_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	end

OldaleTown_PokemonCenter_1F_EventScript_CantTeachEgg::
	msgbox OldaleTown_PokemonCenter_1F_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	end

OldaleTown_PokemonCenter_1F_EventScript_ComeBackWithHeartScale::
	msgbox OldaleTown_PokemonCenter_1F_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_PokemonCenter_1F_Text_ImTheMoveTutor:
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

OldaleTown_PokemonCenter_1F_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "Let me guess, you want me to teach\n"
	.string "a move?$"

OldaleTown_PokemonCenter_1F_Text_TutorWhichMon:
	.string "Which POKéMON needs tutoring?$"

OldaleTown_PokemonCenter_1F_Text_TeachWhichMove:
	.string "Which move should I teach?$"

OldaleTown_PokemonCenter_1F_Text_DontHaveMoveToTeachPokemon:
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"

OldaleTown_PokemonCenter_1F_Text_HandedOverHeartScale:
	.string "{PLAYER} firmly shook his hand in exchange.$"

OldaleTown_PokemonCenter_1F_Text_ComeBackWithHeartScale:
	.string "If your POKéMON need to learn a move,\n"
	.string "come back and see me.$"

OldaleTown_PokemonCenter_1F_Text_CantTeachEgg:
	.string "What are you? An EGG HEAD!?\p"
	.string "There isn't a single move that\n"
	.string "I can teach an EGG.$"