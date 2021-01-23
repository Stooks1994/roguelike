#include "Consumable.h"

Consumable::Consumable() {
	// TODO Auto-generated constructor stub

}

Consumable::~Consumable() {
	// TODO Auto-generated destructor stub
}

void Consumable::render(SDL_Renderer* rend) {
	if (!isDestroyed) {
		destRect.x = (int) xPos;
		destRect.y = (int) yPos;
		SDL_RenderCopy(rend, objectTexture, &srcRect, &destRect);
	}
}

void Consumable::update(double dt) {

}

