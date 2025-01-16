#include "ShieldPickup.h"

#include "Game.h"

void ShieldPickup::ApplyEffect(Game& game)
{
	// play pickup sound
	game.shieldPickupSnd.sound.play();
}
