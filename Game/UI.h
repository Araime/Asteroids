#pragma once

#include <SFML/Graphics.hpp>

#include "Constants.h"

class Game;

class UserInterface
{
public:
	// create UI score text
	sf::Text UIScore;
	std::string scoreStr = "SCORE: ";

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

	// create weapon icons
	sf::Sprite laser;
	sf::Sprite rocket;

	// create wepon power sprite
	sf::Sprite weaponPower;

public:
	void InitUI(Game& game);

	// update player health
	void UpdateUIHealthBar(const float health);

	// change the color of the health bar depending on the condition of the shield
	void ChangeUIHealthBarColor(Game& game, bool is_protected);

	void UpdateWeaponHighlighterPos(const float xcor, const float ycor);

	void DrawUI(Game& game, sf::RenderWindow& window);

	void InitUIScore(const sf::Font& font, const int size, const sf::Color& color);

	void UpdateUIScore(const int& score);
};