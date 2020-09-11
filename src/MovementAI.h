#ifndef SRC_MOVEMENTAI_H_
#define SRC_MOVEMENTAI_H_

#include "Player.h"

class MovementAI {

public:
	MovementAI();
	virtual ~MovementAI();

	virtual double updateXPos(double currXPos, double currYPos, double currXVel, double dt);
	virtual double updateYPos(double currYpos, double currXPos, double currYVel, double dt);

};

#endif /* SRC_MOVEMENTAI_H_ */
