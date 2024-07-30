#pragma once
#include<SFML/Graphics.hpp>
#include "Constants.h"

class Button
{
public:
	sf::RectangleShape shape;
	sf::Text txt;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	void Init(const sf::Font& font, const std::string& text, const float& xcor, const float& ycor);

	void Update();
};