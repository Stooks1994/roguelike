#include "ConsumableMoney.h"
#include "TextureManager.h"

ConsumableMoney::ConsumableMoney(double xPosition, double yPosition) {
	isDestroyed = false;
	xPos = xPosition;
	yPos = yPosition;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.h = destRect.w = 32;

	srcRect.x = srcRect.y = 0;
	srcRect.h = srcRect.w = 32;

	objectTexture = TextureManager::loadTexture("gold.png");
}

ConsumableMoney::~ConsumableMoney() {
	// TODO Auto-generated destructor stub
}

