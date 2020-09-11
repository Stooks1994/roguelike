#ifndef SRC_GAMEOBJECT_H_
#define SRC_GAMEOBJECT_H_

#include "Game.h"

class GameObject {

public:
	GameObject();
	GameObject(const char* textureSheet, int xPos, int yPos);
	virtual ~GameObject();

	virtual void update();
	virtual void update(double dt);
	virtual void render();

	double xPos;
	double yPos;

	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
};

#endif /* SRC_GAMEOBJECT_H_ */
