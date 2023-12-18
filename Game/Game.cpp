#include "Game.h"
#include "Constants.h"

namespace AsteroidsGame
{
	void InitGame(Game& game)
	{
		// load all textures
		game.shipTexture.loadFromFile(IMG_PATH + "spaceship.png");
		game.bgTexture.loadFromFile(IMG_PATH + "background2.jpg");
		game.explosionTexture1.loadFromFile(IMG_PATH + "type_B.png");
		game.explosionTexture2.loadFromFile(IMG_PATH + "type_C.png");
		game.rockTexture.loadFromFile(IMG_PATH + "rock.png");
		game.smallRockTexture.loadFromFile(IMG_PATH + "rock_small.png");
		game.laserTexture.loadFromFile(IMG_PATH + "fire_blue.png");

		// enable smooth filter
		game.shipTexture.setSmooth(true);
		game.bgTexture.setSmooth(true);

		// init BG sprite
		game.sBG.setTexture(game.bgTexture);

		// init all objects of animations
		game.sLaser.SetAnimation(game.laserTexture, 0, 0, 32, 64, 16, 0.8f);
		game.sAsteroidExplosion.SetAnimation(game.explosionTexture1, 0, 0, 192, 192, 64, 1.2f);
		game.sShipExplosion.SetAnimation(game.explosionTexture2, 0, 0, 256, 256, 48, 0.5f);
		game.sRock.SetAnimation(game.rockTexture, 0, 0, 64, 64, 16, 0.2f);
		game.sRockSmall.SetAnimation(game.smallRockTexture, 0, 0, 64, 64, 16, 0.2f);
		game.sShip.SetAnimation(game.shipTexture, 40, 0, 40, 40, 1, 0.f);
		game.sFlyingShip.SetAnimation(game.shipTexture, 40, 40, 40, 40, 1, 0.f);

		// create asteroids
		for (int i = 0; i < game.asteroid_num; i++)
		{
			CreateAsteroid(game);
		}

		game.player->SetParams(game.sShip, float(WIDTH / 2), float(HEIGHT / 2), 0.f, 20.f);
		game.entities.push_back(game.player);
	}

	void MakeShot(Game& game)
	{
		Laser* laser = new Laser();
		laser->SetParams(game.sLaser, game.player->xcor, game.player->ycor,
						 game.player->angle + float(rand() % 6 - 3), 10.f);
		game.entities.push_back(laser);
	}

	void HandlePlayerInput(Game& game, const float& currentTime, float& lastTime)
	{
		if (!game.player->isDestroyed)
		{
			// handle rotation
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				game.player->angle += 3.f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				game.player->angle -= 3.f;
			}

			// make shot
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				// check if enough time has passed
				if (currentTime - lastTime > LASER_COOLDOWN)
				{
					MakeShot(game);

					lastTime = currentTime;
				}
			}

			// check if ship is accelerated
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				game.player->isAccelerating = true;
			}
			else
			{
				game.player->isAccelerating = false;
			}
		}
	}

	void CheckAllCollisions(Game& game)
	{
		for (auto& first_obj : game.entities)
		{
			for (auto& second_obj : game.entities)
			{
				// check collision asteroid and laser
				if (first_obj->name == "asteroid" && second_obj->name == "laser")
				{
					if (IsCollide(first_obj, second_obj))
					{
						second_obj->isAlive = false;
						first_obj->isAlive = false;

						// create asteroid explosion animation
						CreateExplosionAnimation(game, first_obj, game.sAsteroidExplosion);

						CreateSmallAsteroids(game, first_obj);
					}
				}

				// check collision player and asteroid
				if (!game.player->isDestroyed)
				{
					if (first_obj->name == "player" && second_obj->name == "asteroid")
					{
						if (IsCollide(first_obj, second_obj))
						{
							second_obj->isAlive = false;

							// create ship explosion animation
							CreateExplosionAnimation(game, first_obj, game.sShipExplosion);

							// restart player ship
							game.player->SetParams(game.sShip, float(WIDTH / 2), float(HEIGHT / 2), 0.f, 20.f);
							game.player->dx = 0;
							game.player->dy = 0;
						}
					}
				}
			}
		}
	}

	void CreateExplosionAnimation(Game& game, Entity* first_obj, Animation& expl_animation)
	{
		Entity* explosion = new Entity();
		explosion->SetParams(expl_animation, first_obj->xcor, first_obj->ycor);
		explosion->name = "explosion";
		game.entities.push_back(explosion);
	}

	void CreateSmallAsteroids(Game& game, Entity* first_obj)
	{
		for (int i = 0; i < SM_ASTEROIDS; i++)
		{
			if (first_obj->rad == 15)
			{
				continue;
			}

			Asteroid* sm_asteroid = new Asteroid();
			sm_asteroid->SetParams(game.sRockSmall, first_obj->xcor, first_obj->ycor, float(rand() % 360), 15.f);
			game.entities.push_back(sm_asteroid);
		}
	}

	void CheckÑompletedAnimations(Game& game)
	{
		// delete completed animations
		for (auto entity : game.entities)
		{
			if (entity->name == "explosion")
			{
				if (entity->anim.IsAnimationEnd())
				{
					entity->isAlive = false;
				}
			}
		}
	}

	void CreateAsteroid(Game& game)
	{
		Asteroid* asteroid = new Asteroid();
		asteroid->SetParams(game.sRock, 0.f, float(rand() % HEIGHT), float(rand() % 360), 25.f);
		game.entities.push_back(asteroid);
	}

	void RandomGenerateNewAsteroid(Game& game)
	{
		if (rand() % 150 == 0)
		{
			CreateAsteroid(game);
		}
	}

	void UpdateEntities(Game& game)
	{
		// update all entities
		for (auto i = game.entities.begin(); i != game.entities.end();)
		{
			Entity* entity = *i;
			entity->Update();
			entity->anim.Update();

			// delete dead objects
			if (!entity->isAlive)
			{
				i = game.entities.erase(i);
				delete entity;
			}
			else
			{
				i++;
			}
		}
	}

	void UpdateGame(Game& game, sf::RenderWindow& window, const float& currentTime, float& lastTime)
	{
		HandlePlayerInput(game, currentTime, lastTime);

		UpdateShipSprite(game);

		CheckAllCollisions(game);

		CheckÑompletedAnimations(game);

		RandomGenerateNewAsteroid(game);

		UpdateEntities(game);
	}

	void DrawGame(Game& game, sf::RenderWindow& window)
	{
		window.draw(game.sBG);

		for (auto& entity : game.entities)
		{
			entity->Draw(window);
		}

		window.display();
	}
}