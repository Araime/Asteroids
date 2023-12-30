#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Entity.h"

namespace AsteroidsGame
{
	class Rocket : public Entity
	{
	public:
		Rocket()
		{
			name = "rocket";
		}

		void Update()
		{
			dx = cos(angle * DEGTORAD) * 8.f;
			dy = sin(angle * DEGTORAD) * 8.f;
			xcor += dx;
			ycor += dy;

			// check if it's beyond the edge of the screen
			if (xcor > SCREEN_WIDTH || xcor < 0 || ycor > SCREEN_HEIGHT || ycor < 0)
			{
				isAlive = false;
			}
		}
	};
}