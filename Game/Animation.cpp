#include "Animation.h"

void Animation::SetAnimation(sf::Texture& t, int x, int y, int w, int h, const int count, const float Speed)
{
	frame = 0.f;
	framesSpeed = Speed;
	framesNum = count;

	for (int i = 0; i < count; i++)
	{
		frames.push_back(sf::IntRect(x + i * w, y, w, h));
	}

	sprite.setTexture(t);
	sprite.setOrigin(static_cast<float>(w / 2), static_cast<float>(h / 2));
	sprite.setTextureRect(frames[0]);
}

void Animation::Update()
{
	frame += framesSpeed;

	if (frame >= framesNum)
	{
		frame -= framesNum;
	}

	if (framesNum > 0)
	{
		sprite.setTextureRect(frames[static_cast<int>(frame)]);
	}
}

bool Animation::IsAnimationEnd() const
{
	return frame + framesSpeed >= frames.size();
}
