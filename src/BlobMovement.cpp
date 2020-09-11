#include <cstdlib>
#include "BlobMovement.h"

double BlobMovement::updateXPos(double currXPos, double currYPos, double currXVel, double dt) {
	double newX;

	if (directionChangeCD_curr <= 0) {
		currDir = rand() % 4;
		directionChangeCD_curr = directionChangeCD_max;
	}

	switch(currDir) {
	case UP: newX = 0; break;
	case DOWN: newX = 0; break;
	case LEFT: newX = - (currXVel * dt); break;
	case RIGHT: newX = currXVel * dt; break;
	}

	// Bound blob to screen
	if (currXPos + newX < 0 || currXPos + newX + 32 > 800) {
		newX = 0;
	}

	if (Game::collisionManager->checkCollisions(currXPos + newX, currYPos, 32, 32)) {
		newX = 0;
	}

	directionChangeCD_curr -= dt;

	return newX;
}

double BlobMovement::updateYPos(double currYPos, double currXPos, double currYVel, double dt) {
	double newY;

	if (directionChangeCD_curr <= 0) {
		currDir = rand() % 4;
		directionChangeCD_curr = directionChangeCD_max;
	}

	switch(currDir) {
	case UP: newY = -(currYVel * dt); break;
	case DOWN: newY = currYVel * dt; break;
	case LEFT: newY = 0; break;
	case RIGHT: newY = 0; break;
	}

	// Bound blob to screen
	if (currYPos + newY < 0 || currYPos + newY + 32 > 640) {
		newY = 0;
	}

	if (Game::collisionManager->checkCollisions(currXPos, currYPos + newY, 32, 32)) {
		newY = 0;
	}

	directionChangeCD_curr -= dt;

	return newY;
}

