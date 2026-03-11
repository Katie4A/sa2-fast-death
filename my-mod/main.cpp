#include "pch.h"
#include "Kill.h"

extern "C"
{
	static int prevButtons = 0;
	
	// Optional.
	// This function runs code one time when the game starts up. Great for loading assets and setting things up.
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
	}

	// Optional.
	// This function runs code on every frame of the game, INCLUDING being in menus, cutscenes, etc.
	// It is recommended to test for game state so that you only run code at a specific time.
	__declspec(dllexport) void __cdecl OnFrame()
	{
		// are we in-game?
		if (GameState == GameStates_Ingame) {
			// keep track of previous button presses by negating prevButtons and ANDing that with the current buttons pressed
			int buttons = ControllerPointers[0]->on;
			int buttonsPressed = ~prevButtons & buttons;
			prevButtons = buttons; // if bit is set to 1, prevButtons will be negated to prevent double-presses 
			
			// is the right d-pad currently being pressed?
			if (buttonsPressed & Buttons_Right) {
				killPlayer(CurrentLevel);
			}
		}
	}

	// Optional.
	// This function runs code every time the player inputs. Good for adding custom inputs / overriding events.
	__declspec(dllexport) void __cdecl OnInput()
	{
	}

	// Optional.
	// This function runs while the game processes input.
	__declspec(dllexport) void __cdecl OnControl()
	{
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}
