#include "ConsumableHeart.h"
#include "TextureManager.h"

ConsumableHeart::ConsumableHeart(double xPosition, double yPosition) {
	isDestroyed = false;
	xPos = xPosition;
	yPos = yPosition;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.h = destRect.w = 32;

	srcRect.x = srcRect.y = 0;
	srcRect.h = srcRect.w = 32;

	objectTexture = TextureManager::loadTexture("heart.png");

	consumableType = 2;
}

ConsumableHeart::~ConsumableHeart() {
	// TODO Auto-generated destructor stub
}

