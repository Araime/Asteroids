#pragma once
#include <string>

namespace AsteroidsGame
{
	// init paths variables
	const std::string IMG_PATH = "Resources/Images/";
	const std::string FONT_PATH = "Resources/Fonts/";
	const std::string SND_PATH = "Resources/Sounds/";

	// init game variables
	const std::string TITLE = "Asteroids";
	const int WIDTH = 1200;
	const int HEIGHT = 800;
	const int SM_ASTEROIDS = 2;
	const float DEGTORAD = 0.017453f;
	const float LASER_COOLDOWN = 0.2f;
	const float DESTROY_COLLDOWN = 3.f;
}