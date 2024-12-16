#include <algorithm>
#include "ScoreTable.h"
#include "Constants.h"

void ScoreTable::InitScoreTable(const int playerScore, sf::Font& scoreFont)
{
	// init highlighter
	highlighter.setSize(sf::Vector2f(HIGHLIGHTER_WIDTH, HIGHLIGHTER_HEIGHT));
	highlighter.setFillColor(sf::Color::Magenta);

	// clear and initialize map
	data.clear();
	data[PLAYER_NAME] = 0;

	// generate random scores and names and add it to score table
	int massiveLength = static_cast<int>(sizeof(NAMES) / sizeof(NAMES[0]));
	int randomIndex = rand() % massiveLength - 1;

	for (int i = 0; i < TABLE_ROWS; i++)
	{
		data[NAMES[randomIndex]] = rand() % MAX_RAND_SCORE;
		randomIndex++;
		if (randomIndex > massiveLength)
		{
			randomIndex = 0;
		}
	}

	// init score table text
	scoreText.setFont(scoreFont);
	scoreText.setCharacterSize(SCORETABLE_TEXT_SIZE);
	scoreText.setFillColor(sf::Color::Yellow);
}

void ScoreTable::UpdateScoreTable(const int playerScore)
{
	// update player score in map
	data[PLAYER_NAME] = std::max(data[PLAYER_NAME], playerScore);

	// add scores in update multimap and add scores
	sortedData.clear();

	for (const auto& item : data)
	{
		sortedData.insert(make_pair(item.second, item.first));
	}
}

void ScoreTable::DrawScoreTable(sf::RenderWindow& window, float xcor, float ycor)
{
	int place = 1;
	for (const auto& item : sortedData)
	{
		if (item.second == PLAYER_NAME)
		{
			// update highlighter position
			highlighter.setPosition(xcor - TABLE_STEP, ycor + HIGHLIGHTER_STEP);
			window.draw(highlighter);
		}

		// draw player name
		scoreText.setString(std::to_string(place) + "  " + item.second);
		scoreText.setPosition(xcor, ycor);
		window.draw(scoreText);

		// draw player score
		scoreText.setString(std::to_string(item.first));
		scoreText.setPosition(xcor + TABLE_INDENT, ycor);
		window.draw(scoreText);

		ycor += TABLE_STEP;
		place++;
	}
}
