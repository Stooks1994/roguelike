#ifndef SRC_PLAYER_H_
#define SRC_PLAYER_H_

#include "Game.h"
#include "GameObject.h"
#include "ProjectileManager.h"

enum Direction {UP, DOWN, LEFT, RIGHT};

class Player : public GameObject {

public:
	Player(const char* textureSheet, int x, int y);
	virtual ~Player();

	void update(double dt);
	void handleEvents();
	void render();

private:
	double xVel;
	double yVel;
	double movespeed;
	int currDir;

	bool firing;
	int firingDir;
	double fireCD_max;
	double fireCD_curr;
	ProjectileManager* projectileManager;
};

#endif /* SRC_PLAYER_H_ */
