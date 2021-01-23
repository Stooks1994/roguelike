#ifndef SRC_CONSUMABLEMONEY_H_
#define SRC_CONSUMABLEMONEY_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Consumable.h"

class ConsumableMoney : public Consumable {
public:
	ConsumableMoney(double xPosition, double yPosition);
	virtual ~ConsumableMoney();
};

#endif /* SRC_CONSUMABLEMONEY_H_ */
