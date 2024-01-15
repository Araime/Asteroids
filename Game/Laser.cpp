#include "Laser.h"

Laser::Laser()
{
	name = "laser";
}

void Laser::Update()
{
	dx = cos(angle * DEGTORAD) * LASER_SPEED;
	dy = sin(angle * DEGTORAD) * LASER_SPEED;
	xcor += dx;
	ycor += dy;

	// check if it's beyond the edge of the screen
	if (xcor > SCREEN_WIDTH || xcor < 0 || ycor > FIELD_HEIGHT || ycor < 0)
	{
		isAlive = false;
	}
}