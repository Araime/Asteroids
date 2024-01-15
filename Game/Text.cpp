#include "Text.h"
#include "Game.h"

void InitText(Text& text, const sf::Font& font, const int size, const sf::Color& color)
{
	text.txt.setFont(font);
	text.txt.setCharacterSize(size);
	text.txt.setStyle(sf::Text::Bold);
	text.txt.setFillColor(color);
}

// update big text
void UpdateText(Text& text, const std::string& str)
{
	text.txt.setString(str);

	sf::FloatRect textRect = text.txt.getLocalBounds();
	text.txt.setOrigin(textRect.width * 0.5f, textRect.height * 0.5f);
	text.txt.setPosition(float(SCREEN_WIDTH / 2), float(SCREEN_HEIGHT / 2));
}

// update cooldown text
void UpdateText(Game& game)
{
	game.cooldownText.txt.setString(game.cooldownStr + std::to_string(game.destroy_cooldown));

	sf::FloatRect textRect = game.cooldownText.txt.getLocalBounds();
	game.cooldownText.txt.setOrigin(textRect.width * 0.5f, textRect.height * 0.5f);
	game.cooldownText.txt.setPosition(float(SCREEN_WIDTH / 2), float(FIELD_HEIGHT / 2));
}
