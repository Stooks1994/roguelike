#include "ProjectileManager.h"

ProjectileManager::ProjectileManager() {

}

ProjectileManager::~ProjectileManager() {

}


void ProjectileManager::addProjectile(const char* textureSheet, double x, double y, double vel_x, double vel_y, int src_x, int src_y) {
	Projectile* temp = new Projectile(textureSheet, x, y, vel_x, vel_y, src_x, src_y);
	projectiles.push_back(temp);
}

void ProjectileManager::removeDestroyedProjectiles() {
	std::vector<Projectile*> temp;

	for (auto& proj : projectiles) {
		if (!proj->isDestroyed()) {
			temp.push_back(proj);
		}
	}

	projectiles = temp;
}

void ProjectileManager::update(double dt) {
	for (auto& proj : projectiles) {
		proj->update(dt);
	}
}

void ProjectileManager::render() {
	for (auto& proj : projectiles) {
		proj->render();
	}
}

