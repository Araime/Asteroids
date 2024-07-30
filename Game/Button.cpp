#include "Button.h"
#include "Game.h"

void Button::Init(const sf::Font& font, const std::string& text, const float& btnWidth, const float& xcor, const float& ycor)
{
	idleColor = sf::Color(255, 255, 0, 255);
	hoverColor = sf::Color(255, 0, 0, 255);
	activeColor = sf::Color(128, 0, 0, 255);

	isHighlighted = false;
	isClicked = false;

	txt.setFont(font);
	txt.setCharacterSize(BUTTON_TEXT_SIZE);
	txt.setStyle(sf::Text::Bold);
	txt.setFillColor(idleColor);
	txt.setString(text);

	sf::FloatRect textRect = txt.getGlobalBounds();
	txt.setOrigin(textRect.width / 2, textRect.height / 2);
	txt.setPosition(xcor, ycor);

	shape.setSize({btnWidth, BTNS_HEIGHT});
	sf::FloatRect shapeRect = shape.getGlobalBounds();
	shape.setOrigin(shapeRect.width / 2, shapeRect.height / 2);
	shape.setPosition(xcor, ycor + 20.f);
	shape.setFillColor(hoverColor);
}

void Button::Update(Game& game, const sf::Vector2f& mousePos)
{
	// changing the state of the button: at rest, the cursor is hovered, the button is pressed
	buttonState = BTN_IDLE;

	if (shape.getGlobalBounds().contains(mousePos))
	{
		buttonState = BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			buttonState = BTN_ACTIVE;
		}
	}

	// change button text color by state
	switch (buttonState)
	{
	case BTN_IDLE:
		txt.setFillColor(idleColor);
		break;
	case BTN_HOVER:
		txt.setFillColor(hoverColor);
		break;
	case BTN_ACTIVE:
		txt.setFillColor(activeColor);
		break;
	default:
		break;
	}

	// play sound when the buttons are active
	if (!isHighlighted && buttonState == BTN_HOVER)
	{
		isHighlighted = true;
		game.buttonHover.sound.play();
	}
	else if (isHighlighted && buttonState == BTN_ACTIVE)
	{
		isClicked = true;
		game.buttonClick.sound.play();
	}
	else if (buttonState == BTN_IDLE)
	{
		isHighlighted = false;
		isClicked = false;
	}
}

const bool Button::IsPressed() const
{
	if (buttonState == BTN_ACTIVE) return true;

	return false;
}

void Button::Draw(sf::RenderWindow& window)
{
	window.draw(txt);
}
