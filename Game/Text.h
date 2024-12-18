#pragma once

#include <SFML/Graphics.hpp>

#include "Constants.h"

class Text
{
public:
	sf::Text txt;

	void InitText(const sf::Font& font, const int size, const sf::Color& color);

	void UpdateText(const std::string& str);

	void UpdatePosition(const float& xcor, const float& ycor);
};