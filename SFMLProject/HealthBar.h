#pragma once
#include "ressource.h"

class HealthBar
{
private:
	sf::RectangleShape healthBar;
	sf::RectangleShape healthBarFrame;

	void initHealthBar(float health, float healthMax, sf::RectangleShape *shape);
public:

	
	void updateHealthBar(float health, float healthMax, sf::RectangleShape *shape, sf::RenderWindow *window);
	void render(sf::RenderTarget *target);

	HealthBar(float health, float healthMax, sf::RectangleShape *shape);
	HealthBar();
	~HealthBar();
};

