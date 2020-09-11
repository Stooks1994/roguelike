#ifndef MAP_H_
#define MAP_H_

#include "Game.h"

class Map {

public:
	Map();
	virtual ~Map();

	void loadMap(const char* fileName);
	void drawMap();

private:
	SDL_Rect src, dest;
	SDL_Texture* texture;

	int map[20][25];
};

#endif /* MAP_H_ */
