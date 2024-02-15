#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

class BG
{
public:
	sf::Sprite sprite;

	void InitBG(const sf::Texture& texture);
};