#pragma once
// PCH.h : #include <SFML/Graphics.hpp>
// PCH.h : Constants.h 
#include "PCH.h"
#include "Entity.h"

class Rocket : public Entity
{
public:
	Rocket();

	void Update();
};