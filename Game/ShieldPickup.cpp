#include "ShieldPickup.h"

#include "Game.h"

void ShieldPickup::ApplyEffect(Game& game)
{
	// Activate shield
	game.player->ActivateShield(game);

	// play pickup sound
	game.shieldPickupSnd.sound.play();
}
