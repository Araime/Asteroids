#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace AsteroidsGame
{
	struct Game;

	struct UserInterface
	{
		// create health bar
		sf::RectangleShape whiteRect;
		sf::RectangleShape greenLine;
		sf::RectangleShape redLine;

		// create ship life
		sf::Sprite shipLife;
		float lifeX = 150.f;

		// create weapon icons
		sf::Sprite laser;
		sf::Sprite rocket;
	};

	void InitUI(Game& game);

	void UpdateUI(Game& game, const float health); // update player health

	void UpdateUI();

	void DrawUI(Game& game, sf::RenderWindow& window, float xcor);
}