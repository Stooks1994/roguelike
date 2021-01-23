#ifndef SRC_CONSUMABLEHEART_H_
#define SRC_CONSUMABLEHEART_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Consumable.h"

class ConsumableHeart : public Consumable {
public:
	ConsumableHeart(double xPosition, double yPosition);
	virtual ~ConsumableHeart();
};

#endif /* SRC_CONSUMABLEHEART_H_ */
