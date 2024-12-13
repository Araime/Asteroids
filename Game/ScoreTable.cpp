#include <algorithm>
#include "ScoreTable.h"
#include "Constants.h"

void ScoreTable::InitScoreTable(const int playerScore, sf::Font& scoreFont)
{
	// init highlighter
	highlighter.setSize(sf::Vector2f(HIGHLIGHTER_WIDTH, HIGHLIGHTER_HEIGHT));
	highlighter.setFillColor(sf::Color::Magenta);

	data[PLAYER_NAME] = 0;

	// generate random scores and names and add it to score table
	for (int i = 0; i < TABLE_ROWS; i++)
	{
		data[NAMES[rand() % static_cast<int>(sizeof(NAMES) / sizeof(NAMES[0]))]] = rand() % MAX_RAND_SCORE;
	}

	// init score table text
	scoreText.setFont(scoreFont);
	scoreText.setCharacterSize(SCORETABLE_TEXT_SIZE);
	scoreText.setFillColor(sf::Color::Yellow);
}

void ScoreTable::UpdateScoreTable(const int playerScore)
{
	data[PLAYER_NAME] = std::max(data[PLAYER_NAME], playerScore);
}

void ScoreTable::DrawScoreTable(sf::RenderWindow& window, float xcor, float ycor)
{
	// create multimap for sorting by scores
	std::multimap<int, std::string, std::greater<int>> sortedData;

	// add scores in multimap
	for (const auto& item : data)
	{
		sortedData.insert(make_pair(item.second, item.first));
	}

	for (const auto& item : sortedData)
	{
		if (item.second == PLAYER_NAME)
		{
			// update highlighter position
			highlighter.setPosition(xcor - TABLE_STEP, ycor + HIGHLIGHTER_STEP);
			window.draw(highlighter);
		}

		scoreText.setString(item.second);
		scoreText.setPosition(xcor, ycor);
		window.draw(scoreText);

		scoreText.setString(std::to_string(item.first));
		scoreText.setPosition(xcor + TABLE_INDENT, ycor);
		window.draw(scoreText);

		ycor += TABLE_STEP;
	}
}
