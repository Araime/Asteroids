#include "Pickup.h"

Pickup::Pickup()
{
	name = "pickup";
}

void Pickup::Update(const float deltaTime)
{
	lifetime += deltaTime;

	if (lifetime >= PICKUP_MAXLIFETIME)
	{
		isAlive = false;
	}
}
