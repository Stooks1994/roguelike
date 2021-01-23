#include "Map.h"
#include "TextureManager.h"
#include "BlobMovement.h"
#include "CollidableObject.h"
#include "Consumable.h"
#include "ConsumableMoney.h"
#include <iostream>
#include <fstream>

Map::Map() {
	texture = TextureManager::loadTexture("terrain.png");
	loadMap("level1.txt");

	src.x = src.y = 0;
	dest.x = dest.y = 0;

	src.w = dest.w = 32;
	src.h = dest.h = 32;
}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

void Map::loadMap(const char* fileName) {
	std::ifstream levelStream (fileName, std::ios_base::in);

	int type;
	int row = 0;
	int col = 0;
	while(levelStream >> type) {
		if (type == '\n') {
			row++;
			col = 0;
		} else {
			map[row][col] = type;
			col++;
		}
	}

	levelStream.close();


	//Populate CollisionManager for the current level
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 25; j++) {
			type = map[i][j];

			switch(type) {
			case 0: Game::entityManager->addCollidableObject(new CollidableObject(j * 32, i * 32, 32, 32)); break;
			case 2: Game::entityManager->addCollidableObject(new CollidableObject(j * 32, i * 32, 32, 32)); break;
			case 3: Game::entityManager->addCollidableObject(new CollidableObject(j * 32, i * 32, 32, 32)); break;
			}
		}
	}

	//Populate EnemyManager for current level
	struct Stats enemyStats(50, 50, 50);
	Game::entityManager->addEnemy(new Enemy("./blob.png", 250, 550, enemyStats, new BlobMovement()));
	Game::entityManager->addEnemy(new Enemy("./blob_red.png", 550, 550, enemyStats, new BlobMovement()));
	Game::entityManager->addEnemy(new Enemy("./blob_blue.png", 650, 550, enemyStats, new BlobMovement()));

	Game::entityManager->addConsumable(new ConsumableMoney(25, 100));
}

void Map::drawMap() {
	int type = 0;

	for (int row = 0; row < 20; row++) {
		for (int col = 0; col < 25; col++) {
			type = map[row][col];
			dest.x = col * 32;
			dest.y = row * 32;

			switch(type) {
			case 0:
				src.x = 0;
				src.y = 0;
				break;
			case 1:
				src.x = 32;
				src.y = 0;
				break;
			case 2:
				src.x = 0;
				src.y = 32;
				break;
			case 3:
				src.x = 32;
				src.y = 32;
				break;
			default:
				break;
			}

			TextureManager::draw(texture, src, dest);
		}
	}
}
