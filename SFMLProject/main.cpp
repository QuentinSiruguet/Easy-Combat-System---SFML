#include "Game.h"

void main()
{
	Game game;
	srand(static_cast<unsigned>(time(0)));

	while (game.isRunning())
	{
		game.update();

		game.render();
	}
}