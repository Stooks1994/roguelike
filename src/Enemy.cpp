#include "Enemy.h"
#include "TextureManager.h"
#include "MovementAI.h"

Enemy::Enemy(const char* textureSheet, double xPosition, double yPosition, Stats enemyStats, MovementAI* movementAI) {
	objectTexture = TextureManager::loadTexture(textureSheet);
	enemyMovement = movementAI;
	xPos = xPosition;
	yPos = yPosition;
	xVel = 0;
	yVel = 0;

	destroyed = false;

	stats.max_hp = enemyStats.max_hp;
	stats.curr_hp = enemyStats.curr_hp;
	stats.movespeed = enemyStats.movespeed;

	srcRect.h = srcRect.w = 32;
	destRect.h = destRect.w = 32;
}

Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}

void Enemy::update(double dt, std::vector<CollidableObject*> collidableObjects) {
	/*
	int deltaX = enemyMovement->updateXPos(xPos, yPos, stats.movespeed, dt);
	int deltaY = enemyMovement->updateYPos(yPos, xPos, stats.movespeed, dt);

	bool collisionFlagX = false;
	bool collisionFlagY = false;
	for (auto& object : collidableObjects) {
		if ((xPos + deltaX > object->x && xPos + deltaX < object->x + object->w) || (xPos + deltaX + 32 > object->x && xPos + deltaX + 32 <= object->x + object->w)) {
			collisionFlagX = true;
		}

		if ((yPos + deltaY > object->y && yPos + deltaY < object->y + object->h) || (yPos + deltaY + 32 > object->y && yPos + deltaY + 32 <= object->y + object->h)) {
			collisionFlagY = true;
		}
	}

	if (!collisionFlagX) {
		xPos += deltaX;
	}

	if (!collisionFlagY) {
		yPos += deltaY;
	}
	*/

	xPos += enemyMovement->updateXPos(xPos, yPos, stats.movespeed, dt);
	yPos += enemyMovement->updateYPos(yPos, xPos, stats.movespeed, dt);

	if (stats.curr_hp <= 0) {
		destroyed = true;
	}
}

void Enemy::render(SDL_Renderer* rend) {
	if (!destroyed) {
		destRect.x = (int) xPos;
		destRect.y = (int) yPos;
		SDL_RenderCopy(rend, objectTexture, &srcRect, &destRect);
	} else {
		delete this;
	}
}

