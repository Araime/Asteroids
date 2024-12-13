#pragma once
#include <SFML/Graphics.hpp>
#include "unordered_map"

class ScoreTable
{
public:
	sf::RectangleShape highlighter;

	std::unordered_map<std::string, int> data;

	sf::Text scoreText;

	void InitScoreTable(const int playerScore, sf::Font& scoreFont);

	void UpdateScoreTable(const int playerScore);

	void DrawScoreTable(sf::RenderWindow& window, float xcor, float ycor);
};
