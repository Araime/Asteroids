#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Entity.h"


namespace AsteroidsGame
{
	class Asteroid : public Entity
	{
	public:
		Asteroid()
		{
			dx = float(rand() % 8 - 4);
			dy = float(rand() % 8 - 4);
			name = "asteroid";
		}

		void Update()
		{
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
}