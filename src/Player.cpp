#include "Player.h"
#include "TextureManager.h"
#include "Projectile.h"

Player::Player(const char* textureSheet, int x, int y) {
	//projectileManager = new ProjectileManager();
	firing = false;
	firingDir = RIGHT;
	fireCD_max = 1.0;
	fireCD_curr = 0;

	objectTexture = TextureManager::loadTexture(textureSheet);
	xPos = x;
	yPos = y;
	currDir = RIGHT;

	xVel = 0;
	yVel = 0;
	movespeed = 200;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

	max_HP = 100;
	curr_HP = max_HP;
	damageTakenCD_max = 0.5;
	damageTakenCD_curr = 0;

	money = 0;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

void Player::handleEvents() {
	if (Game::event.type == SDL_KEYDOWN && Game::event.key.repeat == 0) {
		switch(Game::event.key.keysym.sym) {
		/*** movement ***/
		case SDLK_w: yVel -= movespeed; break;
		case SDLK_s: yVel += movespeed; break;
		case SDLK_a: xVel -= movespeed; currDir = LEFT; break;
		case SDLK_d: xVel += movespeed; currDir = RIGHT; break;

		/*** firing ***/
		case SDLK_RIGHT: firing = true; firingDir = RIGHT; break;
		case SDLK_LEFT: firing = true; firingDir = LEFT; break;
		case SDLK_UP: firing = true; firingDir = UP; break;
		case SDLK_DOWN: firing = true; firingDir = DOWN; break;
		default: break;
		}
	} else if (Game::event.type == SDL_KEYUP && Game::event.key.repeat == 0) {
		switch(Game::event.key.keysym.sym) {
		/*** movement ***/
		case SDLK_w: yVel += movespeed; break;
		case SDLK_s: yVel -= movespeed; break;
		case SDLK_a: xVel += movespeed; break;
		case SDLK_d: xVel -= movespeed; break;

		/*** firing ***/
		case SDLK_RIGHT: firing = false; break;
		case SDLK_LEFT: firing = false; break;
		case SDLK_UP: firing = false; break;
		case SDLK_DOWN: firing = false; break;
		default: break;
		}
	}
}

void Player::update(double dt) {
	double projectedX = xPos + (xVel * dt);
	double projectedY = yPos + (yVel * dt);

	if (!Game::entityManager->checkCollisions(projectedX, projectedY, 32, 32)) {
		xPos += xVel * dt;
		yPos += yVel * dt;
	}

	if (Game::entityManager->checkCollisionWithEnemy(xPos, yPos, 32, 32)) {
		if (damageTakenCD_curr == 0) {
			dealDamageToPlayer(1);
		}
	}

	if (int consumableType = Game::entityManager->checkCollisionWithConsumable(xPos, yPos, 32, 32)) {
		alterPlayerByConsumable(consumableType);
	}

	damageTakenCD_curr -= dt;
	if (damageTakenCD_curr < 0) {
		damageTakenCD_curr = 0;
	}

	/*** Bound player inside map ***/
	if (xPos < 0) xPos = 0;
	if (xPos + 32 > 800) xPos = 800 - 32;
	if (yPos < 0) yPos = 0;
	if (yPos + 32 > 640) yPos = 640 - 32;
	/*******************************/


	/*** Control player's rate of fire ***/
	fireCD_curr -= dt;
	if (fireCD_curr < 0) {
		fireCD_curr = 0;
	}

	if (firing && fireCD_curr == 0) {
		switch(firingDir) {
		case RIGHT: Game::entityManager->addProjectile(new Projectile("./arrow_horizontal.png", xPos, yPos, 300, 0, 16, 0)); break;
		case LEFT: Game::entityManager->addProjectile(new Projectile("./arrow_horizontal.png", xPos, yPos, -300, 0, 0, 0)); break;
		case UP: Game::entityManager->addProjectile(new Projectile("./arrow_vertical.png", xPos, yPos, 0, -300, 0, 0)); break;
		case DOWN: Game::entityManager->addProjectile(new Projectile("./arrow_vertical.png", xPos, yPos, 0, 300, 0, 16)); break;
		}

		fireCD_curr = fireCD_max;
	}
	/************************************/

	Game::entityManager->update(dt);
	Game::entityManager->removeDestroyedProjectiles();
}

void Player::render(SDL_Renderer* rend) {
	destRect.x = (int) xPos;
	destRect.y = (int) yPos;

	switch(currDir) {
	case LEFT: srcRect.x = 0; break;
	case RIGHT: srcRect.x = 32; break;
	default: break;
	}

	Game::entityManager->render(rend);

	SDL_RenderCopy(rend, objectTexture, &srcRect, &destRect);
}

void Player::dealDamageToPlayer(double damage) {
	curr_HP -= damage;

	damageTakenCD_curr = damageTakenCD_max;
}

void Player::alterPlayerByConsumable(int consumableType) {
	switch(consumableType) {
	case 1:
		money++;
		printf("Money: %d\n", money);
		break;
	case 2:
		curr_HP++;
		printf("Curr HP: %f\n", curr_HP);
		break;
	default:
		break;
	}
}
