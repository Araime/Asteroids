#include "Sound.h"

#include "Constants.h"

Music::Music()
{
	music.setVolume(MUSIC_VOLUME);
}

void Music::PlayMusic(const std::string path)
{
	music.openFromFile(path);
	music.play();
}