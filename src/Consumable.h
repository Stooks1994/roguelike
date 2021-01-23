#ifndef SRC_CONSUMABLE_H_
#define SRC_CONSUMABLE_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Consumable {

public:
	Consumable();
	virtual ~Consumable();

	void setIsDestroyed(bool value) { isDestroyed = value; };
	virtual void render(SDL_Renderer* rend);
	virtual void update(double dt);
	//virtual void alterPlayer();

	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;

	bool isDestroyed;
	double xPos, yPos;
};

#endif /* SRC_CONSUMABLE_H_ */
