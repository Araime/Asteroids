#pragma once

#include "Constants.h"
#include "Entity.h"

class Pickup : public Entity
{
public:
	Pickup();

	virtual void ApplyEffect() {};
};
