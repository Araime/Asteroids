#include "Text.h"

void Text::InitText(Text& text, const sf::Font& font, const int size, const sf::Color& color)
{
	text.txt.setFont(font);
	text.txt.setCharacterSize(size);
	text.txt.setStyle(sf::Text::Bold);
	text.txt.setFillColor(color);
}

void Text::UpdateText(Text& text, const std::string& str)
{
	text.txt.setString(str);

	sf::FloatRect textRect = text.txt.getLocalBounds();
	text.txt.setOrigin(textRect.width * 0.5f, textRect.height * 0.5f);
	text.txt.setPosition(float(SCREEN_WIDTH / 2), float(SCREEN_HEIGHT / 2));
}