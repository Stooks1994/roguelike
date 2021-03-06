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

	for (auto& consumable : consumables) {
		consumable->render(rend);
	}
}

void EntityManager::update(double dt) {
	for (auto& enemy : enemies) {
		enemy->update(dt, collidableObjects, enemies);
	}

	for (auto& projectile : projectiles) {
		projectile->update(dt, enemies);
	}

	for (auto& consumable : consumables) {
		consumable->update(dt);
	}

	removeDestroyedEnemies();
	removeDestroyedProjectiles();
	removeDestroyedConsumables();
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

void EntityManager::addConsumable(Consumable* consumable) {
	consumables.push_back(consumable);
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

void EntityManager::removeDestroyedConsumables() {
	std::vector<Consumable*> temp;

	for (auto& cons : consumables) {
		if (!cons->isDestroyed) {
			temp.push_back(cons);
		}
	}

	consumables = temp;
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

bool EntityManager::checkCollisionWithEnemy(int x, int y, int w, int h) {
	bool collision = false;

	for (auto& e : enemies) {
		if ((x > e->xPos && x < e->xPos + 32) || (x + 32 > e->xPos && x + 32 <= e->xPos + 32)) {
			if ((y > e->yPos && y < e->yPos + 32) || (y + 32 > e->yPos && y+32 <= e->yPos + 32)) {
				collision = true;
			}
		}
	}

	return collision;
}

int EntityManager::checkCollisionWithConsumable(int x, int y, int w, int h) {
	int collision = 0;

	for (auto& e : consumables) {
		if ((x > e->xPos && x < e->xPos + 32) || (x + 32 > e->xPos && x + 32 <= e->xPos + 32)) {
			if ((y > e->yPos && y < e->yPos + 32) || (y + 32 > e->yPos && y+32 <= e->yPos + 32)) {
				collision = e->getType();
				e->setIsDestroyed(true);
			}
		}
	}

	return collision;
}

/************************************/


