#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class TextureManager {
public:
	static SDL_Texture* loadTexture(const char* filename);
	static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

#endif /* TEXTUREMANAGER_H_ */
