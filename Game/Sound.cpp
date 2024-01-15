#include "Sound.h"

Music::Music()
{
	music.setVolume(70.f);
}

void Music::PlayMusic(const std::string path)
{
	music.openFromFile(path);
	music.play();
}