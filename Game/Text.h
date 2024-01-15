#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

class Text
{
public:
	sf::Text txt;

	void InitText(Text& text, const sf::Font& font, const int size, const sf::Color& color);

	void UpdateText(Text& text, const std::string& str);
};