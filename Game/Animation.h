#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
	float frame = 0.f;
	float framesSpeed = 0.f;
	sf::Sprite sprite;
	std::vector<sf::IntRect> frames;

	Animation() {};

	// create frames of animation
	void SetAnimation(sf::Texture& t, int x, int y, int w, int h, int count, float Speed);

	// update animation
	void Update();

	bool IsAnimationEnd();
};
