#pragma once
// PCH.h : #include <SFML/Graphics.hpp>
// PCH.h : Constants.h 
#include "PCH.h"
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
	bool isDeaccelerating = false;
	bool isBoosting = false;
	bool isDestroyed = false;

	bool isOutOfBounds = false; // New attribute to track out of bounds status
	sf::Vector2f CalculateIndicatorPosition(const sf::RenderWindow& window) const;

	Ship();

	void Update();

	void HandlePlayerInput(Game& game);

	void MakeShot(Game& game, float xcor);

	void UpdateShipSprite(Game& game);

	void TakeDamage(Game& game, const float damage);

	void RestartPlayer(Game& game);
};