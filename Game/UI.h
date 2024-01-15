#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

struct Game;

class UserInterface
{
public:
	// create UI BG
	sf::RectangleShape menuRect;

	// create health bar
	sf::RectangleShape whiteRect;
	sf::RectangleShape greenLine;
	sf::RectangleShape redLine;

	// create weapon highlighter
	sf::RectangleShape highlighter;

	// create ship life
	sf::Sprite shipLife;
	float lifeX = 150.f;

	// create weapon icons
	sf::Sprite laser;
	sf::Sprite rocket;

public:
	void InitUI(Game& game);

	// update player health
	void UpdateUIHealthBar(Game& game, const float health);

	void DrawUI(Game& game, sf::RenderWindow& window, float xcor);
};