#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

class BG
{
public:
	sf::Sprite sprite;

	void InitBG(BG& bg, const sf::Texture& texture);
};