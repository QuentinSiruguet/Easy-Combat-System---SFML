#include "EnemiesSystem.h"



void EnemiesSystem::initVariables(Player *player, LootSystem *lootSystem)
{
	this->player = player;
	this->lootSystem = lootSystem;

	this->spawnRate = 50.f;
	this->lastSpawn = this->spawnRate;
	this->spawnMax = 1000;
	this->enemiesWave = 0;
}

EnemiesSystem::EnemiesSystem()
{
}

EnemiesSystem::EnemiesSystem(Player *player, LootSystem *lootSystem)
{
	this->initVariables(player, lootSystem);
}


EnemiesSystem::~EnemiesSystem()
{
}

void EnemiesSystem::spawnEnemies(sf::Vector2u windowSize)
{
	this->target = target;
	if (this->lastSpawn < this->spawnRate)
		this->lastSpawn++;

	sf::Vector2f spawnPos(0, 0);
	int pos2 = 800;
	int range = rand() % 2 + 1;
	if (range == 2)
		pos2 *= -1;
	switch (rand() % 4 + 1)
	{
	case enemiesSpawn::SpawnTop:
		spawnPos = sf::Vector2f(this->player->getPosition().x + rand() % pos2 - rand() % 1200, this->player->getPosition().y - 1200);
		break;
	case enemiesSpawn::SpawnBottom:
		spawnPos = sf::Vector2f(this->player->getPosition().x + rand() % pos2 - rand() % 1200, this->player->getPosition().y + 1200);
		break;
	case enemiesSpawn::SpawnLeft:
		spawnPos = sf::Vector2f(this->player->getPosition().x - 1200, this->player->getPosition().y + rand() % pos2 - rand() % 1200);
		break;
	case enemiesSpawn::SpawnRight:
		spawnPos = sf::Vector2f(this->player->getPosition().x + 1200, this->player->getPosition().y + rand() % pos2 - rand() % 1200);
		break;
	}

	if (this->enemies.size() < this->spawnMax && this->lastSpawn >= this->spawnRate)
	{
		this->lastSpawn = 0;
		this->enemy = Enemy(spawnPos.x, spawnPos.y, this->player->getLevel());
		this->enemies.push_back(enemy);
	}
}

void EnemiesSystem::updateEnnemiesCollision()
{
	for (int i = 0; i < this->enemies.size(); i++)
	{
		if (this->player->getGlobalBounds().intersects(this->enemies[i].getGlobalBounds()))
			this->player->takeDamage(this->enemies[i].getDamage());

		if (this->player->getAttackGlobalBounds().intersects(this->enemies[i].getGlobalBounds()))
			this->enemies[i].takeDamage(this->player->getSwordDamage());

		if (this->player->getSpearGlobalBounds().intersects(this->enemies[i].getGlobalBounds()))
		{
			this->enemies[i].takeDamage(this->player->getSpearDamage());
			this->player->updateSpearDamage();
		}
	}
}

void EnemiesSystem::update(sf::Vector2u windowSize, sf::RenderWindow *window)
{
	this->spawnEnemies(windowSize);

	for (int i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].update(this->player->getPosition(), window);

		if (this->enemies[i].getLife() <= 0)
		{
			this->lootSystem->generateLoot(this->enemies[i].getPosition());
			this->enemies.erase(this->enemies.begin() + i);
			this->player->updateScore(1);
		}
	}
	this->updateEnnemiesCollision();
}

void EnemiesSystem::render(sf::RenderTarget *target)
{
	for (auto &e : this->enemies)
		e.render(target);
}
