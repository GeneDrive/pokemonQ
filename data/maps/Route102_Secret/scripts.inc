.set LOCALID_BALL1, 4
.set LOCALID_BALL2, 5
.set LOCALID_BALL3, 6

Route102_Secret_MapScripts::
	.byte 0

Route102_Secret_EventScript_Sally::
	trainerbattle_double TRAINER_SALLY, Route102_Secret_Text_SallyIntro, Route102_Secret_Text_SallyDefeat, Route102_Secret_Text_Not_enough
	msgbox Route102_Secret_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Secret_EventScript_Eddie::
	trainerbattle_double TRAINER_EDDIE, Route102_Secret_Text_EddieIntro, Route102_Secret_Text_EddieDefeat, Route102_Secret_Text_Not_enough
	msgbox Route102_Secret_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Secret_EventScript_Robin::
	trainerbattle_double TRAINER_ROBIN, Route102_Secret_Text_RobinIntro, Route102_Secret_Text_RobinDefeat, Route102_Secret_Text_Not_enough
	msgbox Route102_Secret_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	setvar VAR_ROUTE102_STATE, 1
	end

Route102_Secret_EventScript_Robin_Post::
	setvar VAR_ROUTE102_STATE, 1
	msgbox Route102_Secret_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Secret_EventScript_OOPS::
	setvar VAR_ROUTE102_STATE, 1
	end

Route102_Secret_StartGivePokemonDialog1::
	msgbox Route102_Secret_Text_Choose_Pokemon1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route102_Secret_GivePokemon1
	goto_if_eq VAR_RESULT, NO, Route102_Secret_GoodLuck
	end

Route102_Secret_StartGivePokemonDialog2::
	msgbox Route102_Secret_Text_Choose_Pokemon2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route102_Secret_GivePokemon2
	goto_if_eq VAR_RESULT, NO, Route102_Secret_GoodLuck
	end

Route102_Secret_StartGivePokemonDialog3::
	msgbox Route102_Secret_Text_Choose_Pokemon3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route102_Secret_GivePokemon3
	goto_if_eq VAR_RESULT, NO, Route102_Secret_GoodLuck
	end

Route102_Secret_GivePokemon1::
	removeobject LOCALID_BALL1
	givemon SPECIES_TORCHIC, 12
	playfanfare MUS_OBTAIN_ITEM
	message Route102_Secret_Text_Received_Pokemon1
	waitfanfare
	closemessage
	warp MAP_ROUTE102, 0, 24
	end

Route102_Secret_GivePokemon2::
	removeobject LOCALID_BALL2
	givemon SPECIES_TREECKO, 12
	playfanfare MUS_OBTAIN_ITEM
	message Route102_Secret_Text_Received_Pokemon2
	waitfanfare
	closemessage
	warp MAP_ROUTE102, 0, 24
	end

Route102_Secret_GivePokemon3::
	removeobject LOCALID_BALL3
	givemon SPECIES_MUDKIP, 12
	playfanfare MUS_OBTAIN_ITEM
	message Route102_Secret_Text_Received_Pokemon3
	waitfanfare
	closemessage
	warp MAP_ROUTE102, 0, 24
	end

Route102_Secret_GoodLuck::
	closemessage
	releaseall
	end

Route102_Secret_Text_SallyIntro:
	.string "I'll burn and blaze my way to victory\n"
	.string "with my burning POKéMON!$"

Route102_Secret_Text_SallyDefeat:
	.string "My fire's been extinguished…$"

Route102_Secret_Text_SallyPostBattle:
	.string "We can't even heat up anymore…$"

Route102_Secret_Text_EddieIntro:
	.string "Me and this team found this place\n"
	.string "by accident… and we've struck gold!$"

Route102_Secret_Text_EddieDefeat:
	.string "I lost…$"

Route102_Secret_Text_EddiePostBattle:
	.string "I lost my way, I lost a battle, and I'm\n"
	.string "now even more lost… I can't get out…$"

Route102_Secret_Text_RobinIntro:
	.string "Don't try to stop us kid!$"

Route102_Secret_Text_RobinDefeat:
	.string "I lost with these POKéMON!?\n"
	.string "HOW!?!$"

Route102_Secret_Text_RobinPostBattle:
	.string "You're strong!\n"
	.string "Just who are you?$"

Route102_Secret_Text_Not_enough:
	.string "You're strong!\n"
	.string "Just who are you?$"

Route102_Secret_Text_Choose_Pokemon1:
	.string "Do you want to choose TORCHIC?$"

Route102_Secret_Text_Choose_Pokemon2:
	.string "Do you want to choose TREECKO?$"

Route102_Secret_Text_Choose_Pokemon3:
	.string "Do you want to choose MUDKIP?$"

Route102_Secret_Text_Received_Pokemon1:
	.string "{PLAYER} received a TORCHIC!$"

Route102_Secret_Text_Received_Pokemon2:
	.string "{PLAYER} received a TREECKO!$"

Route102_Secret_Text_Received_Pokemon3:
	.string "{PLAYER} received a MUDKIP!$"
