#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <time.h>
#include "Constants.h"
#include "Game.h"

void HanldeWindowEvents(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		{
			window.close();
		}
	}
}

int main()
{
	using namespace AsteroidsGame;

	// init randomizer with random seed
	srand(int(time(nullptr)));

	// init game window
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	Game game;
	InitGame(game);

	// init game timer
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();

	// main loop
	while (window.isOpen())
	{
		// get current time
		const float currentrTime = gameClock.getElapsedTime().asSeconds();

		HanldeWindowEvents(window);

		switch (game.gameState)
		{
		case GameState::Menu:
		{
			DrawMainMenu(game, window);
			break;
		}
		case GameState::Game:
		{
			UpdateGame(game, window, currentrTime, lastTime);
			DrawGame(game, window);
			break;
		}
		case GameState::GameOver:
		{
			DrawGameOver(game, window);
			break;
		}
		default:
			break;
		}
	}
	return 0;
}
