PetalburgCity_pyramid_MapScripts::
	.byte 0

PetalburgCity_pyramid_EventScript_WarpBackConfirm1::
	msgbox PetalburgCity_pyramid_halway_Text_Confirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_pyramid_EventScript_WarpNext1
	goto_if_eq VAR_RESULT, NO, PetalburgCity_pyramid_halway_EventScript_Cancel
	end

PetalburgCity_pyramid_EventScript_WarpBackConfirm2::
	msgbox PetalburgCity_pyramid_halway_Text_Confirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_pyramid_EventScript_WarpNext2
	goto_if_eq VAR_RESULT, NO, PetalburgCity_pyramid_halway_EventScript_Cancel
	end

PetalburgCity_pyramid_EventScript_WarpBackConfirm3::
	msgbox PetalburgCity_pyramid_halway_Text_Confirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_pyramid_EventScript_WarpNext3
	goto_if_eq VAR_RESULT, NO, PetalburgCity_pyramid_halway_EventScript_Cancel
	end

PetalburgCity_pyramid_EventScript_WarpNext1::
	goto_if_set FLAG_DESSERT_PUZZLE_DONE, PetalburgCity_pyramid_EventScript_WarpOpen1
	warp MAP_PETALBURG_CITY_PYRAMID_HALWAY, 6, 20
	end

PetalburgCity_pyramid_EventScript_WarpNext2::
	goto_if_set FLAG_DESSERT_PUZZLE_DONE, PetalburgCity_pyramid_EventScript_WarpOpen2
	warp MAP_PETALBURG_CITY_PYRAMID_HALWAY, 7, 20
	end

PetalburgCity_pyramid_EventScript_WarpNext3::
	goto_if_set FLAG_DESSERT_PUZZLE_DONE, PetalburgCity_pyramid_EventScript_WarpOpen3
	warp MAP_PETALBURG_CITY_PYRAMID_HALWAY, 8, 20
	end

PetalburgCity_pyramid_EventScript_WarpOpen1::
	warp MAP_PETALBURG_CITY_PYRAMID_HALWAY_OPEN, 6, 16
	end

PetalburgCity_pyramid_EventScript_WarpOpen2::
	warp MAP_PETALBURG_CITY_PYRAMID_HALWAY_OPEN, 7, 16
	end

PetalburgCity_pyramid_EventScript_WarpOpen3::
	warp MAP_PETALBURG_CITY_PYRAMID_HALWAY_OPEN, 8, 16
	end