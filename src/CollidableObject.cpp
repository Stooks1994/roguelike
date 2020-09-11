#include "CollidableObject.h"

CollidableObject::CollidableObject() {
	x = 0;
	y = 0;
	w = 0;
	h = 0;
}

CollidableObject::CollidableObject(int xPos, int yPos, int width, int height) {
	x = xPos;
	y = yPos;
	w = width;
	h = height;
}

