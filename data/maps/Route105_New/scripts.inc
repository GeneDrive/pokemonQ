.set LOCALID_ALICA, 1
.set LOCALID_WALLY, 2
.set LOCALID_STARTGIRL, 3

Route105_New_MapScripts::
	.byte 0

Route105_New_EventScript_TalkStartGirl::
	lockall
	applymovement LOCALID_STARTGIRL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route105_New_Text_LoveTheWind, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route105_New_EventScript_Trigger1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Route105_New_Block_Player_Down
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route105_New_Block_Player_Face_Right
	waitmovement 0
	goto Route105_New_EventScript_WallyEvent
	end

Route105_New_EventScript_Trigger2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Route105_New_Block_Player_Right
	waitmovement 0
	goto Route105_New_EventScript_WallyEvent
	end

Route105_New_EventScript_WallyEvent::
	msgbox Route105_New_Text_Alica1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLY, Route105_New_Block_Player_Face_Left
	waitmovement 0
	applymovement LOCALID_ALICA, Route105_New_Block_Player_Face_Left
	waitmovement 0
	delay 5
	msgbox Route105_New_Text_Wally1, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox Route105_New_Text_Alica2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLY, Route105_New_Block_Player_Face_Up
	waitmovement 0
	applymovement LOCALID_ALICA, Route105_New_Block_Player_Face_Down
	waitmovement 0
	delay 5
	msgbox Route105_New_Text_Alica3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLY, Route105_New_Block_Player_Face_Left
	waitmovement 0
	applymovement LOCALID_ALICA, Route105_New_Block_Player_Face_Left
	waitmovement 0
	delay 5
	msgbox Route105_New_Text_Wally2, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement LOCALID_ALICA, Route105_New_Block_Player_Face_Down
	waitmovement 0
	delay 5
	msgbox Route105_New_Text_Alica4, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route105_New_Text_Receive_Wrappadan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 5
	applymovement LOCALID_ALICA, Route105_New_Block_Player_Face_Left
	waitmovement 0
	delay 5
	msgbox Route105_New_Text_Wally3, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_YUJI, Route105_New_Text_Wally_Defeat
	setvar VAR_ROUTE105_STATE, 1
	delay 5
	msgbox Route105_New_Text_Wally4, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement LOCALID_WALLY, Route105_New_Block_Player_Face_Up
	waitmovement 0
	applymovement LOCALID_ALICA, Route105_New_Block_Player_Face_Down
	waitmovement 0
	delay 5
	msgbox Route105_New_Text_Alica5, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLY, Route105_New_Block_Player_Face_Left
	waitmovement 0
	applymovement LOCALID_ALICA, Route105_New_Block_Player_Face_Left
	waitmovement 0
	delay 5
	msgbox Route105_New_Text_Alica6, MSGBOX_DEFAULT
	closemessage
	delay 5
	msgbox Route105_New_Text_Alica7, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement LOCALID_WALLY, Route105_New_Block_Player_Face_Up
	waitmovement 0
	applymovement LOCALID_ALICA, Route105_New_Block_Player_Face_Down
	waitmovement 0
	msgbox Route105_New_Text_Alica8, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement LOCALID_ALICA, Route105_New_Block_Player_Face_Left
	waitmovement 0
	delay 5
	msgbox Route105_New_Text_Alica9, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement LOCALID_ALICA, Route105_New_Block_Alica_Leave
	waitmovement 0
	delay 5
	msgbox Route105_New_Text_Wally5, MSGBOX_DEFAULT
	closemessage
	delay 5
	applymovement LOCALID_WALLY, Route105_New_Block_Wally_Leave
	waitmovement 0
	delay 5
	setflag FLAG_ROUTE_105_HIDE_RIVALS
	pokenavcall Route105_New_Text_LevelCapIncrease
	waitmessage
	delay 5
	releaseall
	end

Route105_New_Block_Player_Face_Up::
	face_up
	step_end

Route105_New_Block_Player_Face_Down::
	face_down
	step_end

Route105_New_Block_Player_Face_Left::
	face_left
	step_end

Route105_New_Block_Player_Face_Right::
	face_right
	step_end

Route105_New_Block_Alica_Leave::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route105_New_Block_Wally_Leave::
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route105_New_Block_Player_Down::
	walk_right
	walk_Down
	step_end

Route105_New_Block_Player_Right::
	walk_right
	step_end
	
Route105_New_Text_LoveTheWind:
	.string "I just love coming here and\n"
	.string "Feeling the wind through my hair$"

Route105_New_Text_Alica1:
	.string "And thn you braid this part \n"
	.string "and then pull the string through here...$"

Route105_New_Text_Wally1:
	.string "{PLAYER}!!! W-w-what are you..?\n"
	.string "This isn't what it looks...\l"
	.string "I was just... um...$"

Route105_New_Text_Alica2:
	.string "Who is this guy supposed to be? \p"
	.string "My brother sent you here didn't he?\n"
	.string "You go tell him he should be the one\l"
	.string "to manage the GYM and leave me alone!$"

Route105_New_Text_Alica3:
	.string "Hey Wally, you're not going to let\n"
	.string "this guy interupt our quality time\l"
	.string "together are you?$"

Route105_New_Text_Wally2:
	.string "Umm... I'm sorry, No I'm not gonna\n"
	.string "let him!\p"
	.string "If I defeat you she will stay\n"
	.string "here with me!$"

Route105_New_Text_Alica4:
	.string "Oh Wally...<3\p"
	.string "Here take one of my pokemon\n"
	
Route105_New_Text_Wally3:
	.string "Here I come!$"

Route105_New_Text_Wally4:
	.string "Of course I lost again...$"

Route105_New_Text_Alica5:
	.string "Oh wow, you're something else!\n"
	.string "Don't beat yourself up Wally, I would\l"
	.string "have had a hard time with him too...$"

Route105_New_Text_Alica6:
	.string "I'm sorry, I didn't mean to snap at you.\n"
	.string "I'm just a little frustrated right now.$"
	
Route105_New_Text_Alica7:
	.string "I finnaly found someone who I can\n"
	.string "want to spend time with and my brother\l"
	.string "sends you to ruin it!\p"
	.string "I guess I should be happy that he\n"
	.string "cares about me, but I'm not a child!\l"
	.string "I would have come back to the GYM when\n"
	.string "I was ready!\p"
	.string "But I'm just going to have to talk to\n"
	.string "him about this myself.\p"
	.string "I'm sorry for snapping at you.$"

Route105_New_Text_Alica8:
	.string "Wally, I'll go back to the GYM to talk\n"
	.string "to my brother myself, So come by\l"
	.string "the GYM later. I'll want to see you...$"

Route105_New_Text_Alica9:
	.string "And you {PLAYER} was it? I'll see\n"
	.string "you at the GYM if you're strong enough\l"
	.string "to make it through our students!\p"
	.string "I'll be waiting for you guys!\n"
	.string "So, bye for now!$"

Route105_New_Text_Wally5:
	.string "Well, I guess I should go too\n"
	.string "I'll see you at the GYM later!$"

Route105_New_Text_Receive_Wrappadan:
	.string "Wally received Alica's Wrappadan!$"

Route105_New_Text_Wally_Defeat:
	.string "I'm sorry Alica...$"

Route105_New_Text_LevelCapIncrease:
	.string "Level cap increased to Level 28!$"