#ifndef SRC_COLLISIONMANAGER_H_
#define SRC_COLLISIONMANAGER_H_

#include <stdio.h>
#include <vector>
#include "CollidableObject.h"

class CollisionManager {

public:
	bool checkCollisions(int x, int y, int w, int h);
	void addObject(int x, int y, int w, int h);
	void print();

private:
	std::vector<CollidableObject*> objects;
};

#endif /* SRC_COLLISIONMANAGER_H_ */
