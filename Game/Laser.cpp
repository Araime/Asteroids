#include "Laser.h"

Laser::Laser()
{
	name = "laser";
}

void Laser::Update(float deltaTime)
{
	deltaX = cos(angle * DEGREES_TO_RADIANS) * LASER_ACCELERATION;
	deltaY = sin(angle * DEGREES_TO_RADIANS) * LASER_ACCELERATION;
	xcor += deltaX;
	ycor += deltaY;

	// check if it's beyond the edge of the screen
	if (xcor > SCREEN_WIDTH || xcor < 0 || ycor > FIELD_HEIGHT || ycor < 0)
	{
		isAlive = false;
	}
}