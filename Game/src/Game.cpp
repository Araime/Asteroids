#include "../header/Game.h"
#include "../header/Constants.h"
#include "../header/Input.h"
#include <cassert>
#include <iostream>

void Game::LoadFont(sf::Font& text, const std::string path)
{
	assert(text.loadFromFile(path));
}

void Game::LoadTexture(sf::Texture& object, const std::string path)
{
	assert(object.loadFromFile(path));
}

bool Game::LoadSound(Sound& snd, const std::string& path, float volume) {
	if (!snd.buffer.loadFromFile(path)) {
		// Handle the error, for example, log it and return false
		std::cerr << "Failed to load sound file: " << path << std::endl;
		return false;
	}
	snd.sound.setBuffer(snd.buffer);
	if (volume) {
		snd.sound.setVolume(volume);
	}
	return true;
}


void Game::InitGame(Game& game)
{
	// load fonts
	LoadFont(game.cooldownFont, FONT_PATH + "papyrus-pixel_1.ttf");
	LoadFont(game.titleFont, FONT_PATH + "DischargePro.ttf");

	// init game texts
	game.cooldownText.InitText(game.cooldownFont, COOLDOWN_TEXT_SIZE, sf::Color::Cyan);
	game.cooldownText.UpdateText(game.cooldownStr + std::to_string(game.destroy_cooldown));
	game.bigText.InitText(game.titleFont, TITLE_TEXT_SIZE, sf::Color::Yellow);
	game.bigText.UpdateText(TITLE_TEXT);


	// load game textures
	LoadTexture(game.shipTexture, IMG_PATH + "spaceship.png");
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
	game.sShip.SetAnimation(game.shipTexture, 40, 0, 40, 39, 1, 0.f);
	game.sFlyingShip.SetAnimation(game.shipTexture, 40, 86, 40, 40, 1, 0.f);

	// load sounds
	//LoadSound(game.timerSnd, SND_PATH + "magnet_start.wav");
	LoadSound(game.timerSnd, SND_PATH + "Timer/magnet_start.wav");
	LoadSound(game.laserSnd1, SND_PATH + "Projectiles/Laser_launch/laser1.wav");
	LoadSound(game.laserSnd2, SND_PATH + "Projectiles/Laser_launch/laser2.wav");
	LoadSound(game.laserSnd3, SND_PATH + "Projectiles/Laser_launch/laser3.wav");
	LoadSound(game.RocketSnd1, SND_PATH + "Projectiles/Rocket_launch/rocket_launch_1.wav");
	LoadSound(game.RocketSnd2, SND_PATH + "Projectiles/Rocket_launch/rocket_launch_2.wav");
	LoadSound(game.RocketSnd3, SND_PATH + "Projectiles/Rocket_launch/rocket_launch_3.wav");
	LoadSound(game.RocketSnd4, SND_PATH + "Projectiles/Rocket_launch/rocket_launch_4.wav");
	//Changing Weapons
	LoadSound(game.weapChangeSnd, SND_PATH + "Flashpoint001a.wav");
	LoadSound(game.asteroidExplSnd, SND_PATH + "Explosion/boom2.wav", 75.f);
	LoadSound(game.shipExplSnd, SND_PATH + "Explosion/boom9.wav");

	//Player Critical HP sound when below certain amount 
	bool loaded = LoadSound(game.playerCriticalSnd, SND_PATH + "Player_critical_damage_warning/Player_critical.wav", 50.f);
	//
	game.previousVolume = game.gameMusic.music.getVolume();

	//Player Ship Mayday
	 // Initialize the red flash rectangle
	game.redFlash.setSize(sf::Vector2f(static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT)));
	game.redFlash.setFillColor(sf::Color(255, 0, 0, 0)); // Start as fully transparent
	game.flashTimer = 0.0f; // Start the timer at 0


	// init laser and rocket snd arrays
	game.laserSndArray[0] = game.laserSnd1;
	game.laserSndArray[1] = game.laserSnd2;
	game.laserSndArray[2] = game.laserSnd3;

	game.rocketSndArray[0] = game.RocketSnd1;
	game.rocketSndArray[1] = game.RocketSnd2;
	game.rocketSndArray[2] = game.RocketSnd3;
	game.rocketSndArray[3] = game.RocketSnd4;

	game.gameMusic.PlayMusic(SND_PATH + "Main_menu_theme/enchanted tiki 86.ogg");

	// add player ship to list of entities
	game.entities.push_back(game.player);

	game.UI.InitUI(game);

	// update past time
	game.pastTime = game.gameTimer.getElapsedTime().asSeconds();
}

