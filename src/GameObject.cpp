#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject() {
	objectTexture = nullptr;
	xPos = 0;
	yPos = 0;
}

GameObject::GameObject(const char* textureSheet, int x, int y) {
	objectTexture = TextureManager::loadTexture(textureSheet);
	xPos = x;
	yPos = y;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

GameObject::~GameObject() {
	// TODO Auto-generated destructor stub
}

void GameObject::render() {
	//Cast to integer here to avoid losing fractional portion at lower movespeeds
	destRect.x = (int) xPos;
	destRect.y = (int) yPos;
	SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
}

void GameObject::update() {

}

void GameObject::update(double dt) {

}

