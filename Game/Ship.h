#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Entity.h"

namespace AsteroidsGame
{
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

		int ships = 3;
		float health = 100.f;

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


			int maxSpeed = 5;
			float speed = sqrt(dx * dx + dy * dy);

			if (speed > maxSpeed)
			{
				dx *= maxSpeed / speed;
				dy *= maxSpeed / speed;
			}

			xcor += dx;
			ycor += dy;

			// check if it's beyond the edge of the screen
			if (xcor > WIDTH)
			{
				xcor = 0.f;
			}
			if (xcor < 0)
			{
				xcor = WIDTH;
			}
			if (ycor > HEIGHT)
			{
				ycor = 0.f;
			}
			if (ycor < 0)
			{
				ycor = HEIGHT;
			}
		}
	};

	void HandlePlayerInput(Game& game);

	void MakeShot(Game& game);

	void UpdateShipSprite(Game& game);

	void TakeDamage(Game& game, const float damage);

	void RestartPlayer(Game& game);
}