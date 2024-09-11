BindingCavern_1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BindingCavern_1F_OnResume
	.byte 0

BindingCavern_1F_OnResume:
	setstepcallback STEP_CB_ASH
	end
