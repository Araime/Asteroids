#include "LaserPickup.h"

#include "Game.h"

void LaserPickup::ApplyEffect(Game& game)
{
	if (game.player->laserWeaponLvl < MAX_LASER_LVL)
	{
		game.player->laserWeaponLvl += 1;
	}

	// play pickup sound
	game.laserPickupSnd.sound.play();
}