//Draw Main Menu 
void Game::DrawMainMenu(Game& game, sf::RenderWindow& window)
{
	game.menuBG.sprite.rotate(-0.2f);

	window.clear();
	window.draw(game.menuBG.sprite);
	window.draw(game.bigText.txt);
	window.display();

	game.player->HandlePlayerInput(game);
}
//Restart Game
void Game::RestartGame(Game& game)
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
			++i;
		}

		// Reset pastTime when the game restarts
		//game.pastTime = game.gameTimer.getElapsedTime().asSeconds();
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
	game.player->dx = 0;
	game.player->dy = 0;
	game.player->isDestroyed = false;
	game.player->weapon = Weapon::Laser;

	game.UI.UpdateUIHealthBar(game.player->health);

	game.gameMusic.PlayMusic(SND_PATH + "Background_music/through space.ogg");
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
// Check if player "laser" shot & asteroid collide, begin process
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
			//Spawn small asteroid 
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
			//Spawn small asteroid 
			CreateSmallAsteroids(game, first_obj);
		}
	}
}
//GAME COLLISION
void Game::CheckCollisionPlayerAndAsteroid(Game& game, Entity* first_obj, Entity* second_obj) {
	if (game.player->isDestroyed) return;

	if (first_obj->name == "player" && second_obj->name == "asteroid") {
		if (IsCollide(first_obj, second_obj)) {
			game.player->TakeDamage(game, second_obj->rad);

			if (!game.player->health) {
				CreateExplosionAnimation(game, first_obj, game.sShipExplosion);

				// Reset the pastTime to the current time to restart the survival timer
				//game.pastTime = game.gameTimer.getElapsedTime().asSeconds();

				// Player is now destroyed
				game.player->isDestroyed = true;
			}
			else {
				second_obj->isAlive = false;
				CreateExplosionAnimation(game, second_obj, game.sAsteroidExplosion);
				game.asteroidExplSnd.sound.play();
			}

			CheckGameOver(game);
		}
	}
}
// If Asteroid collide with one another , act same as if player shot/killed them via laser or rocket
// Semi-dynamic environment
void Game::CheckAsteroidCollisions(Game& game) {
	std::vector<Entity*> asteroidsToSplit;

	// Check for collisions between asteroids
	for (auto it1 = game.entities.begin(); it1 != game.entities.end(); ++it1) {
		for (auto it2 = std::next(it1); it2 != game.entities.end(); ++it2) {
			Entity* entity1 = *it1;
			Entity* entity2 = *it2;

			// Skip if any of the entities are not asteroids or already marked as not alive
			if (entity1->name != "asteroid" || entity2->name != "asteroid" || !entity1->isAlive || !entity2->isAlive) {
				continue;
			}

			if (IsCollide(entity1, entity2)) {
				entity1->isAlive = false;
				entity2->isAlive = false;

				CreateExplosionAnimation(game, entity1, game.sAsteroidExplosion);
				CreateExplosionAnimation(game, entity2, game.sAsteroidExplosion);

				// Queue asteroids to be split into smaller ones
				if (entity1->rad != SM_RAD) {
					asteroidsToSplit.push_back(entity1);
				}
				if (entity2->rad != SM_RAD) {
					asteroidsToSplit.push_back(entity2);
				}

				game.asteroidExplSnd.sound.play();
			}
		}
	}

	// Remove the exploded asteroids from the main list first to avoid invalid iterator issues
	game.entities.remove_if([](Entity* entity) { return !entity->isAlive; });

	// Then create small asteroids from the ones marked for splitting
	for (Entity* asteroid : asteroidsToSplit) {
		CreateSmallAsteroids(game, asteroid);
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
		game.gameState = GameState::GameOver;

		game.gameMusic.PlayMusic(SND_PATH + "Background_music/space.ogg");
	}
}
// Spawn small asteroid
void Game::CreateSmallAsteroids(Game& game, Entity* first_obj)
{
    if (first_obj->rad != BIG_RAD) // Assuming BIG_RAD is the radius of large asteroids
    {
        return; // Only create small asteroids from large ones
    }

    float baseAngle = static_cast<float>(rand() % 360); // Random base angle for variation

    for (int i = 0; i < SM_ASTEROIDS; i++)
    {
        // create small asteroids
        Asteroid* sm_asteroid = new Asteroid();

        // Set angle for each small asteroid to spread out from the point of explosion
        float angle = baseAngle + i * (360.0f / SM_ASTEROIDS);

        sm_asteroid->SetParams(game.sRockSmall, first_obj->xcor, first_obj->ycor, angle, SM_RAD);
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
// Spawn Asteroid
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
// Game Update
void Game::UpdateGame(Game& game, sf::RenderWindow& window, const float& currentTime, float& lastTime)
{
	// player's functions
	game.player->HandlePlayerInput(game);
	game.player->UpdateShipSprite(game);
	game.player->RestartPlayer(game);

	CheckAllCollisions(game);
	//
	CheckAsteroidCollisions(game);

	CheckÑompletedAnimations(game);

	RandomGenerateNewAsteroid(game);

	UpdateEntities(game);

	// Update survival time text
	//- game.pastTime
	//How long the player has survived for, will freeze once died
	// Once player "revive" time will re-continue
	float survivalTime = game.gameTimer.getElapsedTime().asSeconds();
	int minutes = static_cast<int>(survivalTime) / 60;
	int seconds = static_cast<int>(survivalTime) % 60;
	std::string timeStr = std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);
	game.UI.survivalTimeText.UpdateText(timeStr);

	//Update survival time text End


// ALARM, If MAYDAY ( Yes ) for Critical Status Update
// Check player's health for critical sound and red flash effect
	if (game.player->health <= 50 && game.player->health > 0) {
		if (game.playerCriticalSnd.sound.getStatus() != sf::Sound::Playing) {
			game.playerCriticalSnd.sound.setLoop(true);
			game.playerCriticalSnd.sound.play();
			if (!game.isMuted) {
				game.previousVolume = game.gameMusic.music.getVolume();
				game.gameMusic.music.setVolume(0.f);
			}
		}
		game.isFlashing = true;
	}
	else {
		if (game.playerCriticalSnd.sound.getStatus() == sf::Sound::Playing) {
			game.playerCriticalSnd.sound.stop();
			if (!game.isMuted) {
				game.gameMusic.music.setVolume(game.previousVolume);
			}
		}
		game.isFlashing = false;
	}
	//MAYDAY Alarm Light : player's critical health
	// Handle the flashing effect with fade in and out
	if (game.isFlashing) {
		game.flashTimer += currentTime - lastTime;

		// Calculate the sine wave value over time, oscillating between 0 and 1
		float sineWave = (std::sin(game.flashTimer / flashDuration * 2 * 3.14159f) + 1) / 2;

		// Calculate alpha based on the sine wave, allowing for a smooth transition
		float alpha = sineWave * maxAlpha;

		// Apply the calculated alpha to the red flash color
		game.redFlash.setFillColor(sf::Color(255, 0, 0, static_cast<sf::Uint8>(alpha)));
	}
	else {
		// Ensure the red flash is fully transparent when not active
		game.redFlash.setFillColor(sf::Color(255, 0, 0, 0));
	}


// VOLUME MODIFY START
	// MUSIC CONTROL START
	// Check for volume increase
	if (Input::IsKeyPressed(Input::KEY::KEY_ADD)) {
		game.volume = std::min(game.volume + 5.f, 100.f); // Ensure the volume does not go above 100%
		game.gameMusic.music.setVolume(game.volume); // Use the 'music' object from your custom Music class
	}

	// Check for volume decrease
	if (Input::IsKeyPressed(Input::KEY::KEY_SUBTRACT)) {
		game.volume = std::max(game.volume - 5.f, 0.f); // Ensure the volume does not go below 0%
		game.gameMusic.music.setVolume(game.volume); // Use the 'music' object from your custom Music class
	}
	// Check for mute or unmute
	if (Input::IsKeyPressed(Input::KEY::Numpad8)) {
		if (!game.isMuted) {
			// Save the current volume before muting
			game.volume = game.gameMusic.music.getVolume();
			// Mute the music
			game.gameMusic.music.setVolume(0.f);
			game.isMuted = true;
		}
		else {
			// Unmute the music and restore the volume
			game.gameMusic.music.setVolume(game.volume);
			game.isMuted = false;
		}
	}

	//MUSIC CONTROL END
}
// VOLUME MODIFY END

void Game::DrawCooldownText(Game& game, sf::RenderWindow& window)
{
	if (game.player->isDestroyed)
	{
		window.draw(game.cooldownText.txt);
	}
}
// Game Draw
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
	
	// Draw Survival Timer
	if (!game.player->isDestroyed) {
		game.UI.survivalTimeText.txt.setPosition(TIMER_TEXT_X, TIMER_TEXT_Y);
		window.draw(game.UI.survivalTimeText.txt);
	}
	//Draw Survival Timer End

	DrawCooldownText(game, window);
	game.UI.DrawUI(game, window, game.UI.lifeX);

	

	// ALARM Draw the red flash if it's active START
	if (game.redFlash.getFillColor().a > 0) {
		window.draw(game.redFlash);
	}
	// ALARM Draw the red flash if it's active END
	window.display();
}

void Game::DrawGameOver(Game& game, sf::RenderWindow& window)
{
	game.newTime = game.gameTimer.getElapsedTime().asSeconds();

	window.clear();
	window.draw(game.gameOverBG.sprite);
	window.draw(game.bigText.txt);
	window.display();

	if (game.newTime - game.pastTime > GAME_OVER_COOLDOWN)
	{
		// update text and game state
		game.bigText.UpdateText(TITLE_TEXT);
		game.gameState = GameState::Menu;

		game.gameMusic.PlayMusic(SND_PATH + "Main_menu_theme/enchanted tiki 86.ogg");

		game.pastTime = game.newTime;

		//ALARM Flash MAYDAY timer
		game.flashTimer = 0.0f;
		//ALARM Flash MAYDAY timer

		//Additional info below
		//
		//
		//
	}
}
