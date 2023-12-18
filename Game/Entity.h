#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

namespace AsteroidsGame
{
	class Entity
	{
	public:
		float xcor = 0.f;
		float ycor = 0.f;
		float dx = 0.f;
		float dy = 0.f;
		float rad = 0.f;
		float angle = 0.f;
		bool isAlive;
		std::string name;
		Animation anim;

		Entity()
		{
			isAlive = true;
		}

		void SetParams(Animation& a, float x, float y, float Angle = 0.f, float radius = 1.f)
		{
			xcor = x;
			ycor = y;
			anim = a;
			angle = Angle;
			rad = radius;
		}

		virtual void Update() {};

		// rotate and draw the sprite 
		void Draw(sf::RenderWindow& win)
		{
			anim.sprite.setPosition(xcor, ycor);
			anim.sprite.setRotation(angle + 90.f);
			win.draw(anim.sprite);
		}

		virtual ~Entity() {};
	};
}