#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Entity.h"

class Laser : public Entity
{
public:
	Laser();

	void Update();
};