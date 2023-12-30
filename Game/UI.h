#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace AsteroidsGame
{
	struct Game;

	enum class Weapon
	{
		Laser = 0,
		Rocket,
	};

	struct UserInterface
	{
		// create health bar
		sf::RectangleShape whiteRect;
		sf::RectangleShape greenLine;
		sf::RectangleShape redLine;

		// create ship life
		sf::Sprite shipLife;
		float lifeX = 150.f;
	};

	void InitUI(Game& game);

	void UpdateUI(Game& game, const float health); // update player health

	void UpdateUI();

	void DrawUI(Game& game, sf::RenderWindow& window);
}