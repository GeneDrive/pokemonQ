PetalburgCity_pyramid_halway_MapScripts::
	.byte 0

PetalburgCity_pyramid_halway_EventScript_Puzzle::
	msgbox PetalburgCity_pyramid_halway_Text_Puzzle, MSGBOX_DEFAULT
	closemessage
	goto_if_set FLAG_DESSERT_PUZZLE_DONE, PetalburgCity_pyramid_halway_EventScript_NoEffect
	specialvar VAR_RESULT, CheckDesertPuzzle
	goto_if_eq VAR_RESULT, FALSE, PetalburgCity_pyramid_halway_EventScript_NoEffect
	msgbox PetalburgCity_pyramid_halway_Text_Puzzle_Success, MSGBOX_DEFAULT
	closemessage
	fadeoutbgm 0
	playse SE_TRUCK_MOVE
	special DoSealedChamberShakingEffect_Long
	waitstate
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	fadeinbgm 0
	setflag FLAG_DESSERT_PUZZLE_DONE
	releaseall
	msgbox PetalburgCity_pyramid_halway_Text_Open, MSGBOX_DEFAULT
	closemessage
	warp MAP_PETALBURG_CITY_PYRAMID_HALWAY_OPEN, 7, 13
	end

PetalburgCity_pyramid_halway_EventScript_NoEffect::
	releaseall
	end

PetalburgCity_pyramid_halway_EventScript_WarpBackConfirm1::
	msgbox PetalburgCity_pyramid_halway_Text_Confirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_pyramid_halway_EventScript_WarpBack1
	goto_if_eq VAR_RESULT, NO, PetalburgCity_pyramid_halway_EventScript_Cancel
	end

PetalburgCity_pyramid_halway_EventScript_WarpBackConfirm2::
	msgbox PetalburgCity_pyramid_halway_Text_Confirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_pyramid_halway_EventScript_WarpBack2
	goto_if_eq VAR_RESULT, NO, PetalburgCity_pyramid_halway_EventScript_Cancel
	end

PetalburgCity_pyramid_halway_EventScript_WarpBackConfirm3::
	msgbox PetalburgCity_pyramid_halway_Text_Confirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_pyramid_halway_EventScript_WarpBack3
	goto_if_eq VAR_RESULT, NO, PetalburgCity_pyramid_halway_EventScript_Cancel
	end

PetalburgCity_pyramid_halway_EventScript_WarpBack1::
	warp MAP_PETALBURG_CITY_PYRAMID, 8, 7
	end

PetalburgCity_pyramid_halway_EventScript_WarpBack2::
	warp MAP_PETALBURG_CITY_PYRAMID, 9, 7
	end

PetalburgCity_pyramid_halway_EventScript_WarpBack3::
	warp MAP_PETALBURG_CITY_PYRAMID, 10, 7
	end

PetalburgCity_pyramid_halway_EventScript_Cancel::
	releaseall
	end

PetalburgCity_pyramid_halway_Text_Puzzle::
	.string "To you who reads. A trial will\n"
	.string "be given to you.\p"
	.string "The original one demands these three.\n"
	.string "The way will be revealed to the one\l"
	.string "who brings three and only these three.\p"
	.string "Bring them in the order that\n"
	.string "has been given to thee.\p"
	.string "First, the unbreakable one that bends\n"
	.string "the light to his will.\p"
	.string "Then the child companion of aura.\p"
	.string "Finally, a childrens toy \n"
	.string "given life through eternities.\p"
	.string "When these are offered, a descendants\n"
	.string "reward will reveal itself.$"

PetalburgCity_pyramid_halway_Text_Puzzle_Success::
	.string "The text starts to glow!$"

PetalburgCity_pyramid_halway_Text_Confirm::
	.string "Do you want to go inside?$"

PetalburgCity_pyramid_halway_Text_Open::
	.string "A door opens north...$"