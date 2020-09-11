#include <iostream>
#include "Game.h"
#include "FrameTimer.h"

Game* game = nullptr;
FrameTimer timer;

int main(int argc, const char* argv[]) {
	game = new Game();
	game->init("roguelike", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	Uint32 minimum_t = 1000 / 6;
	Uint32 dt = 0;
	Uint32 last_t = 0;
	Uint32 curr_t = 0;

	while (game->running()) {
		curr_t = SDL_GetTicks();
		if (last_t < curr_t) {
			dt = curr_t - last_t;

			if (dt > minimum_t) {
				dt = minimum_t;
			}

			game->handleEvents();
			game->update(dt / 1000.f);
			game->render();

			last_t = curr_t;
		} else {
			SDL_Delay(1);
		}
	}


	game->clean();
	return 0;
}
