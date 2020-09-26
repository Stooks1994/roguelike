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

void Projectile::update(double dt, std::vector<Enemy*> enemies) {
	xPos += xVel * dt;
	yPos += yVel * dt;

	checkEnemyCollisions(xPos, yPos, enemies);

	//Destroy if projectile reaches edge of screen
	if (xPos < 0) destroyed = true;
	if (xPos + 16 > 800) destroyed = true;
	if (yPos < 0) destroyed = true;
	if (yPos + 8 > 640) destroyed = true;
}

void Projectile::render(SDL_Renderer* rend) {
	if (!destroyed) {
		destRect.x = (int) xPos;
		destRect.y = (int) yPos;
		SDL_RenderCopy(rend, objectTexture, &srcRect, &destRect);
	} else {
		delete this;
	}
}

bool Projectile::checkEnemyCollisions(double currXPos, double currYPos, std::vector<Enemy*> enemies) {
	bool collision = false;

	for (auto& enemy : enemies) {
		if ((currXPos > enemy->xPos && currXPos < enemy->xPos + 32) || (currXPos + 32 > enemy->xPos && currXPos + 32 <= enemy->xPos + 32)) {
			if ((currYPos > enemy->yPos && currYPos < enemy->yPos + 32) || (currYPos + 32 > enemy->yPos && currYPos+32 <= enemy->yPos + 32)) {
				collision = true;
				destroyed = true;
				enemy->setCurrHealth(-25);
			}
		}
	}

	return collision;
}

