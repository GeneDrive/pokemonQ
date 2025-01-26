PetalburgCity_House3_MapScripts::
	.byte 0

PetalburgCity_House3_EventScript_OldMan::
	goto_if_set FLAG_DESSERT_PUZZLE_POKEMON_GET, PetalburgCity_House3_EventScript_OldMan_Done
	msgbox PetalburgCity_House3_Text_1, MSGBOX_NPC
	closemessage
	delay 4
	msgbox PetalburgCity_House3_Text_9, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_House3_EventScript_OldMan_Yes
	goto_if_eq VAR_RESULT, NO, PetalburgCity_House3_EventScript_OldMan_No
	end

PetalburgCity_House3_EventScript_OldMan_Yes::
	msgbox PetalburgCity_House3_Text_3, MSGBOX_NPC
	closemessage
	warp MAP_PETALBURG_CITY_GYM, 10, 15
	releaseall
	end

PetalburgCity_House3_EventScript_OldMan_No::
	msgbox PetalburgCity_House3_Text_2, MSGBOX_NPC
	releaseall
	end

PetalburgCity_House3_EventScript_OldMan_Done::
	msgbox PetalburgCity_House3_Text_7, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_House3_EventScript_OldMan_Return::
	msgbox PetalburgCity_House3_Text_4, MSGBOX_NPC
	closemessage
	delay 4
	msgbox PetalburgCity_House3_Text_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_House3_EventScript_OldMan_Return_Yes
	goto_if_eq VAR_RESULT, NO, PetalburgCity_House3_EventScript_OldMan_Return_No
	end

PetalburgCity_House3_EventScript_OldMan_Return_Yes::
	warp MAP_PETALBURG_CITY_HOUSE3, 5, 6
	end

PetalburgCity_House3_EventScript_OldMan_Return_No::
	msgbox PetalburgCity_House3_Text_5, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_House3_Text_1:
	.string "Hey there kid! are you interested\n"
	.string "in exploring the unknown?\p"
	.string "Well I'm planning on exploring a\n"
	.string "pyramid near Aridune City.$"

PetalburgCity_House3_Text_2:
	.string "Oh... that's to bad...\n"
	.string "Come back if you ever change your mind.$"

PetalburgCity_House3_Text_3:
	.string "GREAT!\p"
	.string "Let's get going then. you can fly with\n"
	.string "Me on my Corvinight.$"

PetalburgCity_House3_Text_4:
	.string "Would you like to go back?$"

PetalburgCity_House3_Text_5:
	.string "I'll be waiting for you here.$"

PetalburgCity_House3_Text_6:
	.string "Alright! Let's go then!$"

PetalburgCity_House3_Text_7:
	.string "Thanks for all your help kid!\n"
	.string "I couldn't have done it without you!$"

PetalburgCity_House3_Text_8:
	.string "Oh! are you done exploring?$"

PetalburgCity_House3_Text_9:
	.string "Would you like to join me?$"