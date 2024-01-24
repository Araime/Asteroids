#include "../header/PCH.h"

#include "../header/Input.h"

// Returns true if the given key is pressed.
// Player Inputs Update
bool Input::IsKeyPressed(KEY keycode)
{
	switch (keycode)
	{
	
		//Increase music volume
	case Input::KEY::KEY_ADD:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
		{
			return true;
		}
		break;
		//Lower music volume
	case Input::KEY::KEY_SUBTRACT:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
		{
			return true;
		}
		break;
		//Skip to next music, will leave it up to you, if you wish to implement that feature for this game : Asteroids
	case Input::KEY::Numpad9:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
		{
			return true;
		}
		break;
		//Mute & Unmute music
	case Input::KEY::Numpad8:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
		{
			return true;
		}
		break;

	}



	return false;
}