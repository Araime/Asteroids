#include <SFML/Graphics.hpp>
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
	// init randomizer with random seed
	srand(static_cast<int>(time(nullptr)));

	// init game window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_NAME);
	window.setFramerateLimit(FPS);
	window.setVerticalSyncEnabled(true);

	Game game;
	game.InitGame(game);

	// init game timer
	sf::Clock gameClock;
	float deltaTime = 0.f;

	// main loop
	while (window.isOpen())
	{
		// get current time
		const float deltaTime = gameClock.restart().asSeconds();

		HanldeWindowEvents(window);

		switch (game.gameState)
		{
		case GameState::TitleScreen:
		{
			game.DrawMainMenu(game, window);
			break;
		}
		case GameState::Game:
		{
			game.UpdateGame(game, window, deltaTime);
			game.DrawGame(game, window);
			break;
		}
		case GameState::GameOver:
		{
			game.DrawGameOver(game, window);
			break;
		}
		default:
			break;
		}
	}
	return 0;
}
