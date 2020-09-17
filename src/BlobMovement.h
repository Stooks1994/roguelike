#ifndef SRC_BLOBMOVEMENT_H_
#define SRC_BLOBMOVEMENT_H_

#include "MovementAI.h"

class BlobMovement : public MovementAI {

public:
	double updateXPos(double currXPos, double currYPos, double currXVel, double dt);
	double updateYPos(double currYPos, double currXPos, double currYVel, double dt);

private:
	double directionChangeCD_max = 1;
	double directionChangeCD_curr = 1;
	int currDir = AI_RIGHT;
};

#endif /* SRC_BLOBMOVEMENT_H_ */
