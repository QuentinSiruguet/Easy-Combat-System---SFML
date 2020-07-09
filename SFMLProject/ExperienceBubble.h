#pragma once
#include "ressource.h"
class ExperienceBubble
{
private:
	sf::CircleShape shape;
	float experienceNumber;
	float speed;

	void initShape(sf::Vector2f spawnPos, int level);
public:
	ExperienceBubble();
	ExperienceBubble(sf::Vector2f spawnPos, int level);
	~ExperienceBubble();

	sf::FloatRect getGlobalBounds();
	float getExperienceNumber();

	void updateMovment(sf::Vector2f playerPos);
	void update(sf::Vector2f playerPos);
	void render(sf::RenderTarget *target);
};

