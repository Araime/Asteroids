#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

struct Game;

class Text
{
public:
	sf::Text txt;

	void InitText(Text& text, const sf::Font& font, const int size, const sf::Color& color);

	// update big text
	void UpdateText(Text& text, const std::string& str);

	// update cooldown text
	void UpdateText(Game& game);
};