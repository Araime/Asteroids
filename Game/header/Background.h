#pragma once
// PCH.h : #include <SFML/Graphics.hpp>
// PCH.h : #include "Constants.h"
#include "PCH.h"


class BG
{
public:
	sf::Sprite sprite;

	void InitBG(const sf::Texture& texture);
};