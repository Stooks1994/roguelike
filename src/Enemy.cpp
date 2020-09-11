#include "Enemy.h"
#include "TextureManager.h"

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

}

void Enemy::update(double dt) {
	xPos += enemyMovement->updateXPos(xPos, yPos, stats.movespeed, dt);
	yPos += enemyMovement->updateYPos(yPos, xPos, stats.movespeed, dt);

	if (stats.curr_hp <= 0) {
		destroyed = true;
	}
}

void Enemy::render() {
	if (!destroyed) {
		destRect.x = (int) xPos;
		destRect.y = (int) yPos;
		SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
	} else {
		delete this;
	}
}
