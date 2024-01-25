#include "../header/Text.h"

void Text::InitText(const sf::Font& font, const int size, const sf::Color& color)
{
	txt.setFont(font);
	txt.setCharacterSize(size);
	txt.setStyle(sf::Text::Bold);
	txt.setFillColor(color);
}

void Text::UpdateText(const std::string& str)
{
	txt.setString(str);

	sf::FloatRect textRect = txt.getLocalBounds();
	txt.setOrigin(textRect.width / 2, textRect.height / 2);
	txt.setPosition(static_cast<float>(SCREEN_WIDTH / 2), static_cast<float>(SCREEN_HEIGHT / 2));
}