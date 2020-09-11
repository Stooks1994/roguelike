#ifndef SRC_PROJECTILE_H_
#define SRC_PROJECTILE_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Projectile {
public:
	Projectile(const char* textureSheet, double x, double y, double vel_x, double vel_y, int src_x, int src_y);
	virtual ~Projectile();

	void update(double dt);
	void render();
	bool isDestroyed() { return destroyed; }

private:
	double xVel;
	double yVel;
	double xPos;
	double yPos;
	bool destroyed;

	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;

};

#endif /* SRC_PROJECTILE_H_ */
