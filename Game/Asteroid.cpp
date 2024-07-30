#include "Asteroid.h"

Asteroid::Asteroid()
{
	name = "asteroid";

	deltaX = static_cast<float>(rand() % ASTEROID_MAX_SPEED - ASTEROID_MIN_SPEED);
	if (deltaX == 0)
	{
		deltaX = DELTA_XY[rand() % DELTA_XY.size()];
	}

	deltaY = static_cast<float>(rand() % ASTEROID_MAX_SPEED - ASTEROID_MIN_SPEED);
	if (deltaY == 0)
	{
		deltaY = DELTA_XY[rand() % DELTA_XY.size()];
	}
}

void Asteroid::Update()
{
	xcor += deltaX;
	ycor += deltaY;

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