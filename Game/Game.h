#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Animation.h"
#include "Entity.h"
#include "Laser.h"
#include "Asteroid.h"
#include "Ship.h"
#include "Math.h"
#include "Sound.h"
#include "Background.h"

namespace AsteroidsGame
{
	enum class GameState
	{
		Menu = 0,
		Game,
		GameOver
	};

	struct Game
	{
		GameState gameState = GameState::Menu;

		// set ateroid num
		int asteroids_num = 12;

		// create cooldown timer value and text
		int destroy_cooldown = 3;
		std::string cooldownText = "Get Ready\n\t\t\t";

		// create game timers
		sf::Clock gameTimer;
		float newTime = 0.f;
		float pastTime = 0.f;

		// create font
		sf::Font font;
		
		// create text
		sf::Text text;

		// create BG's
		BG menuBG;
		BG levelBG;
		BG gameOverBG;
		sf::Texture menuTexture;
		sf::Texture levelTexture;
		sf::Texture gameOverTexture;

		// create screen texts
		sf::Texture tTitle;
		sf::Texture tGameOver;
		sf::Sprite sTitle;
		sf::Sprite sGameOver;

		// create sounds and music
		Sound timerSnd;
		Sound laserSnd1;
		Sound laserSnd2;
		Sound laserSnd3;
		Sound asteroidExplSnd;
		Sound shipExplSnd;

		Music gameMusic;

		// create laser snd array
		Sound laserSndArray[LASER_SND_QTY];

		// create game textures
		sf::Texture shipTexture;
		sf::Texture laserTexture;
		sf::Texture rockTexture;
		sf::Texture smallRockTexture;
		sf::Texture explosionTexture1;
		sf::Texture explosionTexture2;

		// create all objects of animations
		Animation sLaser;
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

		// create health bar
		sf::RectangleShape healthBar;
		sf::RectangleShape greenLine;
		sf::RectangleShape redLine;
	};

	void InitGame(Game& game);

	void DrawMainMenu(Game& game, sf::RenderWindow& window);

	void RestartGame(Game& game);

	void MakeShot(Game& game);

	void CheckAllCollisions(Game& game);

	void CheckCollisionAsteroidAndLaser(Game& game, Entity* first_obj, Entity* second_obj);

	void CheckCollisionPlayerAndAsteroid(Game& game, Entity* first_obj, Entity* second_obj);

	void CreateExplosionAnimation(Game& game, Entity* first_obj, Animation& expl_animation);

	void UpdateHealhBar(Game& game, const float health);

	void CheckGameOver(Game& game);

	void CreateSmallAsteroids(Game& game, Entity* first_obj);

	void CreateAsteroid(Game& game);

	void RandomGenerateNewAsteroid(Game& game);

	void UpdateEntities(Game& game);

	void Check—ompletedAnimations(Game& game);

	void UpdateGame(Game& game, sf::RenderWindow& window, const float& currentTime, float& lastTime);

	void DrawText(Game& game, sf::RenderWindow& window);

	void DrawGame(Game& game, sf::RenderWindow& window);

	void DrawGameOver(Game& game, sf::RenderWindow& window);
}