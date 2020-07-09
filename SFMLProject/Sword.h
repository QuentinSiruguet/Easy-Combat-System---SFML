#pragma once
#include "ressource.h"

class Sword
{
private:

	sf::CircleShape shape;

	float damage;
	float radius;

	void initVariables(float damage, float radiusAttack);
	void initShape(sf::Vector2f spawnPos);
public:
	Sword(float damage, sf::Vector2f spawnPos, float radiusAttack);
	~Sword();

	sf::FloatRect getGlobalBounds();
	float getDamage();

	void updatePosition(sf::Vector2f movePos);
	void update(sf::Vector2f movePos);
	void render(sf::RenderTarget *target);
	
};

