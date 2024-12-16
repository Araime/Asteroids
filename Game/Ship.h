#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Entity.h"

class Game;

enum class Weapon
{
	Laser = 0,
	Rocket,
};

class Ship : public Entity
{
public:
	Weapon weapon = Weapon::Laser;

	int maxSpeed = SHIP_MAX_SPEED;
	int ships = SHIP_LIFES;
	float health = SHIP_HEALTH;
	float rocketX = -20.f;

	bool isAccelerating = false;
	bool isDestroyed = false;

	Ship();

	virtual void Update() override;

	void HandlePlayerInput(Game& game);

	void ChangeWeapon(Game& game);

	void MakeShot(Game& game, float xcor);

	void UpdateShipSprite(Game& game);

	void TakeDamage(Game& game, const float damage);

	void RestartPlayer(Game& game);
};