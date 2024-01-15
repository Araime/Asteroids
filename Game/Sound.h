#pragma once
#include <SFML/Audio.hpp>

class Sound
{
public:
	sf::SoundBuffer buffer;
	sf::Sound sound;
};

class Music
{
public:
	sf::Music music;

	Music();

	void PlayMusic(const std::string path);
};
