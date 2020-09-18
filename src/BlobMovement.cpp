#include <cstdlib>
#include "BlobMovement.h"

double BlobMovement::updateXPos(double currXPos, double currYPos, double currXVel, double dt, std::vector<CollidableObject*> collidableObjects) {
	double newX;

	if (directionChangeCD_curr <= 0) {
		currDir = rand() % 4;
		directionChangeCD_curr = directionChangeCD_max;
	}

	switch(currDir) {
	case AI_UP: newX = 0; break;
	case AI_DOWN: newX = 0; break;
	case AI_LEFT: newX = - (currXVel * dt); break;
	case AI_RIGHT: newX = currXVel * dt; break;
	}

	// Bound blob to screen
	if (currXPos + newX < 0 || currXPos + newX + 32 > 800) {
		newX = 0;
	}

	if (checkCollisions(currXPos + newX, currYPos, collidableObjects)) {
		newX = 0;
	}

	directionChangeCD_curr -= dt;

	return newX;
}

double BlobMovement::updateYPos(double currYPos, double currXPos, double currYVel, double dt, std::vector<CollidableObject*> collidableObjects) {
	double newY;

	if (directionChangeCD_curr <= 0) {
		currDir = rand() % 4;
		directionChangeCD_curr = directionChangeCD_max;
	}

	switch(currDir) {
	case AI_UP: newY = -(currYVel * dt); break;
	case AI_DOWN: newY = currYVel * dt; break;
	case AI_LEFT: newY = 0; break;
	case AI_RIGHT: newY = 0; break;
	}

	// Bound blob to screen
	if (currYPos + newY < 0 || currYPos + newY + 32 > 640) {
		newY = 0;
	}

	if (checkCollisions(currXPos, currYPos + newY, collidableObjects)) {
		newY = 0;
	}

	directionChangeCD_curr -= dt;

	return newY;
}

bool BlobMovement::checkCollisions(double currXPos, double currYPos, std::vector<CollidableObject*> collidableObjects) {
	bool collision = false;

	for (auto& c : collidableObjects) {
		if ((currXPos > c->x && currXPos < c->x + c->w) || (currXPos + 32 > c->x && currXPos + 32 <= c->x + c->w)) {
			if ((currYPos > c->y && currYPos < c->y + c->h) || (currYPos + 32 > c->y && currYPos+32 <= c->y + c->h)) {
				collision = true;
			}
		}
	}

	return collision;
}
