#include "Game.h"
#include "Constants.h"
#include <cassert>

namespace AsteroidsGame
{
	void InitGame(Game& game)
	{
		// load fonts
		assert(game.cooldownFont.loadFromFile(FONT_PATH + "papyrus-pixel_1.ttf"));
		assert(game.titleFont.loadFromFile(FONT_PATH + "DischargePro.ttf"));

		// init game texts
		InitText(game.cooldownText, game.cooldownFont, COOLDOWN_TEXT_SIZE, sf::Color::Cyan);
		UpdateText(game);
		InitText(game.bigText, game.titleFont, TITLE_TEXT_SIZE, sf::Color::Yellow);
		UpdateText(game.bigText, TITLE_TEXT);


		// load game textures
		assert(game.shipTexture.loadFromFile(IMG_PATH + "spaceship.png"));
		assert(game.explosionTexture1.loadFromFile(IMG_PATH + "type_B.png"));
		assert(game.explosionTexture2.loadFromFile(IMG_PATH + "type_C.png"));
		assert(game.rockTexture.loadFromFile(IMG_PATH + "rock.png"));
		assert(game.smallRockTexture.loadFromFile(IMG_PATH + "rock_small.png"));
		assert(game.laserTexture.loadFromFile(IMG_PATH + "laser.png"));
		assert(game.rocketTexture.loadFromFile(IMG_PATH + "rocket.png"));

		// load bg's textures
		assert(game.levelTexture.loadFromFile(IMG_PATH + "Starfield.jpg"));
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

		// init all objects of animations
		game.sLaser.SetAnimation(game.laserTexture, 0, 0, 32, 64, 16, 0.8f);
		game.sRocket.SetAnimation(game.rocketTexture, 0, 0, 16, 28, 5, 0.8f);
		game.sAsteroidExplosion.SetAnimation(game.explosionTexture1, 0, 0, 192, 192, 64, 1.2f);
		game.sShipExplosion.SetAnimation(game.explosionTexture2, 0, 0, 256, 256, 48, 0.5f);
		game.sRock.SetAnimation(game.rockTexture, 0, 0, 64, 64, 16, 0.2f);
		game.sRockSmall.SetAnimation(game.smallRockTexture, 0, 0, 64, 64, 16, 0.2f);
		game.sShip.SetAnimation(game.shipTexture, 40, 0, 40, 39, 1, 0.f);
		game.sFlyingShip.SetAnimation(game.shipTexture, 40, 86, 40, 40, 1, 0.f);

		// init sounds
		assert(game.timerSnd.buffer.loadFromFile(SND_PATH + "magnet_start.wav"));
		game.timerSnd.sound.setBuffer(game.timerSnd.buffer);

		assert(game.laserSnd1.buffer.loadFromFile(SND_PATH + "laser1.wav"));
		game.laserSnd1.sound.setBuffer(game.laserSnd1.buffer);

		assert(game.laserSnd2.buffer.loadFromFile(SND_PATH + "laser2.wav"));
		game.laserSnd2.sound.setBuffer(game.laserSnd2.buffer);

		assert(game.laserSnd3.buffer.loadFromFile(SND_PATH + "laser3.wav"));
		game.laserSnd3.sound.setBuffer(game.laserSnd3.buffer);

		assert(game.RocketSnd1.buffer.loadFromFile(SND_PATH + "rocket_launch_1.wav"));
		game.RocketSnd1.sound.setBuffer(game.RocketSnd1.buffer);

		assert(game.RocketSnd2.buffer.loadFromFile(SND_PATH + "rocket_launch_2.wav"));
		game.RocketSnd2.sound.setBuffer(game.RocketSnd2.buffer);

		assert(game.RocketSnd3.buffer.loadFromFile(SND_PATH + "rocket_launch_3.wav"));
		game.RocketSnd3.sound.setBuffer(game.RocketSnd3.buffer);

		assert(game.RocketSnd4.buffer.loadFromFile(SND_PATH + "rocket_launch_4.wav"));
		game.RocketSnd4.sound.setBuffer(game.RocketSnd4.buffer);

		assert(game.weapChangeSnd.buffer.loadFromFile(SND_PATH + "Flashpoint001a.wav"));
		game.weapChangeSnd.sound.setBuffer(game.weapChangeSnd.buffer);

		assert(game.asteroidExplSnd.buffer.loadFromFile(SND_PATH + "boom2.wav"));
		game.asteroidExplSnd.sound.setBuffer(game.asteroidExplSnd.buffer);
		game.asteroidExplSnd.sound.setVolume(75.f);

		assert(game.shipExplSnd.buffer.loadFromFile(SND_PATH + "boom9.wav"));
		game.shipExplSnd.sound.setBuffer(game.shipExplSnd.buffer);

		// init laser and rocket snd arrays
		game.laserSndArray[0] = game.laserSnd1;
		game.laserSndArray[1] = game.laserSnd2;
		game.laserSndArray[2] = game.laserSnd3;

		game.rocketSndArray[0] = game.RocketSnd1;
		game.rocketSndArray[1] = game.RocketSnd2;
		game.rocketSndArray[2] = game.RocketSnd3;
		game.rocketSndArray[3] = game.RocketSnd4;

		PlayMusic(game, SND_PATH + "enchanted tiki 86.ogg", 60.f);

		// add player ship to list of entities
		game.entities.push_back(game.player);

		InitUI(game);

		// update past time
		game.pastTime = game.gameTimer.getElapsedTime().asSeconds();
	}

