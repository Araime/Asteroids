#include "Game.h"
#include "Constants.h"
#include <cassert>

namespace AsteroidsGame
{
	void InitGame(Game& game)
	{
		// init font
		game.font.loadFromFile(FONT_PATH + "papyrus-pixel_1.ttf");

		// init game text
		game.text.setFont(game.font);
		game.text.setCharacterSize(CHAR_SIZE);
		game.text.setStyle(sf::Text::Bold);
		game.text.setFillColor(sf::Color::Cyan);
		game.text.setString(game.cooldownText + std::to_string(game.destroy_cooldown));
		game.text.setPosition(COOLDOWN_X_COORD, COOLDOWN_Y_COORD);

		// load game textures
		assert(game.shipTexture.loadFromFile(IMG_PATH + "spaceship.png"));
		assert(game.explosionTexture1.loadFromFile(IMG_PATH + "type_B.png"));
		assert(game.explosionTexture2.loadFromFile(IMG_PATH + "type_C.png"));
		assert(game.rockTexture.loadFromFile(IMG_PATH + "rock.png"));
		assert(game.smallRockTexture.loadFromFile(IMG_PATH + "rock_small.png"));
		assert(game.laserTexture.loadFromFile(IMG_PATH + "fire_blue.png"));

		// load bg's textures
		assert(game.levelTexture.loadFromFile(IMG_PATH + "background2.jpg"));
		assert(game.menuTexture.loadFromFile(IMG_PATH + "5438849.jpg"));
		assert(game.gameOverTexture.loadFromFile(IMG_PATH + "night-sky-glows.jpg"));

		// enable smooth filter
		game.shipTexture.setSmooth(true);
		game.levelTexture.setSmooth(true);
		game.menuTexture.setSmooth(true);
		game.gameOverTexture.setSmooth(true);

		// init BG's sprites
		InitBG(game.menuBG, game.menuTexture);
		InitBG(game.levelBG, game.levelTexture);
		InitBG(game.gameOverBG, game.gameOverTexture);

		// init screen texts
		assert(game.tTitle.loadFromFile(IMG_PATH + "title.png"));
		game.sTitle.setTexture(game.tTitle);
		game.sTitle.setPosition(TITLE_X_COORD, TITLE_Y_COORD);
		assert(game.tGameOver.loadFromFile(IMG_PATH + "gameover.png"));
		game.sGameOver.setTexture(game.tGameOver);
		game.sGameOver.setPosition(TITLE_X_COORD, TITLE_Y_COORD);

		// init all objects of animations
		game.sLaser.SetAnimation(game.laserTexture, 0, 0, 32, 64, 16, 0.8f);
		game.sAsteroidExplosion.SetAnimation(game.explosionTexture1, 0, 0, 192, 192, 64, 1.2f);
		game.sShipExplosion.SetAnimation(game.explosionTexture2, 0, 0, 256, 256, 48, 0.5f);
		game.sRock.SetAnimation(game.rockTexture, 0, 0, 64, 64, 16, 0.2f);
		game.sRockSmall.SetAnimation(game.smallRockTexture, 0, 0, 64, 64, 16, 0.2f);
		game.sShip.SetAnimation(game.shipTexture, 40, 0, 40, 39, 1, 0.f);
		game.sFlyingShip.SetAnimation(game.shipTexture, 40, 86, 40, 40, 1, 0.f);

		// init sounds
		game.timerSnd.buffer.loadFromFile(SND_PATH + "magnet_start.wav");
		game.timerSnd.sound.setBuffer(game.timerSnd.buffer);

		game.laserSnd1.buffer.loadFromFile(SND_PATH + "laser1.wav");
		game.laserSnd1.sound.setBuffer(game.laserSnd1.buffer);

		game.laserSnd2.buffer.loadFromFile(SND_PATH + "laser2.wav");
		game.laserSnd2.sound.setBuffer(game.laserSnd2.buffer);

		game.laserSnd3.buffer.loadFromFile(SND_PATH + "laser3.wav");
		game.laserSnd3.sound.setBuffer(game.laserSnd3.buffer);

		game.asteroidExplSnd.buffer.loadFromFile(SND_PATH + "boom2.wav");
		game.asteroidExplSnd.sound.setBuffer(game.asteroidExplSnd.buffer);
		game.asteroidExplSnd.sound.setVolume(70.f);

		game.shipExplSnd.buffer.loadFromFile(SND_PATH + "boom9.wav");
		game.shipExplSnd.sound.setBuffer(game.shipExplSnd.buffer);

		// init laser snd array
		game.laserSndArray[0] = game.laserSnd1;
		game.laserSndArray[1] = game.laserSnd2;
		game.laserSndArray[2] = game.laserSnd3;

		// init music and play
		game.gameMusic.music.openFromFile(SND_PATH + "enchanted tiki 86.ogg");
		game.gameMusic.music.setVolume(60.f);
		game.gameMusic.music.play();

		// add player ship to list of entities
		game.entities.push_back(game.player);

		// init health bar
		game.healthBar.setSize(sf::Vector2f(100.f, 15.f));
		game.healthBar.setFillColor(sf::Color::Transparent);
		game.healthBar.setOutlineThickness(2.f);
		game.healthBar.setOutlineColor(sf::Color::White);
		game.healthBar.setPosition(30.f, 750.f);

		game.greenLine.setSize(sf::Vector2f(100.f, 15.f));
		game.greenLine.setFillColor(sf::Color::Green);
		game.greenLine.setPosition(30.f, 750.f);

		game.redLine.setSize(sf::Vector2f(100.f, 15.f));
		game.redLine.setFillColor(sf::Color::Red);
		game.redLine.setPosition(30.f, 750.f);

		// update past time
		game.pastTime = game.gameTimer.getElapsedTime().asSeconds();
	}

