#include "../header/Animation.h"

void Animation::SetAnimation(sf::Texture& t, int x, int y, int w, int h, int count, float Speed)
{
	frame = 0.f;
	framesSpeed = Speed;

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
	int frames_num = int(frames.size());

	if (frame >= frames_num)
	{
		frame -= frames_num;
	}

	if (frames_num > 0)
	{
		sprite.setTextureRect(frames[int(frame)]);
	}
}

bool Animation::IsAnimationEnd()
{
	return frame + framesSpeed >= frames.size();
}
