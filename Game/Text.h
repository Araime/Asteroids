#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace AsteroidsGame
{
	struct Game;

	struct Text
	{
		sf::Text txt;
	};
	
	void InitText(Text& text, const sf::Font& font, const int size, const sf::Color& color);

	void UpdateText(Text& text, std::string& str);

	void UpdateCooldownText(Game& game);
}