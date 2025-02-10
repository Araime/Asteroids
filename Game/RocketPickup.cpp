#include "RocketPickup.h"

#include "Game.h"

void RocketPickup::ApplyEffect(Game& game)
{
	if (game.player->rocketWeaponLvl < MAX_ROCKET_LVL)
	{
		game.player->rocketWeaponLvl += 1;
	}

	// play pickup sound
	game.rocketPickupSnd.sound.play();
}
