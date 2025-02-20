#include "Game.h"

#include <cassert>

#include "Constants.h"

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
	LoadTexture(game.laserPickup, IMG_PATH + "Laser_Pickup.png");
	LoadTexture(game.healthPickup, IMG_PATH + "Health_Pickup.png");
	LoadTexture(game.rocketPickup, IMG_PATH + "Rocket_Pickup.png");
	LoadTexture(game.shieldPickup, IMG_PATH + "Armor_Pickup.png");
	LoadTexture(game.pickupEffectTexture, IMG_PATH + "PickupEffect.png");
	LoadTexture(game.shieldEffectTexture, IMG_PATH + "shield.png");
	LoadTexture(game.powerLevelTexture, IMG_PATH + "powerupYellow.png");

	// load bg's textures
	LoadTexture(game.levelTexture, IMG_PATH + "bg.jpg");
	LoadTexture(game.gameOverTexture, IMG_PATH + "gameover.jpg");
	LoadTexture(game.menuTexture, IMG_PATH + "titlescreen.png");

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
	game.sLaserPickup.SetAnimation(game.laserPickup, 0, 0, 50, 50, 1, 0.f);
	game.sHealthPickup.SetAnimation(game.healthPickup, 0, 0, 50, 50, 1, 0.f);
	game.sRocketPickup.SetAnimation(game.rocketPickup, 0, 0, 50, 50, 1, 0.f);
	game.sShieldPickup.SetAnimation(game.shieldPickup, 0, 0, 50, 50, 1, 0.f);
	game.sPickupEffect.SetAnimation(game.pickupEffectTexture, 0, 0, 100, 100, 30, 1.f);
	game.sShieldEffect.SetAnimation(game.shieldEffectTexture, 0, 0, 72, 72, 8, 0.25f);

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
	LoadSound(game.healthPickupSnd, SND_PATH + "misc_03.mp3");
	LoadSound(game.laserPickupSnd, SND_PATH + "weird_02.mp3", 75.f);
	LoadSound(game.rocketPickupSnd, SND_PATH + "retro_beep_04.mp3");
	LoadSound(game.shieldPickupSnd, SND_PATH + "teleport_02.mp3");

	// load pickup voices
	LoadSound(game.laserPickupVoice, SND_PATH + "laser_pickup.wav");
	LoadSound(game.rocketPickupVoice, SND_PATH + "rocket_pickup.wav");
	LoadSound(game.healthPickupVoice, SND_PATH + "health_pickup.wav");
	LoadSound(game.shieldPickupVoice, SND_PATH + "shield_pickup.wav");

	// init laser and rocket snd arrays
	game.laserSndArray[0] = game.laserSnd1;
	game.laserSndArray[1] = game.laserSnd2;
	game.laserSndArray[2] = game.laserSnd3;

	game.rocketSndArray[0] = game.RocketSnd1;
	game.rocketSndArray[1] = game.RocketSnd2;
	game.rocketSndArray[2] = game.RocketSnd3;
	game.rocketSndArray[3] = game.RocketSnd4;

	game.gameMusic.PlayMusic(SND_PATH + "enchanted tiki 86.ogg");

	// init UI
	game.UI.InitUI(game);
	game.UI.InitUIScore(game.UIFont, UI_TEXT_SIZE, sf::Color::Yellow);
	game.UI.UpdateUIScore(game.playerScore);

	// init ScoreTable
	game.scoreTable.InitScoreTable(game.UIFont);

	// update past time
	game.pastTime = game.gameTimer.getElapsedTime().asSeconds();
}

void Game::RestartGame(Game& game)
{
	// clear the list of entities
	for (auto iter = game.entities.begin(); iter != game.entities.end();)
	{
		Entity* entity = *iter;
		iter = game.entities.erase(iter);
		delete entity;
	}

	// create the player ship and add to the list of entities
	game.player = new Ship;
	game.entities.push_back(game.player);
	game.player->ResetPlayerParams(game);

	// create asteroids
	for (int i = 0; i < game.asteroids_num; i++)
	{
		CreateAsteroid(game);
	}

	// reset UI and GameState
	game.playerScore = 0;
	game.UI.UpdateUIHealthBar(game.player->health);
	game.UI.UpdateWeaponHighlighterPos(SELECT1_XCOR, SELECT_YCOR);
	game.UI.UpdateUIScore(game.playerScore);

	game.scoreTable.InitScoreTable(game.UIFont);

	game.gameMusic.PlayMusic(SND_PATH + "through space.ogg");

	game.gameState = GameState::Game;
}

void Game::CheckAllCollisions(Game& game)
{
	for (auto& first_obj : game.entities)
	{
		for (auto& second_obj : game.entities)
		{
			// if the name of the first object is a "player" and the second is an "asteroid"
			if (first_obj->name == "player")
			{
				if (second_obj->name == "asteroid")
				{
					CheckCollisionPlayerAndAsteroid(game, first_obj, second_obj);
				}

				// check collision player with pickup
				if (second_obj->name == "pickup" && second_obj->isAlive)
				{
					CheckCollisionPlayerAndPickup(game, first_obj, second_obj);
				}
			}

			/* if the name of the first object is a "asteroid" and the second is an "laser" or "rocket"
			and the second object is alive*/
			if (first_obj->name == "asteroid")
			{
				if (second_obj->name == "laser" && second_obj->isAlive || second_obj->name == "rocket" && second_obj->isAlive)
				{
					CheckAsteroidAndShotCollision(game, first_obj, second_obj);
				}
			}
		}
	}
}

void Game::CheckAsteroidAndShotCollision(Game& game, Entity* first_obj, Entity* second_obj)
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

		if ((rand() % 10 + 1) > 9)
		{
			CreateRandomPickup(game, second_obj);
		}
	}
}

