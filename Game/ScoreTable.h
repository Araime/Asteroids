#pragma once
#include <SFML/Graphics.hpp>
#include "unordered_map"

class ScoreTable
{
public:
	sf::RectangleShape highlighter;

	std::unordered_map<std::string, int> data;

	float xcor = 280.f;
	float ycor = 250.f;

	void InitScoreTable(const int playerScore);

	void UpdateScoreTable(const int playerScore);

	void DrawScoreTable(sf::Text& scoresText, sf::RenderWindow& window, float xcor, float ycor);
};
