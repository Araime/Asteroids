#include "Asteroid.h"

Asteroid::Asteroid()
{
	name = "asteroid";

	dx = float(rand() % ASTEROID_MAX_SPEED - ASTEROID_MIN_SPEED);
	if (dx == 0)
	{
		dx = DELTA_XY[rand() % DELTA_XY.size()];
	}

	dy = float(rand() % ASTEROID_MAX_SPEED - ASTEROID_MIN_SPEED);
	if (dy == 0)
	{
		dy = DELTA_XY[rand() % DELTA_XY.size()];
	}
}

void Asteroid::Update()
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