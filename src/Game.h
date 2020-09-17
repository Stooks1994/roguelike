#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "EntityManager.h"
#include <iostream>

class Game {

public:
	Game();
	virtual ~Game();

	void init(const char* title, int xPos, int yPos, int w, int h, bool fs);
	void update(double dt);
	void render(SDL_Renderer* rend);
	void clean();
	void handleEvents();

	bool running() { return isRunning; }

	static SDL_Renderer* renderer;
	static SDL_Event event;
	static EntityManager* entityManager;

private:
	bool isRunning;
	SDL_Window* window;
};

#endif
