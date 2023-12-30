#include "Ship.h"
#include "Game.h"

namespace AsteroidsGame
{
	void HandlePlayerInput(Game& game)
	{
		switch (game.gameState)
		{
		case GameState::Menu:
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				RestartGame(game);
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
					game.player->angle += 3.f;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					game.player->angle -= 3.f;
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

	void MakeShot(Game& game, float xcor)
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
					xcor += ROCKET_STEP;
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

	void UpdateShipSprite(Game& game)
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

	void TakeDamage(Game& game, const float damage)
	{
		game.player->health -= damage * 2.f;

		if (game.player->health < 0.f)
		{
			game.player->health = 0.f;
		}

		if (game.player->health == 0.f)
		{
			game.player->isDestroyed = true;
			game.player->ships--;
			game.shipExplSnd.sound.play();
		}
	}

	void RestartPlayer(Game& game)
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
					UpdateText(game);

					// update past time
					game.pastTime = game.newTime;
				}
			}
			if (game.destroy_cooldown == 0)
			{
				// ressurect the player
				game.player->SetParams(game.sShip, float(SCREEN_WIDTH / 2), float(FIELD_HEIGHT / 2), 0.f, 20.f);
				game.player->dx = 0.f;
				game.player->dy = 0.f;
				game.player->isAccelerating = false;
				game.player->health = 100.f;
				game.player->isDestroyed = false;

				// update player health
				UpdateUI(game, game.player->health);
			}
		}
	}
}