	void PlayMusic(Game& game, std::string path, const float volume)
	{
		game.gameMusic.music.openFromFile(path);
		game.gameMusic.music.setVolume(volume);
		game.gameMusic.music.play();
	}

	void DrawMainMenu(Game& game, sf::RenderWindow& window)
	{
		game.menuBG.sprite.rotate(-0.2f);

		window.clear();
		window.draw(game.menuBG.sprite);
		window.draw(game.bigText.txt);
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
		game.player->SetParams(game.sShip, float(SCREEN_WIDTH / 2), float(FIELD_HEIGHT / 2), 0.f, SHIP_RAD);
		game.player->dx = 0;
		game.player->dy = 0;
		game.player->isDestroyed = false;
		game.player->weapon = Weapon::Laser;

		// update player health
		UpdateUI(game, game.player->health);
		PlayMusic(game, SND_PATH + "through space.ogg", 75.f);

		game.gameState = GameState::Game;
	}

	void CheckAllCollisions(Game& game)
	{
		for (auto& first_obj : game.entities)
		{
			for (auto& second_obj : game.entities)
			{
				CheckAsteroidAndShotCollision(game, first_obj, second_obj);
				CheckCollisionPlayerAndAsteroid(game, first_obj, second_obj);
			}
		}
	}

	void CheckAsteroidAndShotCollision(Game& game, Entity* first_obj, Entity* second_obj)
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

		if (first_obj->name == "asteroid" && second_obj->name == "rocket" && second_obj->isAlive)
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
					// update player health
					UpdateUI(game, game.player->health);

					if (!game.player->health)
					{
						CreateExplosionAnimation(game, first_obj, game.sShipExplosion);

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
			// update cooldown ressurection time
			game.destroy_cooldown = 3;
			UpdateText(game);
		}
		else
		{
			// update text and game state
			UpdateText(game.bigText, GAME_OVER_TEXT);
			game.gameState = GameState::GameOver;

			PlayMusic(game, SND_PATH + "space.ogg", 80.f);
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
			sm_asteroid->SetParams(game.sRockSmall, first_obj->xcor, first_obj->ycor, float(rand() % 360), SM_RAD);
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
		asteroid->SetParams(game.sRock, 0.f, float(rand() % FIELD_HEIGHT), float(rand() % 360), BIG_RAD);
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

	void DrawCooldownText(Game& game, sf::RenderWindow& window)
	{
		if (game.player->isDestroyed)
		{
			window.draw(game.cooldownText.txt);
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

		DrawCooldownText(game, window);
		DrawUI(game, window, game.UI.lifeX);
		
		window.display();
	}

	void DrawGameOver(Game& game, sf::RenderWindow& window)
	{
		game.newTime = game.gameTimer.getElapsedTime().asSeconds();

		window.clear();
		window.draw(game.gameOverBG.sprite);
		window.draw(game.bigText.txt);
		window.display();

		if (game.newTime - game.pastTime > GAME_OVER_COOLDOWN)
		{
			// update text and game state
			UpdateText(game.bigText, TITLE_TEXT);
			game.gameState = GameState::Menu;

			PlayMusic(game, SND_PATH + "enchanted tiki 86.ogg", 60.f);

			game.pastTime = game.newTime;
		}
	}
}