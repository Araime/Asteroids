#pragma once

#include "Pickup.h"

class LaserPickup : public Pickup
{
public:
	virtual void ApplyEffect(Game& game) override;
};
