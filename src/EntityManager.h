#ifndef ENTITYMANAGER_H_
#define ENTITYMANAGER_H_

#include <vector>
#include <stdio.h>
#include "Enemy.h"
#include "CollidableObject.h"
#include "Projectile.h"
#include "Consumable.h"

class EntityManager {

public:
	EntityManager();
	virtual ~EntityManager();

	void addEnemy(Enemy* enemy);
	void addCollidableObject(CollidableObject* object);
	void addProjectile(Projectile* projectile);
	void addConsumable(Consumable* consumable);

	void removeDestroyedEnemies();
	void removeDestroyedProjectiles();
	void removeDestroyedConsumables();

	bool checkCollisions(int x, int y, int w, int h);
	bool checkCollisionWithEnemy(int x, int y, int w, int h);
	int checkCollisionWithConsumable(int x, int y, int w, int h);

	void render(SDL_Renderer* rend);
	void update(double dt);

private:
	std::vector<Enemy*> enemies;
	std::vector<CollidableObject*> collidableObjects;
	std::vector<Projectile*> projectiles;
	std::vector<Consumable*> consumables;

};

#endif /* ENTITYMANAGER_H_ */
