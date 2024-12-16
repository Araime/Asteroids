#include "Game.h"
#include "Constants.h"
#include <cassert>

void Game::LoadFont(sf::Font& text, const std::string path)
{
	assert(text.loadFromFile(path));
}

void Game::LoadTexture(sf::Texture& object, const std::string path)
{
	assert(object.loadFromFile(path));
}

void Game::LoadSound(Sound& snd, const std::string path, float volume)
{
	assert(snd.buffer.loadFromFile(path));
	snd.sound.setBuffer(snd.buffer);

	if (volume) snd.sound.setVolume(volume);
}

void Game::InitGame(Game& game)
{
	// load fonts
	LoadFont(game.cooldownFont, FONT_PATH + "papyrus-pixel_1.ttf");
	LoadFont(game.titleFont, FONT_PATH + "DischargePro.ttf");
	LoadFont(game.UIFont, FONT_PATH + "accid___(Ru)_0.ttf");

	// init game texts
	game.cooldownText.InitText(game.cooldownFont, COOLDOWN_TEXT_SIZE, sf::Color::Cyan);
	game.cooldownText.UpdateText(game.cooldownStr + std::to_string(game.destroy_cooldown));
	game.bigText.InitText(game.titleFont, TITLE_TEXT_SIZE, sf::Color::Yellow);
	game.bigText.UpdateText(TITLE_TEXT);

	// init game buttons
	game.startButton.Init(titleFont, START_BTN_TXT, START_BTN_WIDTH, LEFT_BTN_XCOR, BTNS_YCOR);
	game.quitButton.Init(titleFont, QUIT_BTN_TXT, QUIT_BTN_WIDTH, RIGHT_BTN_XCOR, BTNS_YCOR);
	game.restartButton.Init(titleFont, RESTART_BTN_TXT, RESTART_BTN_WIDTH, LEFT_BTN_XCOR, BTNS_YCOR);

	// load game textures
	LoadTexture(game.shipTexture, IMG_PATH + "Spaceship.png");
	LoadTexture(game.flyingShipTexture, IMG_PATH + "Spaceship2.png");
	LoadTexture(game.shipLife, IMG_PATH + "MiniSpaceship.png");
	LoadTexture(game.explosionTexture1, IMG_PATH + "type_B.png");
	LoadTexture(game.explosionTexture2, IMG_PATH + "type_C.png");
	LoadTexture(game.rockTexture, IMG_PATH + "rock.png");
	LoadTexture(game.smallRockTexture, IMG_PATH + "rock_small.png");
	LoadTexture(game.laserTexture, IMG_PATH + "laser.png");
	LoadTexture(game.rocketTexture, IMG_PATH + "rocket.png");

	// load bg's textures
	LoadTexture(game.levelTexture, IMG_PATH + "Starfield.jpg");
	LoadTexture(game.menuTexture, IMG_PATH + "5438849.jpg");
	LoadTexture(game.gameOverTexture, IMG_PATH + "night-sky-glows.jpg");

	// enable smooth filter
	game.shipTexture.setSmooth(true);
	game.levelTexture.setSmooth(true);
	game.menuTexture.setSmooth(true);
	game.gameOverTexture.setSmooth(true);

	// init BG's sprites
	game.menuBG.InitBG(game.menuTexture);
	game.levelBG.InitBG(game.levelTexture);
	game.gameOverBG.InitBG(game.gameOverTexture);

	// init all objects of animations
	game.sLaser.SetAnimation(game.laserTexture, 0, 0, 32, 64, 16, 0.8f);
	game.sRocket.SetAnimation(game.rocketTexture, 0, 0, 16, 28, 5, 0.8f);
	game.sAsteroidExplosion.SetAnimation(game.explosionTexture1, 0, 0, 192, 192, 64, 1.2f);
	game.sShipExplosion.SetAnimation(game.explosionTexture2, 0, 0, 256, 256, 48, 0.5f);
	game.sRock.SetAnimation(game.rockTexture, 0, 0, 64, 64, 16, 0.2f);
	game.sRockSmall.SetAnimation(game.smallRockTexture, 0, 0, 64, 64, 16, 0.2f);
	game.sShip.SetAnimation(game.shipTexture, 0, 0, 62, 68, 1, 0.f);
	game.sFlyingShip.SetAnimation(game.flyingShipTexture, 0, 0, 62, 68, 1, 0.f);

	// load sounds
	LoadSound(game.timerSnd, SND_PATH + "magnet_start.wav");
	LoadSound(game.laserSnd1, SND_PATH + "laser1.wav");
	LoadSound(game.laserSnd2, SND_PATH + "laser2.wav");
	LoadSound(game.laserSnd3, SND_PATH + "laser3.wav");
	LoadSound(game.RocketSnd1, SND_PATH + "rocket_launch_1.wav");
	LoadSound(game.RocketSnd2, SND_PATH + "rocket_launch_2.wav");
	LoadSound(game.RocketSnd3, SND_PATH + "rocket_launch_3.wav");
	LoadSound(game.RocketSnd4, SND_PATH + "rocket_launch_4.wav");
	LoadSound(game.weapChangeSnd, SND_PATH + "Flashpoint001a.wav");
	LoadSound(game.asteroidExplSnd, SND_PATH + "boom2.wav", 75.f);
	LoadSound(game.shipExplSnd, SND_PATH + "boom9.wav");
	LoadSound(game.buttonHover, SND_PATH + "beep_03.ogg");
	LoadSound(game.buttonClick, SND_PATH + "terminal_09.ogg");

	// init laser and rocket snd arrays
	game.laserSndArray[0] = game.laserSnd1;
	game.laserSndArray[1] = game.laserSnd2;
	game.laserSndArray[2] = game.laserSnd3;

	game.rocketSndArray[0] = game.RocketSnd1;
	game.rocketSndArray[1] = game.RocketSnd2;
	game.rocketSndArray[2] = game.RocketSnd3;
	game.rocketSndArray[3] = game.RocketSnd4;

	game.gameMusic.PlayMusic(SND_PATH + "enchanted tiki 86.ogg");

	// add player ship to list of entities
	game.entities.push_back(game.player);

	// init UI
	game.UI.InitUI(game);
	game.UI.InitUIScore(game.UIFont, UI_TEXT_SIZE, sf::Color::Yellow);
	game.UI.UpdateUIScore(game.playerScore);

	// init ScoreTable
	game.scoreTable.InitScoreTable(game.playerScore, game.UIFont);

	// update past time
	game.pastTime = game.gameTimer.getElapsedTime().asSeconds();
}

