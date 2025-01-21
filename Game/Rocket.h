#pragma once

#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Entity.h"

class Rocket : public Entity
{
public:
	Rocket();

	virtual void Update(const float deltaTime) override;
};