	void DrawMainMenu(Game& game, sf::RenderWindow& window)
	{
		game.menuBG.sprite.rotate(-0.2f);

		window.clear();

		window.draw(game.menuBG.sprite);
		window.draw(game.sTitle);

		window.display();

		HandlePlayerInput(game);
	}

	void RestartGame(Game& game)
	{
		// clear entities list
		for (auto i = game.entities.begin(); i != game.entities.end();)
		{
			Entity* entity = *i;
			if (entity->name != "player")
			{
				i = game.entities.erase(i);
				delete entity;
			}
			else
			{
				i++;
			}
		}

		// create asteroids
		for (int i = 0; i < game.asteroids_num; i++)
		{
			CreateAsteroid(game);
		}

		// restart player ship
		game.player->ships = 3;
		game.player->health = 100.f;
		game.player->SetParams(game.sShip, float(WIDTH / 2), float(HEIGHT / 2), 0.f, 20.f);
		game.player->dx = 0;
		game.player->dy = 0;

		// change music and play
		game.gameMusic.music.openFromFile(SND_PATH + "through space.ogg");
		game.gameMusic.music.setVolume(75);
		game.gameMusic.music.play();

		game.gameState = GameState::Game;
	}

	void MakeShot(Game& game)
	{
		// create new laser
		Laser* laser = new Laser();
		laser->SetParams(game.sLaser, game.player->xcor, game.player->ycor,
						 game.player->angle + float(rand() % 6 - 3), 10.f);
		game.entities.push_back(laser);

		// play random laser sound
		game.laserSndArray[rand() % LASER_SND_QTY].sound.play();
	}

	void CheckAllCollisions(Game& game)
	{
		for (auto& first_obj : game.entities)
		{
			for (auto& second_obj : game.entities)
			{
				CheckCollisionAsteroidAndLaser(game, first_obj, second_obj);
				CheckCollisionPlayerAndAsteroid(game, first_obj, second_obj);
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

				// play explosion sound
				game.asteroidExplSnd.sound.play();

				CreateSmallAsteroids(game, first_obj);
			}
		}
	}

