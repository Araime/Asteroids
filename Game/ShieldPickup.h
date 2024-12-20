#pragma once

#include "Pickup.h"

class ShieldPickup : public Pickup
{
public:
	virtual void ApplyEffect() override;
};
