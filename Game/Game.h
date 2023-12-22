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
		GameState gameState = GameState::Game;

		// set ateroid num
		int asteroids_num = 12;

		// init cooldown timer and text
		int destroy_cooldown = 3;
		std::string cooldownText = "Get Ready\n\t\t\t";

		// create font
		sf::Font font;
		
		// create text
		sf::Text text;

		// create BG
		sf::Texture bgTexture;

		// create sounds and music
		Sound timerSnd;
		Sound laserSnd1;
		Sound laserSnd2;
		Sound laserSnd3;
		Sound laserSnd4;

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

		// create BG sprite
		sf::Sprite sBG;

		// create list of all objects
		std::list<Entity*> entities;

		// create player ship
		Ship* player = new Ship;
	};

	void InitGame(Game& game);

	void MakeShot(Game& game);

	void HandlePlayerInput(Game& game, const float& currentTime, float& lastTime);

	void CheckAllCollisions(Game& game, const float& currentTime, float& lastTime);

	void CheckCollisionAsteroidAndLaser(Game& game, Entity* first_obj, Entity* second_obj);

	void CheckCollisionPlayerAndAsteroid(Game& game, Entity* first_obj, Entity* second_obj,
										 const float& currentTime, float& lastTime);

	void CreateExplosionAnimation(Game& game, Entity* first_obj, Animation& expl_animation);

	void CreateSmallAsteroids(Game& game, Entity* first_obj);

	void CreateAsteroid(Game& game);

	void RandomGenerateNewAsteroid(Game& game);

	void UpdateEntities(Game& game);

	void Check—ompletedAnimations(Game& game);

	void UpdateGame(Game& game, sf::RenderWindow& window, const float& currentTime, float& lastTime);

	void DrawText(Game& game, sf::RenderWindow& window);

	void DrawGame(Game& game, sf::RenderWindow& window);
}