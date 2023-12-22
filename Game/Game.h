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
		int asteroids_num = 12;

		// create font
		sf::Font font;
		
		// create text
		sf::String Text;

		// create BG
		sf::Texture bgTexture;

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

	void DrawGame(Game& game, sf::RenderWindow& window);
}