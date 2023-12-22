#pragma once
#include <SFML/Audio.hpp>

namespace AsteroidsGame
{
	struct Sound
	{
		sf::SoundBuffer buffer;
		sf::Sound sound;
	};

	struct Music
	{
		sf::Music music;
	};
}