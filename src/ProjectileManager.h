#ifndef SRC_PROJECTILEMANAGER_H_
#define SRC_PROJECTILEMANAGER_H_

#include <stdio.h>
#include <vector>
#include "Projectile.h"

class ProjectileManager {
public:

	ProjectileManager();
	virtual ~ProjectileManager();

	void addProjectile(const char* textureSheet, double x, double y, double vel_x, double vel_y, int src_x, int src_y);
	void removeDestroyedProjectiles();

	void update(double dt);
	void render();

private:
	std::vector<Projectile*> projectiles;
};

#endif /* SRC_PROJECTILEMANAGER_H_ */