void Game::CheckCollisionPlayerAndAsteroid(Game& game, Entity* first_obj, Entity* second_obj)
{
	if (game.player->isDestroyed) return;

	if (IsCollide(first_obj, second_obj))
	{
		game.player->TakeDamage(game, second_obj->rad);

		if (!game.player->health)
		{
			CreateExplosionAnimation(game, first_obj, game.sShipExplosion);

			game.scoreTable.UpdateScoreTable(game.playerScore);

			// update past time
			game.pastTime = game.gameTimer.getElapsedTime().asSeconds();

			// update cooldown ressurection time
			game.destroy_cooldown = DESTROY_COOLDOWN;

			if (game.player->ships == 1) // if the player no longer has any ships
			{
				game.cooldownText.UpdateText(game.gameoverStr);
				game.gameMusic.PlayMusic(SND_PATH + "space.ogg");
			}
			else
			{
				game.cooldownText.UpdateText(game.cooldownStr + std::to_string(game.destroy_cooldown));
			}
		}
		else
		{
			second_obj->isAlive = false;

			CreateExplosionAnimation(game, second_obj, game.sAsteroidExplosion);

			game.asteroidExplSnd.sound.play();
		}
	}
}

void Game::CheckCollisionPlayerAndPickup(Game& game, Entity* first_obj, Entity* second_obj)
{
	if (game.player->isDestroyed) return;

	if (IsCollide(first_obj, second_obj))
	{
		second_obj->ApplyEffect(game);
		second_obj->isAlive = false;

		CreatePickupEffectAnimation(game, second_obj, game.sPickupEffect);
	}
}

void Game::GameOver(Game& game)
{
	// update text and game state
	game.bigText.UpdateText(GAME_OVER_TEXT);
	game.bigText.UpdatePosition(GO_TEXT_XCOR, GO_TEXT_YCOR);
	game.gameState = GameState::GameOver;
}

void Game::CheckÑompletedAnimations(Game& game)
{
	// turn off completed explosions animations
	for (auto entity : game.entities)
	{
		if (entity->name == "explosion" || entity->name == "pickupEffect")
		{
			if (entity->anim.IsAnimationEnd())
			{
				entity->isAlive = false;
			}
		}
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

void Game::CreateAsteroid(Game& game)
{
	// create big asteroid
	Asteroid* asteroid = new Asteroid();

	float xcor = 0;
	float angle = static_cast<float>(rand() % 360);
	asteroid->SetParams(game.sRock, xcor, static_cast<float>(rand() % FIELD_HEIGHT), angle, BIG_RAD);
	game.entities.push_back(asteroid);
}

void Game::CreateRandomPickup(Game& game, Entity* obj)
{
	// creating a random number that will be used to determine which bonus will appear
	int pickupNumber = rand() % 100 + 1;

	if (pickupNumber < 26)
	{
		HealthPickup* pickup = new HealthPickup();
		pickup->SetParams(sHealthPickup, obj->xcor, obj->ycor, -ADDITIONAL_ANGLE, PICKUP_RAD);
		game.entities.push_back(pickup);
	}
	else if (pickupNumber > 25 && pickupNumber < 51)
	{
		ShieldPickup* pickup = new ShieldPickup();
		pickup->SetParams(sShieldPickup, obj->xcor, obj->ycor, -ADDITIONAL_ANGLE, PICKUP_RAD);
		game.entities.push_back(pickup);
	}
	else if (pickupNumber > 50 && pickupNumber < 76)
	{
		LaserPickup* pickup = new LaserPickup();
		pickup->SetParams(sLaserPickup, obj->xcor, obj->ycor, -ADDITIONAL_ANGLE, PICKUP_RAD);
		game.entities.push_back(pickup);
	}
	else if (pickupNumber > 75 && pickupNumber <= 100)
	{
		RocketPickup* pickup = new RocketPickup();
		pickup->SetParams(sRocketPickup, obj->xcor, obj->ycor, -ADDITIONAL_ANGLE, PICKUP_RAD);
		game.entities.push_back(pickup);
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

void Game::CreatePickupEffectAnimation(Game& game, Entity* second_obj, Animation& pickup_animation)
{
	// create pickup effect
	Entity* pickupEffect = new Entity();
	pickupEffect->SetParams(pickup_animation, second_obj->xcor, second_obj->ycor);
	pickupEffect->name = "pickupEffect";
	game.entities.push_back(pickupEffect);
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
		entity->Update(game.deltaTime);
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

void Game::UpdateDeltaTime(Game& game)
{
	game.deltaTime = game.Clock.restart().asSeconds();
}

void Game::UpdateGame(Game& game, sf::RenderWindow& window)
{
	UpdateDeltaTime(game);

	// player's functions
	game.player->HandlePlayerInput(game, game.deltaTime);
	game.player->UpdateShipSprite(game);
	game.player->HandlePlayerRessurection(game);

	if (game.player->isProtected)
	{
		game.player->UpdateShield(game, deltaTime);
	}

	if (!game.player->ships)
	{
		GameOver(game);
	}

	CheckAllCollisions(game);

	CheckÑompletedAnimations(game);

	RandomGenerateNewAsteroid(game);

	UpdateEntities(game);
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

void Game::DrawCooldownText(Game& game, sf::RenderWindow& window)
{
	if (game.player->isDestroyed)
	{
		window.draw(game.cooldownText.txt);
	}
}

void Game::DrawMainMenu(Game& game, sf::RenderWindow& window)
{
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

	if (game.player->isProtected)
	{
		game.player->DrawShieldSprite(window);
	}

	DrawCooldownText(game, window);
	game.UI.DrawUI(game, window);

	window.display();
}

void Game::DrawGameOver(Game& game, sf::RenderWindow& window)
{
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
}
