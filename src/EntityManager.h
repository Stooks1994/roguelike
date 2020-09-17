#ifndef ENTITYMANAGER_H_
#define ENTITYMANAGER_H_

#include <vector>
#include <stdio.h>
#include "Enemy.h"
#include "CollidableObject.h"
#include "Projectile.h"

class EntityManager {

public:
	EntityManager();
	virtual ~EntityManager();

	void addEnemy(Enemy* enemy);
	void addCollidableObject(CollidableObject* object);
	void addProjectile(Projectile* projectile);

	void removeDestroyedEnemies();
	void removeDestroyedProjectiles();

	bool checkCollisions(int x, int y, int w, int h);

	void render(SDL_Renderer* rend);
	void update(double dt);

private:
	std::vector<Enemy*> enemies;
	std::vector<CollidableObject*> collidableObjects;
	std::vector<Projectile*> projectiles;

};

#endif /* ENTITYMANAGER_H_ */
