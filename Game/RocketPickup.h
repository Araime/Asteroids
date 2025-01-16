#pragma once

#include "Pickup.h"

class RocketPickup : public Pickup
{
public:
	virtual void ApplyEffect(Game& game) override;
};
