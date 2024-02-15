#include "Background.h"

void BG::InitBG(const sf::Texture& texture)
{
	sprite.setTexture(texture);

	sf::FloatRect spriteRect = sprite.getLocalBounds();
	sprite.setOrigin(spriteRect.width / 2, spriteRect.height / 2);
	sprite.setPosition(float(SCREEN_WIDTH / 2), float(SCREEN_HEIGHT / 2));
}