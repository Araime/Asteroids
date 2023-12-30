#include "HealthBar.h"
#include "Game.h"

namespace AsteroidsGame
{
	void InitHealthBar(Game& game)
	{
		game.healthBar.whiteRect.setSize(sf::Vector2f(100.f, 15.f));
		game.healthBar.whiteRect.setFillColor(sf::Color::Transparent);
		game.healthBar.whiteRect.setOutlineThickness(2.f);
		game.healthBar.whiteRect.setOutlineColor(sf::Color::White);
		game.healthBar.whiteRect.setPosition(30.f, 730.f);

		game.healthBar.greenLine.setSize(sf::Vector2f(100.f, 15.f));
		game.healthBar.greenLine.setFillColor(sf::Color::Green);
		game.healthBar.greenLine.setPosition(30.f, 730.f);

		game.healthBar.redLine.setSize(sf::Vector2f(100.f, 15.f));
		game.healthBar.redLine.setFillColor(sf::Color::Red);
		game.healthBar.redLine.setPosition(30.f, 730.f);
	}

	void UpdateHealhBar(Game& game, const float health)
	{
		game.healthBar.greenLine.setSize(sf::Vector2f(health, 15.f));
	}

	void DrawHealthBar(Game& game, sf::RenderWindow& window)
	{
		window.draw(game.healthBar.redLine);
		window.draw(game.healthBar.greenLine);
		window.draw(game.healthBar.whiteRect);
	}
}