#include "UI.h"

#include "Game.h"

void UserInterface::InitUI(Game& game)
{
	// init menu BG
	game.UI.menuRect.setSize(sf::Vector2f(SCREEN_WIDTH, MENU_HEIGHT));
	game.UI.menuRect.setFillColor(sf::Color::Black);
	game.UI.menuRect.setPosition(MENU_XCOR, MENU_YCOR);

	// init health bar
	game.UI.whiteRect.setSize(sf::Vector2f(HP_WIDTH, HP_HEIGHT));
	game.UI.whiteRect.setFillColor(sf::Color::Transparent);
	game.UI.whiteRect.setOutlineThickness(2.f);
	game.UI.whiteRect.setOutlineColor(sf::Color::White);
	game.UI.whiteRect.setPosition(HP_XCOR, HP_YCOR);

	game.UI.greenLine.setSize(sf::Vector2f(HP_WIDTH, HP_HEIGHT));
	game.UI.greenLine.setFillColor(sf::Color::Green);
	game.UI.greenLine.setPosition(HP_XCOR, HP_YCOR);

	game.UI.redLine.setSize(sf::Vector2f(HP_WIDTH, HP_HEIGHT));
	game.UI.redLine.setFillColor(sf::Color::Red);
	game.UI.redLine.setPosition(HP_XCOR, HP_YCOR);

	// init highlighter
	game.UI.highlighter.setSize(sf::Vector2f(SELECTOR_SIZE, SELECTOR_SIZE));
	game.UI.highlighter.setFillColor(sf::Color::Transparent);
	game.UI.highlighter.setOutlineThickness(2.f);
	game.UI.highlighter.setOutlineColor(sf::Color::Green);
	game.UI.highlighter.setPosition(SELECT1_XCOR, SELECT_YCOR);

	// init ship lifes
	game.UI.shipLife.setTexture(game.shipLife);
	game.UI.shipLife.setTextureRect(sf::IntRect(0, 0, LIFE_WIDTH, LIFE_HEIGHT));
	game.UI.shipLife.setScale(LIFE_SIZE / game.UI.shipLife.getLocalBounds().width,
							  LIFE_SIZE / game.UI.shipLife.getLocalBounds().height);

	// init weapon icons
	game.UI.laser.setTexture(game.laserTexture);
	game.UI.laser.setTextureRect(sf::IntRect(0, 0, UI_LASER_WIDTH, UI_LASER_HEIGHT));
	game.UI.laser.setScale(0.5f, 0.5f);
	game.UI.laser.setOrigin(game.UI.laser.getLocalBounds().width / 2,
							game.UI.laser.getLocalBounds().height / 2);
	game.UI.laser.setRotation(WEAP_ICON_ANGLE);
	game.UI.laser.setPosition(ICON1_XCOR, ICON1_YCOR);

	game.UI.rocket.setTexture(game.rocketTexture);
	game.UI.rocket.setTextureRect(sf::IntRect(0, 0, UI_ROCKET_WIDTH, UI_ROCKET_HEIGHT));
	game.UI.rocket.setOrigin(game.UI.rocket.getLocalBounds().width / 2,
							 game.UI.rocket.getLocalBounds().height / 2);
	game.UI.rocket.setRotation(WEAP_ICON_ANGLE);
	game.UI.rocket.setPosition(ICON2_XCOR, ICON2_YCOR);
}

void UserInterface::UpdateUIHealthBar(const float health)
{
	greenLine.setSize(sf::Vector2f(health, HP_HEIGHT));
}

void UserInterface::UpdateWeaponHighlighterPos(const float xcor, const float ycor)
{
	// change highlighter coord
	highlighter.setPosition(xcor, ycor);
}

void UserInterface::DrawUI(Game& game, sf::RenderWindow& window)
{
	// draw HP
	window.draw(game.UI.menuRect);
	window.draw(game.UI.redLine);
	window.draw(game.UI.greenLine);
	window.draw(game.UI.whiteRect);

	// draw lifes
	for (int i = 0; i < game.player->ships; ++i)
	{
		float lifeXcor = LIFE_XCOR + LIFE_STEP * i;
		game.UI.shipLife.setPosition(lifeXcor, LIFE_YCOR);
		window.draw(game.UI.shipLife);
	}

	// draw weapons
	window.draw(game.UI.laser);
	window.draw(game.UI.rocket);

	// draw highlihter
	window.draw(game.UI.highlighter);

	// draw UI score
	if (game.gameState == GameState::Game)
	{
		window.draw(game.UI.UIScore);
	}
}

void UserInterface::InitUIScore(const sf::Font& font, const int size, const sf::Color& color)
{
	UIScore.setFont(font);
	UIScore.setCharacterSize(size);
	UIScore.setStyle(sf::Text::Bold);
	UIScore.setFillColor(color);
	UIScore.setPosition(UI_XCOR, UI_YCOR);
}

void UserInterface::UpdateUIScore(const int& score)
{
	UIScore.setString(scoreStr + std::to_string(score));
}
