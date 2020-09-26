#include "EntityManager.h"

/************************************/
/*** Constructors and Destructors ***/
/************************************/
EntityManager::EntityManager() {

}

EntityManager::~EntityManager() {

}
/***********************************/


/************************************/
/******** Render and Update *********/
/************************************/
void EntityManager::render(SDL_Renderer* rend) {
	for (auto& enemy : enemies) {
		enemy->render(rend);
	}

	for (auto& projectile : projectiles) {
		projectile->render(rend);
	}
}

void EntityManager::update(double dt) {
	for (auto& enemy : enemies) {
		enemy->update(dt, collidableObjects, enemies);
	}

	for (auto& projectile : projectiles) {
		projectile->update(dt, enemies);
	}

	removeDestroyedEnemies();
	removeDestroyedProjectiles();
}
/************************************/


/************************************/
/********** Add Objects *************/
/************************************/
void EntityManager::addEnemy(Enemy* enemy) {
	enemies.push_back(enemy);
}

void EntityManager::addCollidableObject(CollidableObject* object) {
	collidableObjects.push_back(object);
}

void EntityManager::addProjectile(Projectile* projectile) {
	projectiles.push_back(projectile);
}
/************************************/


/************************************/
/********* Remove Objects ***********/
/************************************/
void EntityManager::removeDestroyedEnemies() {
	std::vector<Enemy*> temp;

	for (auto& enemy : enemies) {
		if (!enemy->isDestroyed()) {
			temp.push_back(enemy);
		}
	}

	enemies = temp;
}

void EntityManager::removeDestroyedProjectiles() {
	std::vector<Projectile*> temp;

	for (auto& proj : projectiles) {
		if (!proj->isDestroyed()) {
			temp.push_back(proj);
		}
	}

	projectiles = temp;
}
/************************************/


/************************************/
/******* Collision Handling *********/
/************************************/
bool EntityManager::checkCollisions(int x, int y, int w, int h) {
	bool collision = false;

	for (auto& c : collidableObjects) {
		if ((x > c->x && x < c->x + c->w) || (x + 32 > c->x && x + 32 <= c->x + c->w)) {
			if ((y > c->y && y < c->y + c->h) || (y + 32 > c->y && y+32 <= c->y + c->h)) {
				collision = true;
			}
		}
	}

	return collision;
}
/************************************/


