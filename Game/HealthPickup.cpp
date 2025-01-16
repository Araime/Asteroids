#include "HealthPickup.h"

#include "Game.h"

void HealthPickup::ApplyEffect(Game& game)
{
	game.player->health = 100.f;
	game.UI.UpdateUIHealthBar(game.player->health);
}
