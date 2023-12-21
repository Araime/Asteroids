#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Animation.h"
#include "Entity.h"
#include "Laser.h"
#include "Asteroid.h"
#include "Ship.h"
#include "Math.h"

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
		int asteroid_num = 12;

		// init BG
		sf::Texture bgTexture;

		// init game textures
		sf::Texture shipTexture;
		sf::Texture laserTexture;
		sf::Texture rockTexture;
		sf::Texture smallRockTexture;
		sf::Texture explosionTexture1;
		sf::Texture explosionTexture2;

		// init all objects of animations
		Animation sLaser;
		Animation sAsteroidExplosion;
		Animation sShipExplosion;
		Animation sRock;
		Animation sRockSmall;
		Animation sShip;
		Animation sFlyingShip;

		// init BG sprite
		sf::Sprite sBG;

		// create list of all objects
		std::list<Entity*> entities;

		// init player ship
		Ship* player = new Ship;
	};

	void InitGame(Game& game);

	void MakeShot(Game& game);

	void HandlePlayerInput(Game& game, const float& currentTime, float& lastTime);

	void CheckAllCollisions(Game& game, const float& currentTime, float& lastTime);

	void CreateExplosionAnimation(Game& game, Entity* first_obj, Animation& expl_animation);

	void CreateSmallAsteroids(Game& game, Entity* first_obj);

	void CreateAsteroid(Game& game);

	void RandomGenerateNewAsteroid(Game& game);

	void UpdateEntities(Game& game);

	void Check—ompletedAnimations(Game& game);

	void UpdateGame(Game& game, sf::RenderWindow& window, const float& currentTime, float& lastTime);

	void DrawGame(Game& game, sf::RenderWindow& window);
}