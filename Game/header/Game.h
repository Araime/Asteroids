#pragma once
// PCH.h : #include <SFML/Graphics.hpp>
// PCH.h : #include <list> && #include <string>
#include "PCH.h"
#include "Animation.h"
#include "Entity.h"
#include "Laser.h"
#include "Rocket.h"
#include "Asteroid.h"
#include "Ship.h"
#include "Math.h"
#include "Sound.h"
#include "Background.h"
#include "Text.h"
#include "UI.h"
//Added .h
#include "Input.h"
#include <SFML/Audio/Music.hpp>

enum class GameState
{
	Menu = 0,
	Game,
	GameOver
};

class Game
{
public:
	GameState gameState = GameState::Menu;

	// set ateroid num
	int asteroids_num = 5;

	// create cooldown timer value and text
	int destroy_cooldown = 3;
	std::string cooldownStr = "Get Ready\n\t\t\t";

	// create game timers
	sf::Clock gameTimer;
	float newTime = 0.f;
	float pastTime = 0.f;


	//Sound
	bool LoadSound(Sound& snd, const std::string& path, float volume = 0);


	// create fonts
	sf::Font cooldownFont;
	sf::Font titleFont;

	// create game texts
	Text cooldownText;
	Text bigText;
	Text smallText;

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
	//Player critical sound when HP is below a certain amount
	Sound playerCriticalSnd;
	//MUSIC PORTION START
	Music gameMusic;
	float previousVolume;
	//Music volume attrib	
	float volume;
   // To track the mute state
	bool isMuted = false; 
	//MUSIC PORTION END
	
	//Player Ship Mayday during -> Sound playerCriticalSnd;
	float flashTimer;
	sf::RectangleShape redFlash;
	bool isFlashing;



	// create laser and rocket snd arrays
	Sound laserSndArray[LASER_SND_QTY];
	Sound rocketSndArray[ROCKETS_SND_QTY];

	// create game textures
	sf::Texture shipTexture;
	sf::Texture laserTexture;
	sf::Texture rocketTexture;
	sf::Texture rockTexture;
	sf::Texture smallRockTexture;
	sf::Texture explosionTexture1;
	sf::Texture explosionTexture2;

	// create all objects of animations
	Animation sLaser;
	Animation sRocket;
	Animation sAsteroidExplosion;
	Animation sShipExplosion;
	Animation sRock;
	Animation sRockSmall;
	Animation sShip;
	Animation sFlyingShip;

	// create list of all objects
	std::list<Entity*> entities;

	// create player ship
	Ship* player = new Ship;

	// create health bar rectangles
	UserInterface UI;

	void LoadFont(sf::Font& text, const std::string path);

	void LoadTexture(sf::Texture& object, const std::string path);

	//void LoadSound(Sound& snd, const std::string path, float volume = 0);

	void InitGame(Game& game);

	void DrawMainMenu(Game& game, sf::RenderWindow& window);

	void RestartGame(Game& game);

	void CheckAllCollisions(Game& game);

	void CheckAsteroidAndShotCollision(Game& game, Entity* first_obj, Entity* second_obj);

	void CheckCollisionPlayerAndAsteroid(Game& game, Entity* first_obj, Entity* second_obj);

	//
	void CheckAsteroidCollisions(Game& game);


	void CreateExplosionAnimation(Game& game, Entity* first_obj, Animation& expl_animation);

	void CheckGameOver(Game& game);

	void CreateSmallAsteroids(Game& game, Entity* first_obj);

	void CreateAsteroid(Game& game);

	void RandomGenerateNewAsteroid(Game& game);

	void UpdateEntities(Game& game);

	void Check—ompletedAnimations(Game& game);

	void UpdateGame(Game& game, sf::RenderWindow& window, const float& currentTime, float& lastTime);

	void DrawCooldownText(Game& game, sf::RenderWindow& window);

	void DrawGame(Game& game, sf::RenderWindow& window);

	void DrawGameOver(Game& game, sf::RenderWindow& window);
};