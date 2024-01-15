#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

struct Game;

struct Text
{
	sf::Text txt;
};

void InitText(Text& text, const sf::Font& font, const int size, const sf::Color& color);

void UpdateText(Text& text, const std::string& str); // update big text

void UpdateText(Game& game); // update cooldown text
