#pragma once
// PCH.h : #include <string>
#include "PCH.h"

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
const int FPS = 60;
const int FIELD_HEIGHT = 728;
const float GAME_OVER_COOLDOWN = 10.f;
const float MUSIC_VOLUME = 70.f;
const float IMAGE_ROTATION_ANGLE = -0.2f;

//Survival Text Size
constexpr int TIMER_TEXT_SIZE = 36; //  Current Timer size
constexpr float TIMER_XCOR = 700.0f; // X coordinate
constexpr float TIMER_YCOR = 20.0f; //Y coordinate
// Adjust these values to position the text appropriately
const float TIMER_TEXT_X = SCREEN_WIDTH - 100;  // X area in which the timer will be
const float TIMER_TEXT_Y = 50;  // Y area in which the timer be at

// sprites
const float ADDITIONAL_ANGLE = 90.f;

// asteroids
const int SM_ASTEROIDS = 5;
const std::vector<float> DELTA_XY{ -2, 2 };
const float SM_RAD = 15.f;
const float BIG_RAD = 25.f;
const int ASTEROID_MIN_SPEED = 4;
const int ASTEROID_MAX_SPEED = 8;
const int DIVIDER = 175;

// weapons
// laser
const float LASER_COOLDOWN = 0.2f;
const float LASER_ACCELERATION = 12.f;
const int LASER_SND_QTY = 3;

// rocket
const int ROCKETS_SND_QTY = 4;
const float ROCKETS_QTY = 5;
const float ROCKET_ACCELERATION = 6.f;
const float ROCKET_ANGLE_STEP = 10.f;
const float ROCKET_COOLDOWN = 1.3f;

// ship
const float DEGTORAD = 0.017453f;
const int COUNTER = 1;
const float SHIP_RAD = 20.f;
//SHIFT input/modified START
const float SHIP_ACCELERATION = 0.2f;
const float DECELERATION_FACTOR = 0.99f; // The lower the value, the faster the ship stops / modifi similiar to space objects in the void
//SHIFT input/modified END
const float ROTATION_SPEED = 3.f;
const int SHIP_LIFES = 3;
const int SHIP_MAX_SPEED = 5;
const float SHIP_HEALTH = 100.f;
//POWER UP IDEA: SHIP_SHIELD
//const float SHIP_SHIELD = 100.f;

const float DAMAGE_MULTIPLIER = 2.f;

//ALARM MAYDAY Light : Player Critical Health
const float flashDuration = 1111.0f; // Duration for a complete fade in and out cycle (Similiar to alarm for a sci-fi ship in ->
									//"battle/critical status".
const float maxAlpha = 64.0f;       // Maximum alpha value for the flash (semi-transparent/intensity of the red light)


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
