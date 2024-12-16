#pragma once
#include <SFML/Graphics.hpp>
#include "unordered_map"

class ScoreTable
{
public:
	sf::RectangleShape highlighter;

	std::unordered_map<std::string, int> data;

	// create multimap for sorting by scores
	std::multimap<int, std::string, std::greater<int>> sortedData;

	sf::Text scoreText;

	void InitScoreTable(const int playerScore, sf::Font& scoreFont);

	void UpdateScoreTable(const int playerScore);

	void DrawScoreTable(sf::RenderWindow& window, float xcor, float ycor);
};
