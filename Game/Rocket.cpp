#include "Rocket.h"

Rocket::Rocket()
{
	name = "rocket";
}

void Rocket::Update(const float deltaTime)
{
	deltaX = cos(angle * DEGREES_TO_RADIANS) * ROCKET_ACCELERATION;
	deltaY = sin(angle * DEGREES_TO_RADIANS) * ROCKET_ACCELERATION;

	xcor += deltaX * deltaTime;
	ycor += deltaY * deltaTime;

	// check if it's beyond the edge of the screen
	if (xcor > SCREEN_WIDTH || xcor < 0 || ycor > FIELD_HEIGHT || ycor < 0)
	{
		isAlive = false;
	}
}