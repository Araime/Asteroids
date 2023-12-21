#include "Ship.h"
#include "Game.h"

namespace AsteroidsGame
{
	void UpdateShip(Game& game, const float& currentTime, float& lastTime)
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
		else if(currentTime - lastTime > DESTROY_COLLDOWN)
		{
			game.player->SetParams(game.sShip, float(WIDTH / 2), float(HEIGHT / 2), 0.f, 20.f);
			game.player->dx = 0;
			game.player->dy = 0;
			game.player->isDestroyed = false;
		}
	}
}