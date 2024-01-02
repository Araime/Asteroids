#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace AsteroidsGame
{
	struct Game;

	struct UserInterface
	{
		// create UI BG
		sf::RectangleShape menuRect;

		// create health bar
		sf::RectangleShape whiteRect;
		sf::RectangleShape greenLine;
		sf::RectangleShape redLine;

		// create weapon highlighter
		sf::RectangleShape highlighter;

		// create ship life
		sf::Sprite shipLife;
		float lifeX = 150.f;

		// create weapon icons
		sf::Sprite laser;
		sf::Sprite rocket;
	};

	void InitUI(Game& game);

	void UpdateUI(Game& game, const float health); // update player health

	void DrawUI(Game& game, sf::RenderWindow& window, float xcor);
}