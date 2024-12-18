#pragma once

#include<SFML/Graphics.hpp>

#include "Constants.h"

enum ButtonState{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Game;

class Button
{
public:
	unsigned short buttonState;

	sf::RectangleShape shape;
	sf::Text txt;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	bool isHighlighted;
	bool isClicked;

	void Init(const sf::Font& font, const std::string& text, const float& btnWidth, const float& xcor, const float& ycor);

	void Update(Game& game, const sf::Vector2f& mousePos);

	const bool IsPressed() const;

	void Draw(sf::RenderWindow& window);
};
