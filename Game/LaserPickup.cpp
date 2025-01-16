#include "LaserPickup.h"

#include "Game.h"

void LaserPickup::ApplyEffect(Game& game)
{
	// play pickup sound
	game.laserPickupSnd.sound.play();
}
