#include "Projectile.h"
#include "TextureManager.h"

Projectile::Projectile(const char* textureSheet, double x, double y, double vel_x, double vel_y, int src_x, int src_y) {
	objectTexture = TextureManager::loadTexture(textureSheet);
	xPos = x;
	yPos = y;
	xVel = vel_x;
	yVel = vel_y;

	destroyed = false;

	srcRect.h = 16;
	srcRect.w = 16;
	srcRect.x = src_x;
	srcRect.y = src_y;

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

Projectile::~Projectile() {
	// TODO Auto-generated destructor stub
}

void Projectile::update(double dt) {
	xPos += xVel * dt;
	yPos += yVel * dt;

	if (xPos < 0) destroyed = true;
	if (xPos + 16 > 800) destroyed = true;
	if (yPos < 0) destroyed = true;
	if (yPos + 8 > 640) destroyed = true;
}

void Projectile::render() {
	if (!destroyed) {
		destRect.x = (int) xPos;
		destRect.y = (int) yPos;
		SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
	} else {
		delete this;
	}
}

