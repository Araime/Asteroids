#include "Ship.h"
#include "Game.h"

namespace AsteroidsGame
{
	void UpdateShipSprite(Game& game)
	{
		if (!game.player->isDestroyed)
		{
			// change sprite if ship is accelerated
			if (game.player->isAccelerating)
			{
				game.player->anim = game.sFlyingShip;
			}
			else
			{
				game.player->anim = game.sShip;
			}
		}
	}
}