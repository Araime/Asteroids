#pragma once

#include "Constants.h"
#include "Entity.h"

class Pickup : public Entity
{
public:
	float lifetime = 0.f;

	Pickup();

	virtual void Update(const float deltaTime) override;
};
