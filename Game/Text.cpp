#include "Text.h"
#include "Game.h"

namespace AsteroidsGame
{
	void AsteroidsGame::InitText(Text& text, const sf::Font& font, const int size, const sf::Color& color)
	{
		text.txt.setFont(font);
		text.txt.setCharacterSize(COOLDOWN_TEXT_SIZE);
		text.txt.setStyle(sf::Text::Bold);
		text.txt.setFillColor(color);
	}

	void UpdateText(Text& text, std::string& str)
	{
		text.txt.setString(str);

		sf::FloatRect textRect = text.txt.getLocalBounds();
		text.txt.setOrigin(textRect.width * 0.5f, textRect.height * 0.5f);
		text.txt.setPosition(float(WIDTH / 2), float(HEIGHT / 2));
	}

	void UpdateCooldownText(Game& game)
	{
		game.cooldownText.txt.setString(game.cooldownStr + std::to_string(game.destroy_cooldown));

		sf::FloatRect textRect = game.cooldownText.txt.getLocalBounds();
		game.cooldownText.txt.setOrigin(textRect.width * 0.5f, textRect.height * 0.5f);
		game.cooldownText.txt.setPosition(float(WIDTH / 2), float(HEIGHT / 2));
	}
}
