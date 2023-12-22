#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace AsteroidsGame
{
	struct Game;

	struct BG
	{
		sf::Sprite sprite;
	};

	void InitBG(BG& bg, const sf::Texture& texture);
}