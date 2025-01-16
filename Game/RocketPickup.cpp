#include "RocketPickup.h"

#include "Game.h"

void RocketPickup::ApplyEffect(Game& game)
{
	// play pickup sound
	game.rocketPickupSnd.sound.play();
}
