#pragma once
#include <string>

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
const int BUTTON_TEXT_SIZE = 60;
const int UI_TEXT_SIZE = 20;

// main game
const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;
const int FPS = 60;
const int FIELD_HEIGHT = 728;
const float GAME_OVER_COOLDOWN = 10.f;
const float MUSIC_VOLUME = 70.f;
const float IMAGE_ROTATION_ANGLE = -0.2f;

// buttons
const std::string START_BTN_TXT = "START";
const std::string QUIT_BTN_TXT = "QUIT";
const std::string RESTART_BTN_TXT = "RESTART";
const float LEFT_BTN_XCOR = 350.f;
const float RIGHT_BTN_XCOR = 1000.f;
const float BTNS_YCOR = 600.f;
const float START_BTN_WIDTH = 145.f;
const float QUIT_BTN_WIDTH = 105.f;
const float RESTART_BTN_WIDTH = 195.f;
const float BTNS_HEIGHT = 45.f;

// sprites
const float ADDITIONAL_ANGLE = 90.f;

// asteroids
const int SM_ASTEROIDS = 2;
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
const float DEGREES_TO_RADIANS = 0.017453f;
const int COUNTER = 1;
const float SHIP_RAD = 25.f;
const float SHIP_ACCELERATION = 0.2f;
const float DECELERATION_FACTOR = 0.99f; // The lower the value, the faster the ship stops
const float ROTATION_SPEED = 3.f;
const int SHIP_LIFES = 3;
const int SHIP_MAX_SPEED = 5;
const float SHIP_HEALTH = 100.f;
const float DAMAGE_MULTIPLIER = 2.f;

// UI
const float MENU_HEIGHT = 40.f;
const float MENU_XCOR = 0.f;
const float MENU_YCOR = 728.f;
const float HP_XCOR = 30.f;
const float HP_YCOR = 740.f;
const float HP_WIDTH = 100.f;
const float HP_HEIGHT = 15.f;
const float LIFE_SIZE = 25.f;
const float LIFE_STEP = 36.f;
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
const float UI_XCOR = 1100.f;
const float UI_YCOR = 735.f;
