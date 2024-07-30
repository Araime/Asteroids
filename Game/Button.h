#pragma once
#include<SFML/Graphics.hpp>
#include "Constants.h"

enum ButtonState{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button
{
public:
	unsigned short buttonState;

	sf::RectangleShape shape;
	sf::Text txt;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	void Init(const sf::Font& font, const std::string& text, const float& btnWidth, const float& xcor, const float& ycor);

	void Update(const sf::Vector2f& mousePos);

	void Draw(sf::RenderWindow& window);
};
