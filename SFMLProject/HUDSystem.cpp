#include "HUDSystem.h"


HUDSystem::HUDSystem()
{

}

HUDSystem::HUDSystem(float health, float healthMax, float experience, float experienceMax, sf::RectangleShape shape)
{
	this->healthBar = HealthBar(health, healthMax, &shape);
	this->xpBar = XpBar(experience, experienceMax);
}



HUDSystem::~HUDSystem()
{
}

void HUDSystem::update(sf::RenderWindow *window, float health, float healthMax, float experience, float experienceMax, int level, short score, sf::RectangleShape shape)
{
	this->healthBar.updateHealthBar(health, healthMax, &shape, window);
	this->xpBar.update(window, experience, experienceMax);

	font.loadFromFile("Font/LemonMilk.otf");
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	sf::Vector2f posView = window->mapPixelToCoords(sf::Vector2i(0,0), window->getView());
	text.setPosition(posView);
	std::stringstream ss;
	ss << "Level : " << level + 1 << std::endl << "Health : " << health << "/" << healthMax << std::endl << "Score : " << score;
	text.setString(ss.str());
	
}

void HUDSystem::render(sf::RenderTarget *target)
{
	this->xpBar.render(target);
	this->healthBar.render(target);
	target->draw(text);
}
