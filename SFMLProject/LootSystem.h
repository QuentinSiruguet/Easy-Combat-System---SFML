#pragma once
#include "ExperienceBubble.h"
#include "Player.h"

class LootSystem
{
private:
	ExperienceBubble experienceBubble;
	std::vector<ExperienceBubble> experienceBubbles;

	Player *player;

	void initVariables(Player *player);
public:
	LootSystem();
	LootSystem(Player *player);
	~LootSystem();
	
	void generateLoot(sf::Vector2f spawnPos);
	
	void update();
	void render(sf::RenderTarget *target);
};

