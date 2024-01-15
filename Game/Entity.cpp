#include "Entity.h"

Entity::Entity()
{
	isAlive = true;
}

void Entity::SetParams(Animation& a, float x, float y, float Angle, float radius)
{
	xcor = x;
	ycor = y;
	anim = a;
	angle = Angle;
	rad = radius;
}

void Entity::Draw(sf::RenderWindow& win)
{
	anim.sprite.setPosition(xcor, ycor);
	anim.sprite.setRotation(angle + 90.f);
	win.draw(anim.sprite);
}