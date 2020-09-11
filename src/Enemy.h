#ifndef SRC_ENEMY_H_
#define SRC_ENEMY_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "MovementAI.h"

struct Stats {
	double max_hp;
	double curr_hp;
	double movespeed;

	Stats(double mhp, double chp, double ms) {
		max_hp = mhp;
		curr_hp = chp;
		movespeed = ms;
	}

	Stats() {
		max_hp = 1;
		curr_hp = 1;
		movespeed = 0;
	}
};

class Enemy {

public:
	Enemy(const char* textureSheet, double xPosition, double yPosition, Stats enemyStats, MovementAI* movementAI);
	virtual ~Enemy();

	void update(double dt);
	void render();
	bool isDestroyed() { return destroyed; }

private:
	double xVel, yVel;
	double xPos, yPos;
	bool destroyed;

	Stats stats;

	MovementAI* enemyMovement;

	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
};

#endif /* SRC_ENEMY_H_ */
