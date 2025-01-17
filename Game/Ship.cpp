#include "Ship.h"

#include "Game.h"

Ship::Ship()
{
	name = "player";
}

void Ship::Update(float deltaTime)
{
	if (isAccelerating)
	{
		deltaX += cos(angle * DEGREES_TO_RADIANS) * SHIP_ACCELERATION;
		deltaY += sin(angle * DEGREES_TO_RADIANS) * SHIP_ACCELERATION;
	}
	else
	{
		deltaX *= DECELERATION_FACTOR;
		deltaY *= DECELERATION_FACTOR;
	}

	float speed = sqrt(deltaX * deltaX + deltaY * deltaY);

	if (speed > maxSpeed)
	{
		deltaX *= maxSpeed / speed;
		deltaY *= maxSpeed / speed;
	}

	xcor += deltaX * deltaTime;
	ycor += deltaY * deltaTime;

	// check if it's beyond the edge of the screen
	if (xcor > SCREEN_WIDTH)
	{
		xcor = 0.f;
	}
	if (xcor < 0)
	{
		xcor = SCREEN_WIDTH;
	}
	if (ycor > FIELD_HEIGHT)
	{
		ycor = 0.f;
	}
	if (ycor < 0)
	{
		ycor = FIELD_HEIGHT;
	}
}

void Ship::HandlePlayerInput(Game& game, float deltaTime)
{
	switch (game.gameState)
	{
	case GameState::TitleScreen:
	{
		break;
	}
	case GameState::Game:
	{
		if (game.player->isDestroyed) return;

		// update current time
		game.newTime = game.gameTimer.getElapsedTime().asSeconds();

		// handle rotation
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			game.player->angle += ROTATION_SPEED * deltaTime;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			game.player->angle -= ROTATION_SPEED * deltaTime;
		}

		// make shot
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			MakeShot(game, game.player->rocketX);
		}

		// equip rocket
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && game.player->weapon == Weapon::Laser)
		{
			ChangeWeapon(game);
		}

		// equip laser
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && game.player->weapon == Weapon::Rocket)
		{
			ChangeWeapon(game);
		}

		// check if ship is accelerated
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			isAccelerating = true;
		}
		else
		{
			isAccelerating = false;
		}
		break;
	}
	case GameState::GameOver:
	{
		break;
	}
	default:
		break;
	}
}

void Ship::ChangeWeapon(Game& game)
{
	switch (game.player->weapon)
	{
	case Weapon::Laser:
		game.player->weapon = Weapon::Rocket;
		game.UI.UpdateWeaponHighlighterPos(SELECT2_XCOR, SELECT_YCOR);
		game.weapChangeSnd.sound.play();
		break;
	case Weapon::Rocket:
		game.player->weapon = Weapon::Laser;
		game.UI.UpdateWeaponHighlighterPos(SELECT1_XCOR, SELECT_YCOR);
		game.weapChangeSnd.sound.play();
		break;
	default:
		break;
	}
}

void Ship::MakeShot(Game& game, float xcor)
{
	switch (game.player->weapon)
	{
	case Weapon::Laser:
	{
		// check if enough time has passed
		if (game.newTime - game.pastTime > LASER_COOLDOWN)
		{
			// create new laser
			Laser* laser = new Laser();

			float rand_angle = static_cast<float>(rand() % 6 - 3);
			laser->SetParams(game.sLaser, game.player->xcor, game.player->ycor,
				game.player->angle + rand_angle, LASER_RAD);
			game.entities.push_back(laser);

			// play random laser sound
			game.laserSndArray[rand() % LASER_SND_QTY].sound.play();

			// update timer
			game.pastTime = game.newTime;
		}

		break;
	}
	case Weapon::Rocket:
	{
		// check if enough time has passed
		if (game.newTime - game.pastTime > ROCKET_COOLDOWN)
		{
			for (int i = 0; i < ROCKETS_QTY; i++)
			{
				// create new rocket
				Rocket* rocket = new Rocket();
				rocket->SetParams(game.sRocket, game.player->xcor, game.player->ycor,
					game.player->angle - xcor, ROCKET_RAD);
				game.entities.push_back(rocket);
				xcor += ROCKET_ANGLE_STEP;
			}

			// play random rocket sound
			game.rocketSndArray[rand() % ROCKETS_SND_QTY].sound.play();

			// update timer
			game.pastTime = game.newTime;
		}

		break;
	}
	default:
		break;
	}
}

void Ship::UpdateShipSprite(Game& game)
{
	if (!game.player->isDestroyed)
	{
		// change sprite if ship is accelerated
		if (game.player->isAccelerating)
		{
			game.player->anim = game.sFlyingShip;
		}
		else
		{
			game.player->anim = game.sShip;
		}
	}
}

void Ship::TakeDamage(Game& game, const float damage)
{
	game.player->health -= damage * DAMAGE_MULTIPLIER;

	if (game.player->health < 0.f)
	{
		game.player->health = 0.f;
	}

	// update player health
	game.UI.UpdateUIHealthBar(game.player->health);

	if (game.player->health == 0.f)
	{
		game.player->isDestroyed = true;
		game.player->ships--;
		game.shipExplSnd.sound.play();
	}
}

void Ship::HandlePlayerRessurection(Game& game)
{
	if (!game.player->isDestroyed) return;

	// update current time
	game.newTime = game.gameTimer.getElapsedTime().asSeconds();

	if (game.destroy_cooldown)
	{
		if (game.newTime - game.pastTime > COUNTER)
		{
			// update cooldown counter
			game.destroy_cooldown -= COUNTER;
			game.timerSnd.sound.play();

			// update cooldown text
			game.cooldownText.UpdateText(game.cooldownStr + std::to_string(game.destroy_cooldown));

			// update past time
			game.pastTime = game.newTime;
		}
	}
	if (!game.destroy_cooldown)
	{
		RessurectPlayer(game);

		// update player health
		game.UI.UpdateUIHealthBar(game.player->health);
	}
}

void Ship::RessurectPlayer(Game& game)
{
	// ressurect the player
	ResetPlayerParams(game);

	game.player->deltaX = 0.f;
	game.player->deltaY = 0.f;
	game.player->isDestroyed = false;
	game.player->isAccelerating = false;
	game.player->health = SHIP_HEALTH;
}

void Ship::ResetPlayerParams(Game& game)
{
	float angle = 0.f;

	game.player->SetParams(game.sShip, static_cast<float>(SCREEN_WIDTH / 2),
		static_cast<float>(FIELD_HEIGHT / 2), angle, SHIP_RAD);
}
