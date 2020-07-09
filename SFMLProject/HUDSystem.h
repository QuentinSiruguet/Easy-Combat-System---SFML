#pragma once
#include "HealthBar.h"
#include "XpBar.h"
class HUDSystem
{
private:
	HealthBar healthBar;
	XpBar xpBar;

	sf::Font font;
	sf::Text text;

public:
	HUDSystem();
	HUDSystem(float health, float healthMax, float experience, float experienceMax, sf::RectangleShape shape);
	~HUDSystem();

	void update(sf::RenderWindow *window, float health, float healthMax, float experience, float experienceMax,int level,short score, sf::RectangleShape shape);
	void render(sf::RenderTarget *target);
};

