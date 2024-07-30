#include "Button.h"

void Button::Init(const sf::Font& font, const std::string& text, const float& xcor, const float& ycor)
{
	idleColor = sf::Color(255, 255, 0, 255);
	hoverColor = sf::Color(169, 169, 169, 255);
	activeColor = sf::Color(47, 79, 79, 200);

	txt.setFont(font);
	txt.setCharacterSize(BUTTON_TEXT_SIZE);
	txt.setStyle(sf::Text::Bold);
	txt.setFillColor(idleColor);
	txt.setString(text);

	sf::FloatRect textRect = txt.getGlobalBounds();
	txt.setOrigin(textRect.width / 2, textRect.height / 2);
	txt.setPosition(xcor, ycor);
}

void Button::Update()
{

}
