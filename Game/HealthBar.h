#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace AsteroidsGame
{
	struct Game;

	struct HealthBar
	{
		sf::RectangleShape whiteRect;
		sf::RectangleShape greenLine;
		sf::RectangleShape redLine;
	};

	void InitHealthBar(Game& game);

	void UpdateHealhBar(Game& game, const float health);

	void DrawHealthBar(Game& game, sf::RenderWindow& window);
}