#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Entity.h"

class Asteroid : public Entity
{
public:
	Asteroid()
	{
		dx = float(rand() % 8 - 4);
		if (dx == 0)
		{
			dx = DELTA_XY[rand() % DELTA_XY.size()];
		}

		dy = float(rand() % 8 - 4);
		if (dy == 0)
		{
			dy = DELTA_XY[rand() % DELTA_XY.size()];
		}

		name = "asteroid";
	}

	void Update()
	{
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
