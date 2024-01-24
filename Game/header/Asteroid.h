#pragma once
// PCH.h : #include <SFML/Graphics.hpp>
// PCH.h : #include "Constants.h"
#include "PCH.h"
#include "Entity.h"

class Asteroid : public Entity
{
public:
	Asteroid();

	void Update();
};