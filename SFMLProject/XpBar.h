#pragma once
#include "ressource.h"

class XpBar
{
private:
	sf::RectangleShape xpBar;
	sf::RectangleShape xpBarFrame;
	sf::RenderWindow *window;

	float experience;
	float experienceMax;

	void initXpBar(float experience, float experienceMax);
public:
	XpBar();
	XpBar(float experience, float experienceMax);
	~XpBar();

	void update(sf::RenderWindow *window, float experience, float experienceMax);
	void render(sf::RenderTarget *target);
};

