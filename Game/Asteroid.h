#pragma once

#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Entity.h"

class Asteroid : public Entity
{
public:
	Asteroid();

	virtual void Update(const float deltaTime) override;
};