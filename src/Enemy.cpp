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

	destRect.x = xPos;
	destRect.y = yPos;

	srcRect.x = srcRect.y = 0;
	srcRect.h = srcRect.w = 32;
	destRect.h = destRect.w = 32;
}

Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}

void Enemy::update(double dt, std::vector<CollidableObject*> collidableObjects) {
	xPos += enemyMovement->updateXPos(xPos, yPos, stats.movespeed, dt, collidableObjects);
	yPos += enemyMovement->updateYPos(yPos, xPos, stats.movespeed, dt, collidableObjects);

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
		printf("deleted\n");
		delete this;
	}
}

