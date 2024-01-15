#include "Ship.h"
#include "Game.h"

Ship::Ship()
{
	name = "player";
}

void Ship::Update()
{
	if (isAccelerating)
	{
		dx += cos(angle * DEGTORAD) * SHIP_ACCELERATION;
		dy += sin(angle * DEGTORAD) * SHIP_ACCELERATION;
	}
	else
	{
		dx *= DECELERATION_FACTOR;
		dy *= DECELERATION_FACTOR;
	}

	float speed = sqrt(dx * dx + dy * dy);

	if (speed > maxSpeed)
	{
		dx *= maxSpeed / speed;
		dy *= maxSpeed / speed;
	}

	xcor += dx;
	ycor += dy;

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

void Ship::HandlePlayerInput(Game& game)
{
	switch (game.gameState)
	{
	case GameState::Menu:
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			game.RestartGame(game);
		}
		break;
	}
	case GameState::Game:
	{
		if (!game.player->isDestroyed)
		{
			// update current time
			game.newTime = game.gameTimer.getElapsedTime().asSeconds();

			// handle rotation
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				game.player->angle += ROTATION_SPEED;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				game.player->angle -= ROTATION_SPEED;
			}

			// make shot
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				MakeShot(game, game.player->rocketX);
			}

			// equip rocket
			if (game.player->weapon == Weapon::Laser)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
				{
					game.player->weapon = Weapon::Rocket;

					// change highlighter coord
					game.UI.UpdateWeaponHighlighterPos(SELECT2_XCOR, SELECT_YCOR);

					// play weapon change sound
					game.weapChangeSnd.sound.play();
				}
			}

			// equip laser
			if (game.player->weapon == Weapon::Rocket)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
				{
					game.player->weapon = Weapon::Laser;

					// change highlighter coord
					game.UI.UpdateWeaponHighlighterPos(SELECT1_XCOR, SELECT_YCOR);

					// play weapon change sound
					game.weapChangeSnd.sound.play();
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
			laser->SetParams(game.sLaser, game.player->xcor, game.player->ycor,
							 game.player->angle + float(rand() % 6 - 3), LASER_RAD);
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
		// create rockets
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

void Ship::RestartPlayer(Game& game)
{
	if (game.player->isDestroyed)
	{
		// update current time
		game.newTime = game.gameTimer.getElapsedTime().asSeconds();

		if (game.destroy_cooldown > 0)
		{
			if (game.newTime - game.pastTime > COUNTER)
			{
				// update cooldown counter
				game.destroy_cooldown -= COUNTER;
				game.timerSnd.sound.play();

				// update cooldown text
				game.cooldownText.UpdateText(game.cooldownText, game.cooldownStr + std::to_string(game.destroy_cooldown));

				// update past time
				game.pastTime = game.newTime;
			}
		}
		if (game.destroy_cooldown == 0)
		{
			// ressurect the player
			game.player->SetParams(game.sShip, float(SCREEN_WIDTH / 2), float(FIELD_HEIGHT / 2), 0.f, SHIP_RAD);
			game.player->dx = 0.f;
			game.player->dy = 0.f;
			game.player->isAccelerating = false;
			game.player->health = SHIP_HEALTH;
			game.player->isDestroyed = false;

			// update player health
			game.UI.UpdateUIHealthBar(game.player->health);
		}
	}
}