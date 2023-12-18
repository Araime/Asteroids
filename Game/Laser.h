#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Game.h"

namespace AsteroidsGame
{
	struct Game;

	class Laser : public Entity
	{
	public:
		Laser()
		{
			name = "laser";
		}

		void Update()
		{
			dx = cos(angle * DEGTORAD) * 12.f;
			dy = sin(angle * DEGTORAD) * 12.f;
			xcor += dx;
			ycor += dy;

			// check if it's beyond the edge of the screen
			if (xcor > WIDTH || xcor < 0 || ycor > HEIGHT || ycor < 0)
			{
				isAlive = false;
			}
		}
	};
}