#ifndef SRC_ENEMY_H_
#define SRC_ENEMY_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Enemy {

public:
	Enemy(const char* textureSheet, double xPosition, double yPosition, double hp);
	virtual ~Enemy();

	void update(double dt);
	void render();
	bool isDestroyed() { return destroyed; }

private:
	double xVel, yVel;
	double xPos, yPos;
	bool destroyed;

	double max_hp, curr_hp;

	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
};

#endif /* SRC_ENEMY_H_ */
