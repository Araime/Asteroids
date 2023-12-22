#include "Background.h"
#include "Game.h"

namespace AsteroidsGame
{
	void InitBG(BG& bg, const sf::Texture& texture)
	{
		bg.sprite.setTexture(texture);

		sf::FloatRect spriteRect = bg.sprite.getLocalBounds();
		bg.sprite.setOrigin(spriteRect.width * 0.5f, spriteRect.height * 0.5f);
		bg.sprite.setPosition(float(WIDTH / 2), float(HEIGHT / 2));
	}
}