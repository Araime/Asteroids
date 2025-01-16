#pragma once

#include "Pickup.h"

class HealthPickup : public Pickup
{
public:
	virtual void ApplyEffect(Game& game) override;
};