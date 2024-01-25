#pragma once
//-------------------------------------------------------------------------------------
#ifndef INPUT_H
#define INPUT_H
/// <summary>
/// Player Input
/// Numpad8, Numpad9, KEY_ADD, 	KEY_SUBTRACT
/// KEY_RESTART ( game restart via key)
/// </summary>
class Input
{
public:

	/**
	 * An enum denoting all possible input keys.
	 */
	enum class KEY
	{
		Numpad8,
		Numpad9,
		//KEY_RESTART,
		KEY_ADD,
		KEY_SUBTRACT,
		

	};

	/**
	 * Checks if a given key is currently pressed.
	 * @param keycode The key to check.
	 * @return True if the given key is currently pressed.
	 */
	static bool IsKeyPressed(KEY keycode);
};
#endif