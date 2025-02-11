#pragma once

#include <SFML/Graphics.hpp>

#include <list>
#include <string>

#include "Animation.h"
#include "Asteroid.h"
#include "Background.h"
#include "Button.h"
#include "Entity.h"
#include "HealthPickup.h"
#include "Laser.h"
#include "LaserPickup.h"
#include "Math.h"
#include "Rocket.h"
#include "RocketPickup.h"
#include "Ship.h"
#include "Sound.h"
#include "ScoreTable.h"
#include "ShieldPickup.h"
#include "Text.h"
#include "UI.h"

enum class GameState
{
	TitleScreen = 0,
	Game,
	GameOver
};

class Game
{
public:
	GameState gameState = GameState::TitleScreen;

	// set max asteroids num
	int asteroids_num = 12;

	// create cooldown timer value and text
	int destroy_cooldown = DESTROY_COOLDOWN;
	std::string cooldownStr = "Get Ready\n\t\t\t";
	std::string gameoverStr = "GAME OVER";

	// create player score:
	int playerScore = 0;

	// create game timers
	sf::Clock gameTimer;
	sf::Clock Clock;
	float newTime = 0.f;
	float pastTime = 0.f;
	float deltaTime = 0.f;

	// create fonts
	sf::Font cooldownFont;
	sf::Font titleFont;
	sf::Font UIFont;

	// create game texts
	Text cooldownText;
	Text bigText;
	Text smallText;

	// create buttons
	Button startButton;
	Button quitButton;
	Button restartButton;

	// mouse position coord
	sf::Vector2f mousePos;

	// create BG's
	BG menuBG;
	BG levelBG;
	BG gameOverBG;
	sf::Texture menuTexture;
	sf::Texture levelTexture;
	sf::Texture gameOverTexture;

	// create sounds and music
	Sound timerSnd;
	Sound laserSnd1;
	Sound laserSnd2;
	Sound laserSnd3;
	Sound RocketSnd1;
	Sound RocketSnd2;
	Sound RocketSnd3;
	Sound RocketSnd4;
	Sound weapChangeSnd;
	Sound asteroidExplSnd;
	Sound shipExplSnd;
	Sound buttonHover;
	Sound buttonClick;
	Sound healthPickupSnd;
	Sound laserPickupSnd;
	Sound rocketPickupSnd;
	Sound shieldPickupSnd;

	Music gameMusic;

	// create laser and rocket snd arrays
	Sound laserSndArray[LASER_SND_QTY];
	Sound rocketSndArray[ROCKETS_SND_QTY];

	// create game textures
	sf::Texture shipTexture;
	sf::Texture flyingShipTexture;
	sf::Texture shipLife;
	sf::Texture laserTexture;
	sf::Texture rocketTexture;
	sf::Texture rockTexture;
	sf::Texture smallRockTexture;
	sf::Texture explosionTexture1;
	sf::Texture explosionTexture2;
	sf::Texture laserPickup;
	sf::Texture healthPickup;
	sf::Texture rocketPickup;
	sf::Texture shieldPickup;
	sf::Texture pickupEffectTexture;
	sf::Texture shieldEffectTexture;
	sf::Texture laserIcon;
	sf::Texture rocketIcon;
	sf::Texture powerLevelTexture;

	// create all objects of animations
	Animation sLaser;
	Animation sRocket;
	Animation sAsteroidExplosion;
	Animation sShipExplosion;
	Animation sRock;
	Animation sRockSmall;
	Animation sShip;
	Animation sFlyingShip;
	Animation sLaserPickup;
	Animation sHealthPickup;
	Animation sRocketPickup;
	Animation sShieldPickup;
	Animation sPickupEffect;
	Animation sShieldEffect;

	// create list of all objects
	std::list<Entity*> entities;

	// create player ship
	//Ship* player = new Ship;
	Ship* player;

	// create health bar rectangles
	UserInterface UI;

	// create score table
	ScoreTable scoreTable;

	void LoadFont(sf::Font& text, const std::string path);
	void LoadTexture(sf::Texture& object, const std::string path);
	void LoadSound(Sound& snd, const std::string path, float volume = 0);

	void InitGame(Game& game);
	void RestartGame(Game& game);

	void CheckAllCollisions(Game& game);
	void CheckAsteroidAndShotCollision(Game& game, Entity* first_obj, Entity* second_obj);
	void CheckCollisionPlayerAndAsteroid(Game& game, Entity* first_obj, Entity* second_obj);
	void CheckCollisionPlayerAndPickup(Game& game, Entity* first_obj, Entity* second_obj);
	void GameOver(Game& game);
	void Check—ompletedAnimations(Game& game);

	void CreateSmallAsteroids(Game& game, Entity* first_obj);
	void CreateAsteroid(Game& game);
	void CreateRandomPickup(Game& game, Entity* obj);
	void CreateExplosionAnimation(Game& game, Entity* first_obj, Animation& expl_animation);
	void CreatePickupEffectAnimation(Game& game, Entity* second_obj, Animation& pickup_animation);

	void RandomGenerateNewAsteroid(Game& game);

	void UpdateEntities(Game& game);
	void UpdateDeltaTime(Game& game);
	void UpdateGame(Game& game, sf::RenderWindow& window);
	void UpdateMousePosition(Game& game, sf::RenderWindow& window);
	void UpdatePlayerScore(Game& game, const int& score);

	void DrawCooldownText(Game& game, sf::RenderWindow& window);
	void DrawMainMenu(Game& game, sf::RenderWindow& window);
	void DrawGame(Game& game, sf::RenderWindow& window);
	void DrawGameOver(Game& game, sf::RenderWindow& window);
};
