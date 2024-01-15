#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Entity.h"

struct Game;

enum class Weapon
{
	Laser = 0,
	Rocket,
};

class Ship : public Entity
{
public:
	Weapon weapon = Weapon::Laser;

	int maxSpeed = 5;
	int ships = 3;
	float health = 100.f;
	float rocketX = -20.f;

	bool isAccelerating = false;
	bool isDestroyed = false;

	Ship()
	{
		name = "player";
	}

	void Update()
	{
		if (isAccelerating)
		{
			dx += cos(angle * DEGTORAD) * 0.2f;
			dy += sin(angle * DEGTORAD) * 0.2f;
		}
		else
		{
			dx *= 0.99f;
			dy *= 0.99f;
		}

		float speed = sqrt(dx * dx + dy * dy);

		if (speed > maxSpeed)
		{
			dx *= maxSpeed / speed;
			dy *= maxSpeed / speed;
		}

		xcor += dx;
		ycor += dy;

		// check if it's beyond the edge of the screen
		if (xcor > SCREEN_WIDTH)
		{
			xcor = 0.f;
		}
		if (xcor < 0)
		{
			xcor = SCREEN_WIDTH;
		}
		if (ycor > FIELD_HEIGHT)
		{
			ycor = 0.f;
		}
		if (ycor < 0)
		{
			ycor = FIELD_HEIGHT;
		}
	}
};

void HandlePlayerInput(Game& game);

void MakeShot(Game& game, float xcor);

void UpdateShipSprite(Game& game);

void TakeDamage(Game& game, const float damage);

void RestartPlayer(Game& game);
