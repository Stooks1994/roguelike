#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "MovementAI.h"
#include "BlobMovement.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
CollisionManager* Game::collisionManager = new CollisionManager();
Map* map;
Player* player;

Enemy* blob;
MovementAI* enemyMovementAI;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xPos, int yPos, int w, int h, bool fs) {
	int flags = 0;

	if (fs) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xPos, yPos, w, h, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		isRunning = true;
	} else {
		isRunning = false;
	}

	struct Stats blobStats = Stats(50, 50, 50);
	enemyMovementAI = new BlobMovement();

	map = new Map();
	player = new Player("knight.png", 50, 50);
	blob = new Enemy("blob.png", 550, 550, blobStats, enemyMovementAI);
}

void Game::update(double dt) {
	//map->loadMap() 		pass in array stored in external file to change map
	player->update(dt);
	blob->update(dt);
}

void Game::render() {
	SDL_RenderClear(renderer);
	map->drawMap();
	player->render();
	blob->render();
	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	while(SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			isRunning = false;
		}

		player->handleEvents();
	}

}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