void Game::DrawMainMenu(Game& game, sf::RenderWindow& window)
{
	game.menuBG.sprite.rotate(-0.2f);

	window.clear();

	window.draw(game.menuBG.sprite);
	window.draw(game.bigText.txt);

	UpdateMousePosition(game, window);

	game.startButton.Update(game, mousePos);
	game.quitButton.Update(game, mousePos);
	game.startButton.Draw(window);
	game.quitButton.Draw(window);

	// check if the button is pressed
	if (game.startButton.IsPressed())
	{
		game.RestartGame(game);
	}

	if (game.quitButton.IsPressed())
	{
		window.close();
	}

	window.display();
}

void Game::RestartGame(Game& game)
{
	// clear entities list
	for (auto iter = game.entities.begin(); iter != game.entities.end();)
	{
		Entity* entity = *iter;
		if (entity->name != "player")
		{
			iter = game.entities.erase(iter);
			delete entity;
		}
		else
		{
			++iter;
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

	float angle = 0.f;
	game.player->SetParams(game.sShip, static_cast<float>(SCREEN_WIDTH / 2),
		static_cast<float>(FIELD_HEIGHT / 2), angle, SHIP_RAD);
	game.player->deltaX = 0;
	game.player->deltaY = 0;
	game.player->isDestroyed = false;
	game.player->weapon = Weapon::Laser;
	game.playerScore = 0;

	game.gameMusic.PlayMusic(SND_PATH + "through space.ogg");

	// reset UI and GameState
	game.UI.UpdateUIHealthBar(game.player->health);
	game.UI.UpdateWeaponHighlighterPos(SELECT1_XCOR, SELECT_YCOR);
	game.UI.UpdateUIScore(game.playerScore);

	game.scoreTable.InitScoreTable(game.playerScore, game.UIFont);

	game.gameState = GameState::Game;
}

void Game::CheckAllCollisions(Game& game)
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

void Game::CheckAsteroidAndShotCollision(Game& game, Entity* first_obj, Entity* second_obj)
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

			UpdatePlayerScore(game, static_cast<int>(first_obj->rad));
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

			UpdatePlayerScore(game, static_cast<int>(first_obj->rad));
		}
	}
}

