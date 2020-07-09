#pragma once
#include "Enemy.h"
#include "Player.h"
#include "LootSystem.h"

class EnemiesSystem
{
private:

	sf::RenderTarget *target;
	Player *player;
	LootSystem *lootSystem;

	Enemy enemy;
	std::vector<Enemy>	enemies;

	float lastSpawn;
	float spawnRate;
	float spawnMax;
	int enemiesWave;

	void initVariables(Player *player, LootSystem *lootSystem);
public:
	EnemiesSystem();
	EnemiesSystem(Player *player, LootSystem *lootSystem);
	~EnemiesSystem();

	void spawnEnemies(sf::Vector2u windowSize);
	void updateEnnemiesCollision();
	void update(sf::Vector2u windowSize, sf::RenderWindow *window);
	void render(sf::RenderTarget *target);
};

