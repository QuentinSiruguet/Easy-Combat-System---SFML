#include "LootSystem.h"



LootSystem::LootSystem()
{
}

LootSystem::LootSystem(Player *player)
{
	this->initVariables(player);
}


void LootSystem::initVariables(Player * player)
{
	this->player = player;
}

LootSystem::~LootSystem()
{

}

void LootSystem::generateLoot(sf::Vector2f spawnPos)
{
	int chance = rand() % 100+1;
	if (chance > 20)
	{
		this->experienceBubble = ExperienceBubble(spawnPos, this->player->getLevel());
		this->experienceBubbles.push_back(this->experienceBubble);
	}
}

void LootSystem::update()
{
	for (int i = 0; i < this->experienceBubbles.size(); i++)
	{
		this->experienceBubbles[i].update(this->player->getPosition());
		if (player->getGlobalBounds().intersects(this->experienceBubbles[i].getGlobalBounds()))
		{
			this->player->pickUpExperience(this->experienceBubbles[i].getExperienceNumber());
			this->experienceBubbles.erase(this->experienceBubbles.begin() + i);
		}
	}
}

void LootSystem::render(sf::RenderTarget *target)
{
	for (auto &u : this->experienceBubbles)
		u.render(target);
}
