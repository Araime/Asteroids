#include "UI.h"
#include "Game.h"

namespace AsteroidsGame
{
	void InitUI(Game& game)
	{
		game.UI.whiteRect.setSize(sf::Vector2f(100.f, 15.f));
		game.UI.whiteRect.setFillColor(sf::Color::Transparent);
		game.UI.whiteRect.setOutlineThickness(2.f);
		game.UI.whiteRect.setOutlineColor(sf::Color::White);
		game.UI.whiteRect.setPosition(30.f, 730.f);

		game.UI.greenLine.setSize(sf::Vector2f(100.f, 15.f));
		game.UI.greenLine.setFillColor(sf::Color::Green);
		game.UI.greenLine.setPosition(30.f, 730.f);

		game.UI.redLine.setSize(sf::Vector2f(100.f, 15.f));
		game.UI.redLine.setFillColor(sf::Color::Red);
		game.UI.redLine.setPosition(30.f, 730.f);
	}

	// update player health
	void UpdateUI(Game& game, const float health)
	{
		game.UI.greenLine.setSize(sf::Vector2f(health, 15.f));
	}

	void DrawUI(Game& game, sf::RenderWindow& window)
	{
		window.draw(game.UI.redLine);
		window.draw(game.UI.greenLine);
		window.draw(game.UI.whiteRect);
	}
}