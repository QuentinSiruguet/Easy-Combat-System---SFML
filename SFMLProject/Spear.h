#pragma once
#include "ressource.h"


class Spear
{
private:
	sf::RectangleShape shape;

	playerLookDirection dir;
	float damage;
	float speed;

	void initVariables(playerLookDirection dir, float damage);
	void initShape(sf::Vector2f spawnPos, sf::Vector2f spearSize);
public:
	Spear(sf::Vector2f spawnPos,sf::Vector2f spearSize, playerLookDirection dir, float damage);
	~Spear();

	sf::FloatRect getGlobalBounds();
	float getDamage();

	void updateDamage();
	void updateMovements();
	void update();
	void render(sf::RenderTarget *target);
};

