#pragma once
#include <SFML/Graphics.hpp>

namespace AsteroidsGame
{
	struct Animation
	{
		float frame = 0.f;
		float speed = 0.f;
		bool isFinished = false;
		sf::Sprite sprite;
		std::vector<sf::IntRect> frames;

		Animation() {}

		// create frames of animation
		void SetAnimation(sf::Texture& t, int x, int y, int w, int h, int count, float Speed)
		{
			frame = 0.f;
			speed = Speed;

			for (int i = 0; i < count; i++)
			{
				frames.push_back(sf::IntRect(x + i * w, y, w, h));
			}

			sprite.setTexture(t);
			sprite.setOrigin(w / 2.f, h / 2.f);
			sprite.setTextureRect(frames[0]);
		}

		// update animation
		void Update()
		{
			frame += speed;
			int frames_num = int(frames.size());

			if (frame >= frames_num)
			{
				frame -= frames_num;
				isFinished = true;
			}

			if (frames_num > 0)
			{
				sprite.setTextureRect(frames[int(frame)]);
			}
		}

		bool IsAnimationEnd()
		{
			return frame + speed >= frames.size();
		}
	};
}