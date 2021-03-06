#ifndef SRC_PLAYER_H_
#define SRC_PLAYER_H_

#include "Game.h"
//#include "ProjectileManager.h"

enum Direction {UP, DOWN, LEFT, RIGHT};

class Player {

public:
	Player(const char* textureSheet, int x, int y);
	virtual ~Player();

	void update(double dt);
	void handleEvents();
	void render(SDL_Renderer* rend);

	void dealDamageToPlayer(double damage);
	void alterPlayerByConsumable(int consumableType);

private:
	double xVel;
	double yVel;
	double xPos;
	double yPos;
	double movespeed;
	int currDir;
	int money;

	bool firing;
	int firingDir;
	double fireCD_max;
	double fireCD_curr;
	//ProjectileManager* projectileManager;

	double curr_HP;
	double max_HP;
	double damageTakenCD_max;
	double damageTakenCD_curr;

	SDL_Rect srcRect, destRect;
	SDL_Texture* objectTexture;

};

#endif /* SRC_PLAYER_H_ */
