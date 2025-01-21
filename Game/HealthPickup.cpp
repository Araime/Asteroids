#include "HealthPickup.h"

#include "Game.h"

void HealthPickup::ApplyEffect(Game& game)
{
	// restore the player's health and update the UI
	game.player->health = SHIP_HEALTH;
	game.UI.UpdateUIHealthBar(game.player->health);

	// play pickup sound
	game.healthPickupSnd.sound.play();
}