	void CheckCollisionPlayerAndAsteroid(Game& game, Entity* first_obj, Entity* second_obj)
	{
		if (!game.player->isDestroyed)
		{
			if (first_obj->name == "player" && second_obj->name == "asteroid")
			{
				if (IsCollide(first_obj, second_obj))
				{
					TakeDamage(game, second_obj->rad);

					if (!game.player->health)
					{
						CreateExplosionAnimation(game, first_obj, game.sShipExplosion);

						game.shipExplSnd.sound.play();
						game.player->ships--;

						// update past time
						game.pastTime = game.gameTimer.getElapsedTime().asSeconds();
					}
					else
					{
						second_obj->isAlive = false;

						CreateExplosionAnimation(game, second_obj, game.sAsteroidExplosion);

						game.asteroidExplSnd.sound.play();
					}
					
					CheckGameOver(game);
				}
			}
		}
	}

	void CreateExplosionAnimation(Game& game, Entity* first_obj, Animation& expl_animation)
	{
		// create new explosion
		Entity* explosion = new Entity();
		explosion->SetParams(expl_animation, first_obj->xcor, first_obj->ycor);
		explosion->name = "explosion";
		game.entities.push_back(explosion);
	}

	void CheckGameOver(Game& game)
	{
		// check if life is over
		if (game.player->ships)
		{
			game.player->isDestroyed = true;

			// update cooldown ressurection time
			game.destroy_cooldown = 3;
			game.text.setString(game.cooldownText + std::to_string(game.destroy_cooldown));
		}
		else
		{
			game.gameState = GameState::GameOver;

			// change music and play
			game.gameMusic.music.openFromFile(SND_PATH + "space.ogg");
			game.gameMusic.music.setVolume(80);
			game.gameMusic.music.play();
		}
	}

	void CreateSmallAsteroids(Game& game, Entity* first_obj)
	{
		for (int i = 0; i < SM_ASTEROIDS; i++)
		{
			// check that the exploded asteroid is not small
			if (first_obj->rad == 15)
			{
				continue;
			}

			// create small asteroids
			Asteroid* sm_asteroid = new Asteroid();
			sm_asteroid->SetParams(game.sRockSmall, first_obj->xcor, first_obj->ycor, float(rand() % 360), 15.f);
			game.entities.push_back(sm_asteroid);
		}
	}

	void CheckÑompletedAnimations(Game& game)
	{
		// turn off completed explosions animations
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
		// create big asteroid
		Asteroid* asteroid = new Asteroid();
		asteroid->SetParams(game.sRock, 0.f, float(rand() % HEIGHT), float(rand() % 360), 25.f);
		game.entities.push_back(asteroid);
	}

	void RandomGenerateNewAsteroid(Game& game)
	{
		if (rand() % 175 == 0)
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

			// delete dead objects from entities
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
		HandlePlayerInput(game);

		UpdateShipSprite(game);

		RestartPlayer(game);

		CheckAllCollisions(game);

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
		window.clear();

		window.draw(game.levelBG.sprite);

		for (auto& entity : game.entities)
		{
			// check if player is destroyed
			if (entity->name == "player" && game.player->isDestroyed)
			{
				continue;
			}
			entity->Draw(window);
		}

		DrawText(game, window);

		window.draw(game.redLine);
		window.draw(game.greenLine);
		window.draw(game.healthBar);
		window.display();
	}

	void DrawGameOver(Game& game, sf::RenderWindow& window)
	{
		game.newTime = game.gameTimer.getElapsedTime().asSeconds();

		window.clear();

		window.draw(game.gameOverBG.sprite);
		window.draw(game.sGameOver);

		window.display();

		if (game.newTime - game.pastTime > GAME_OVER_COOLDOWN)
		{
			game.gameState = GameState::Menu;

			// change music and play
			game.gameMusic.music.openFromFile(SND_PATH + "enchanted tiki 86.ogg");
			game.gameMusic.music.setVolume(60.f);
			game.gameMusic.music.play();

			game.pastTime = game.newTime;
		}
	}
}