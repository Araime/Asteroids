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
					// check if enough time has passed
					if (game.newTime - game.pastTime > LASER_COOLDOWN)
					{
						MakeShot(game);

						game.pastTime = game.newTime;
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
					game.destroy_cooldown -= COUNTER;
					game.timerSnd.sound.play();

					// update game text
					game.text.setString(game.cooldownText + std::to_string(game.destroy_cooldown));

					game.pastTime = game.newTime;
				}
			}
			if (game.destroy_cooldown == 0)
			{
				game.player->SetParams(game.sShip, float(WIDTH / 2), float(HEIGHT / 2), 0.f, 20.f);
				game.player->dx = 0;
				game.player->dy = 0;
				game.player->isDestroyed = false;
			}
		}
	}
}