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
	float protectionTimer = 0.f;

	int rocketWeaponLvl = 1;
	int laserWeaponLvl = 1;

	bool isProtected = false;
	bool isAccelerating = false;
	bool isDestroyed = false;

	Animation shieldAnim;

	Ship();

	virtual void Update(float deltaTime) override;

	void HandlePlayerInput(Game& game, float deltaTime);

	void ChangeWeapon(Game& game);

	void MakeShot(Game& game);

	void LaserFire(Game& game);

	void RocketFire(Game& game);

	void UpdateShipSprite(Game& game);

	void TakeDamage(Game& game, const float damage);

	void HandlePlayerRessurection(Game& game);

	void RessurectPlayer(Game& game);

	void ResetPlayerParams(Game& game);

	void ActivateShield(Game& game);

	void UpdateShield(Game& game, float deltaTime);

	void UpdateShieldSprite();

	void DrawShieldSprite(sf::RenderWindow& win);

	void DeactivateShield(Game& game);
};