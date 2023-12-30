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
	const int WIDTH = 1366;
	const int HEIGHT = 768;
	const int SM_ASTEROIDS = 2;
	const float DEGTORAD = 0.017453f;
	const float LASER_COOLDOWN = 0.2f;
	const int COUNTER = 1;
	const float COOLDOWN_X_COORD = 600.f;
	const float COOLDOWN_Y_COORD = 320.f;
	const int COOLDOWN_TEXT_SIZE = 55;
	const int LASER_SND_QTY = 3;
	const float TITLE_X_COORD = 370;
	const float TITLE_Y_COORD = 300;
	const float GAME_OVER_COOLDOWN = 7.f;
	const std::vector<float> DELTA_XY{ -2, 2 };
}