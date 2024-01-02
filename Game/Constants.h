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
	const int SCREEN_WIDTH = 1366;
	const int SCREEN_HEIGHT = 768;
	const int FIELD_HEIGHT = 728;
	const float GAME_OVER_COOLDOWN = 10.f;

	// asteroids
	const int SM_ASTEROIDS = 2;
	const std::vector<float> DELTA_XY{ -2, 2 };
	const float SM_RAD = 15.f;
	const float BIG_RAD = 25.f;
	
	// weapons
	const float LASER_COOLDOWN = 0.2f;
	const int LASER_SND_QTY = 3;
	const int ROCKETS_SND_QTY = 4;
	const float ROCKETS_QTY = 5;
	const float ROCKET_STEP = 10.f;
	const float ROCKET_COOLDOWN = 1.3f;

	// ship
	const float DEGTORAD = 0.017453f;
	const int COUNTER = 1;
	const float SHIP_RAD = 20.f;

	// UI
	const float MENU_HEIGHT = 40.f;
	const float MENU_XCOR = 0.f;
	const float MENU_YCOR = 728.f;
	const float HP_XCOR = 30.f;
	const float HP_YCOR = 740.f;
	const float HP_WIDTH = 100.f;
	const float HP_HEIGHT = 15.f;
	const float LIFE_SIZE = 25.f;
	const float LIFE_STEP = 32.f;
	const float LIFE_YCOR = 737.f;
	const float ICON1_XCOR = 270.f;
	const float ICON1_YCOR = 748.f;
	const float ICON2_XCOR = 300.f;
	const float ICON2_YCOR = 748.f;
	const float SELECTOR_SIZE = 28.f;
	const float SELECT1_XCOR = 260.f;
	const float SELECT_YCOR = 734.f;
	const float SELECT2_XCOR = 293.f;
	const float WEAP_ICON_ANGLE = 90.f;
	const float LASER_RAD = 10.f;
	const float ROCKET_RAD = 10.f;
}