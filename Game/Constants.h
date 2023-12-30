#pragma once
#include <string>

namespace AsteroidsGame
{
	// init paths variables
	const std::string IMG_PATH = "Resources/Images/";
	const std::string FONT_PATH = "Resources/Fonts/";
	const std::string SND_PATH = "Resources/Sounds/";

	// init game variables
	// texts
	const std::string GAME_NAME = "Asteroids";
	const std::string TITLE_TEXT = "ASTEROIDS";
	const std::string GAME_OVER_TEXT = "GAME OVER";
	const int COOLDOWN_TEXT_SIZE = 55;
	const int TITLE_TEXT_SIZE = 128;

	// main game
	const int WIDTH = 1366;
	const int HEIGHT = 768;
	const float GAME_OVER_COOLDOWN = 10.f;

	// asteroids
	const int SM_ASTEROIDS = 2;
	const std::vector<float> DELTA_XY{ -2, 2 };
	
	// weapon
	const float LASER_COOLDOWN = 0.2f;
	const int LASER_SND_QTY = 3;
	const float ROCKETS_QTY = 3;
	const float ROCKET_STEP = 20.f;
	const float ROCKET_COOLDOWN = 0.8f;

	// ship
	const float DEGTORAD = 0.017453f;
	const int COUNTER = 1;

	//UI
	const float LIFE_SIZE = 25.f;
	const float HEALTH_WIDTH = 100.f;
	const float HEALTH_HEIGHT = 15.f;
	const float LIFE_STEP = 32.f;
	const float LIFE_Y = 727.f;
}