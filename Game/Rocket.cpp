#include "Rocket.h"

Rocket::Rocket()
{
	name = "rocket";
}

void Rocket::Update()
{
	dx = cos(angle * DEGTORAD) * ROCKET_SPEED;
	dy = sin(angle * DEGTORAD) * ROCKET_SPEED;
	xcor += dx;
	ycor += dy;

	// check if it's beyond the edge of the screen
	if (xcor > SCREEN_WIDTH || xcor < 0 || ycor > FIELD_HEIGHT || ycor < 0)
	{
		isAlive = false;
	}
}