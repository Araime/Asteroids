#include "Background.h"

void BG::InitBG(BG& bg, const sf::Texture& texture)
{
	bg.sprite.setTexture(texture);

	sf::FloatRect spriteRect = bg.sprite.getLocalBounds();
	bg.sprite.setOrigin(spriteRect.width * 0.5f, spriteRect.height * 0.5f);
	bg.sprite.setPosition(float(SCREEN_WIDTH / 2), float(SCREEN_HEIGHT / 2));
}