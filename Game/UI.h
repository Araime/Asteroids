#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace AsteroidsGame
{
	struct Game;

	struct UserInterface
	{
		sf::RectangleShape whiteRect;
		sf::RectangleShape greenLine;
		sf::RectangleShape redLine;
	};

	void InitUI(Game& game);

	void UpdateUI(Game& game, const float health); // update player health

	void UpdateUI();

	void UpdateUI();

	void DrawUI(Game& game, sf::RenderWindow& window);
}