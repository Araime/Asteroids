#include "UI.h"
#include "Game.h"

namespace AsteroidsGame
{
	void InitUI(Game& game)
	{
		// init health bar
		game.UI.whiteRect.setSize(sf::Vector2f(HEALTH_WIDTH, HEALTH_HEIGHT));
		game.UI.whiteRect.setFillColor(sf::Color::Transparent);
		game.UI.whiteRect.setOutlineThickness(2.f);
		game.UI.whiteRect.setOutlineColor(sf::Color::White);
		game.UI.whiteRect.setPosition(30.f, 730.f);

		game.UI.greenLine.setSize(sf::Vector2f(HEALTH_WIDTH, HEALTH_HEIGHT));
		game.UI.greenLine.setFillColor(sf::Color::Green);
		game.UI.greenLine.setPosition(30.f, 730.f);

		game.UI.redLine.setSize(sf::Vector2f(HEALTH_WIDTH, HEALTH_HEIGHT));
		game.UI.redLine.setFillColor(sf::Color::Red);
		game.UI.redLine.setPosition(30.f, 730.f);

		// init ship lifes
		game.UI.shipLife.setTexture(game.shipTexture);
		game.UI.shipLife.setTextureRect(sf::IntRect(40, 0, 40, 39));
		// change life sprite size
		game.UI.shipLife.setScale(LIFE_SIZE / game.UI.shipLife.getLocalBounds().width,
								  LIFE_SIZE / game.UI.shipLife.getLocalBounds().height);

		// init weapon icons
		game.UI.laser.setTexture(game.laserTexture);
		game.UI.laser.setTextureRect(sf::IntRect(0, 0, 32, 64));
		game.UI.laser.setScale(0.5f, 0.5f);
		game.UI.laser.setOrigin(game.UI.laser.getLocalBounds().width * 0.5f,
								game.UI.laser.getLocalBounds().height * 0.5f);
		game.UI.laser.setRotation(90.f);

		game.UI.rocket.setTexture(game.rocketTexture);
		game.UI.rocket.setTextureRect(sf::IntRect(0, 0, 16, 28));
		game.UI.rocket.setOrigin(game.UI.rocket.getLocalBounds().width * 0.5f,
								 game.UI.rocket.getLocalBounds().height * 0.5f);
		game.UI.rocket.setRotation(90.f);
	}

	// update player health
	void UpdateUI(Game& game, const float health)
	{
		game.UI.greenLine.setSize(sf::Vector2f(health, HEALTH_HEIGHT));
	}

	void DrawUI(Game& game, sf::RenderWindow& window)
	{
		window.draw(game.UI.redLine);
		window.draw(game.UI.greenLine);
		window.draw(game.UI.whiteRect);

		game.UI.lifeX = 150.f;

		for (int i = 0; i < game.player->ships; i++)
		{
			game.UI.shipLife.setPosition(game.UI.lifeX, LIFE_Y);
			window.draw(game.UI.shipLife);
			game.UI.lifeX += LIFE_STEP;
		}

		switch (game.player->weapon)
		{
		case Weapon::Laser:
		{
			game.UI.laser.setPosition(260.f, 738.f);
			window.draw(game.UI.laser);
			break;
		}
		case Weapon::Rocket:
		{
			game.UI.rocket.setPosition(260.f, 738.f);
			window.draw(game.UI.rocket);
			break;
		}
		default:
			break;
		}
	}
}