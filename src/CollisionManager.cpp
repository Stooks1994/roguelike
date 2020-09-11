#include "CollisionManager.h"

void CollisionManager::addObject(int x, int y, int w, int h) {
	CollidableObject* temp = new CollidableObject(x, y, w, h);
	objects.push_back(temp);
}

bool CollisionManager::checkCollisions(int x, int y, int w, int h) {
	bool collision = false;

	for (auto& c : objects) {
		if ((x > c->x && x < c->x + c->w) || (x + 32 > c->x && x + 32 <= c->x + c->w)) {
			if ((y > c->y && y < c->y + c->h) || (y + 32 > c->y && y+32 <= c->y + c->h)) {
				collision = true;
			}
		}
	}

	return collision;
}

void CollisionManager::print() {
	for (auto& c : objects) {
		int x = c->x;
		int y = c->y;

		printf("%d %d\n", x, y);
	}
}

