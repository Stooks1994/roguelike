#ifndef SRC_MOVEMENTAI_H_
#define SRC_MOVEMENTAI_H_

#include "CollidableObject.h"
#include <stdio.h>
#include <vector>

enum AIDirection {AI_UP, AI_DOWN, AI_LEFT, AI_RIGHT};

class MovementAI {

public:
	MovementAI();
	virtual ~MovementAI();

	virtual double updateXPos(double currXPos, double currYPos, double currXVel, double dt, std::vector<CollidableObject*> collidableObjects);
	virtual double updateYPos(double currYpos, double currXPos, double currYVel, double dt, std::vector<CollidableObject*> collidableObjects);

};

#endif /* SRC_MOVEMENTAI_H_ */