void Game::CheckCollisionPlayerAndAsteroid(Game& game, Entity* first_obj, Entity* second_obj)
{
	if (game.player->isDestroyed) return;

	if (first_obj->name == "player" && second_obj->name == "asteroid")
	{
		if (IsCollide(first_obj, second_obj))
		{
			game.player->TakeDamage(game, second_obj->rad);

			if (!game.player->health)
			{
				CreateExplosionAnimation(game, first_obj, game.sShipExplosion);

				game.scoreTable.UpdateScoreTable(game.playerScore);

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

void Game::CreateExplosionAnimation(Game& game, Entity* first_obj, Animation& expl_animation)
{
	// create new explosion
	Entity* explosion = new Entity();
	explosion->SetParams(expl_animation, first_obj->xcor, first_obj->ycor);
	explosion->name = "explosion";
	game.entities.push_back(explosion);
}

void Game::CheckGameOver(Game& game)
{
	// check if life is over
	if (game.player->ships)
	{
		// update cooldown ressurection time
		game.destroy_cooldown = 3;
		game.cooldownText.UpdateText(game.cooldownStr + std::to_string(game.destroy_cooldown));
	}
	else
	{
		// update text and game state
		game.bigText.UpdateText(GAME_OVER_TEXT);
		game.bigText.UpdatePosition(GO_TEXT_XCOR, GO_TEXT_YCOR);
		game.gameState = GameState::GameOver;

		game.gameMusic.PlayMusic(SND_PATH + "space.ogg");
	}
}

void Game::CreateSmallAsteroids(Game& game, Entity* first_obj)
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
		sm_asteroid->SetParams(game.sRockSmall, first_obj->xcor, first_obj->ycor,
			static_cast<float>(rand() % 360), SM_RAD);
		game.entities.push_back(sm_asteroid);
	}
}

void Game::CheckÑompletedAnimations(Game& game)
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

void Game::CreateAsteroid(Game& game)
{
	// create big asteroid
	Asteroid* asteroid = new Asteroid();

	float xcor = 0;
	float angle = static_cast<float>(rand() % 360);
	asteroid->SetParams(game.sRock, xcor, static_cast<float>(rand() % FIELD_HEIGHT), angle, BIG_RAD);
	game.entities.push_back(asteroid);
}

void Game::RandomGenerateNewAsteroid(Game& game)
{
	if (rand() % DIVIDER == 0)
	{
		CreateAsteroid(game);
	}
}

void Game::UpdateEntities(Game& game)
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
			++i;
		}
	}
}

void Game::UpdateGame(Game& game, sf::RenderWindow& window)
{
	// player's functions
	game.player->HandlePlayerInput(game);
	game.player->UpdateShipSprite(game);
	game.player->RestartPlayer(game);

	CheckAllCollisions(game);

	CheckÑompletedAnimations(game);

	RandomGenerateNewAsteroid(game);

	UpdateEntities(game);
}

void Game::DrawCooldownText(Game& game, sf::RenderWindow& window)
{
	if (game.player->isDestroyed)
	{
		window.draw(game.cooldownText.txt);
	}
}

void Game::DrawGame(Game& game, sf::RenderWindow& window)
{
	window.clear();
	window.draw(game.levelBG.sprite);

	for (auto& entity : game.entities)
	{
		// check if player is destroyed
		if (entity->name == "player" && game.player->isDestroyed) continue;

		entity->Draw(window);
	}

	DrawCooldownText(game, window);
	game.UI.DrawUI(game, window, game.UI.lifeX);

	window.display();
}

void Game::DrawGameOver(Game& game, sf::RenderWindow& window)
{
	game.newTime = game.gameTimer.getElapsedTime().asSeconds();

	window.clear();

	window.draw(game.gameOverBG.sprite);
	window.draw(game.bigText.txt);

	UpdateMousePosition(game, window);

	game.restartButton.Update(game, mousePos);
	game.quitButton.Update(game, mousePos);
	game.restartButton.Draw(window);
	game.quitButton.Draw(window);

	game.scoreTable.DrawScoreTable(window, SCORETABLE_XCOR, SCORETABLE_YCOR);

	// check if the button is pressed
	if (game.restartButton.IsPressed())
	{
		game.RestartGame(game);
	}

	if (game.quitButton.IsPressed())
	{
		window.close();
	}

	window.display();

	if (game.newTime - game.pastTime > GAME_OVER_COOLDOWN)
	{
		// update text and game state
		game.bigText.UpdateText(TITLE_TEXT);
		game.gameState = GameState::TitleScreen;

		game.gameMusic.PlayMusic(SND_PATH + "enchanted tiki 86.ogg");

		game.pastTime = game.newTime;
	}
}

void Game::UpdateMousePosition(Game& game, sf::RenderWindow& window)
{
	game.mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
}

void Game::UpdatePlayerScore(Game& game, const int& score)
{
	game.playerScore += score;
	game.UI.UpdateUIScore(game.playerScore);
}
