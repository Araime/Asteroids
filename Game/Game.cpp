#include "Game.h"
#include "Constants.h"

namespace AsteroidsGame
{
	void InitGame(Game& game)
	{
		// init font
		game.font.loadFromFile(FONT_PATH + "Boomboom.otf");

		// init game text
		game.text.setFont(game.font);
		game.text.setCharacterSize(CHAR_SIZE);
		game.text.setFillColor(sf::Color::Green);
		game.text.setString(game.cooldownText + std::to_string(game.destroy_cooldown));
		game.text.setPosition(COOLDOWN_X_COORD, COOLDOWN_Y_COORD);

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
		for (int i = 0; i < game.asteroids_num; i++)
		{
			CreateAsteroid(game);
		}

		// init player ship
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

	void CheckAllCollisions(Game& game, const float& currentTime, float& lastTime)
	{
		for (auto& first_obj : game.entities)
		{
			for (auto& second_obj : game.entities)
			{
				CheckCollisionAsteroidAndLaser(game, first_obj, second_obj);

				CheckCollisionPlayerAndAsteroid(game, first_obj, second_obj, currentTime, lastTime);
			}
		}
	}

	void CheckCollisionAsteroidAndLaser(Game& game, Entity* first_obj, Entity* second_obj)
	{
		if (first_obj->name == "asteroid" && second_obj->name == "laser" && second_obj->isAlive)
		{
			if (IsCollide(first_obj, second_obj))
			{
				second_obj->isAlive = false;
				first_obj->isAlive = false;

				CreateExplosionAnimation(game, first_obj, game.sAsteroidExplosion);

				CreateSmallAsteroids(game, first_obj);
			}
		}
	}

	void CheckCollisionPlayerAndAsteroid(Game& game, Entity* first_obj, Entity* second_obj,
										 const float& currentTime, float& lastTime)
	{
		if (!game.player->isDestroyed)
		{
			if (first_obj->name == "player" && second_obj->name == "asteroid")
			{
				if (IsCollide(first_obj, second_obj))
				{
					second_obj->isAlive = false;

					CreateExplosionAnimation(game, first_obj, game.sShipExplosion);

					game.player->isDestroyed = true;
					game.destroy_cooldown = 3;
					game.text.setString(game.cooldownText + std::to_string(game.destroy_cooldown));
					lastTime = currentTime;
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

		RestartPlayer(game, currentTime, lastTime);

		CheckAllCollisions(game, currentTime, lastTime);

		CheckÑompletedAnimations(game);

		RandomGenerateNewAsteroid(game);

		UpdateEntities(game);
	}

	void DrawText(Game& game, sf::RenderWindow& window)
	{
		if (game.player->isDestroyed)
		{
			window.draw(game.text);
		}
	}

	void DrawGame(Game& game, sf::RenderWindow& window)
	{
		window.draw(game.sBG);

		for (auto& entity : game.entities)
		{
			if (entity->name == "player" && game.player->isDestroyed)
			{
				continue;
			}
			entity->Draw(window);
		}

		DrawText(game, window);

		window.display();
	}
}