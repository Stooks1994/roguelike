#include "Enemy.h"
#include "TextureManager.h"

Enemy::Enemy(const char* textureSheet, double xPosition, double yPosition, double hp) {
	objectTexture = TextureManager::loadTexture(textureSheet);
	xPos = xPosition;
	yPos = yPosition;
	xVel = 0;
	yVel = 0;

	destroyed = false;

	max_hp = curr_hp = 100.0;

	srcRect.h = srcRect.w = 32;
	destRect.h = destRect.w = 32;
}

Enemy::~Enemy() {

}

