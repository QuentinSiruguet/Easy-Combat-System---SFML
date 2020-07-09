#include "HealthBar.h"


void HealthBar::initHealthBar(float health, float healthMax, sf::RectangleShape *shape)
{
	this->healthBarFrame.setSize(sf::Vector2f(100, 20));
	this->healthBarFrame.setFillColor(sf::Color(255, 255, 255, 0));
	this->healthBarFrame.setOutlineThickness(2.f);
	this->healthBarFrame.setOutlineColor(sf::Color::White);
	this->healthBarFrame.setPosition(sf::Vector2f(
		(shape->getPosition().x - shape->getSize().x / 2) - this->healthBarFrame.getSize().x / 2,
		shape->getPosition().y - 30));

	this->healthBar.setSize(sf::Vector2f(health, 20));
	this->healthBar.setFillColor(sf::Color(255, 0, 0, 128));
}

void HealthBar::updateHealthBar(float health, float healthMax, sf::RectangleShape *shape, sf::RenderWindow *window)
{
	if (health >= 0)
		this->healthBar.setSize(sf::Vector2f((health * 100) / healthMax, 20));

	this->healthBarFrame.setPosition(sf::Vector2f((shape->getPosition().x + shape->getSize().x / 2) - this->healthBarFrame.getSize().x / 2, shape->getPosition().y - 30));
	this->healthBar.setPosition(sf::Vector2f(this->healthBarFrame.getPosition().x, this->healthBarFrame.getPosition().y));

	/*
	if (this->healthBar.getPosition().x < 0)
	{
		this->healthBar.setPosition(0, this->healthBar.getPosition().y);
		this->healthBarFrame.setPosition(0, this->healthBarFrame.getPosition().y);
	}
	if (this->healthBar.getPosition().x > window->getSize().x - this->healthBar.getSize().x)
	{
		this->healthBar.setPosition(window->getSize().x - this->healthBar.getSize().x, this->healthBar.getPosition().y);
		this->healthBarFrame.setPosition(window->getSize().x - this->healthBarFrame.getSize().x, this->healthBarFrame.getPosition().y);
	}

	if (this->healthBar.getPosition().y < 0)
	{
		this->healthBar.setPosition(this->healthBar.getPosition().x, 0);
		this->healthBarFrame.setPosition(this->healthBarFrame.getPosition().x, 0);
	}

	if (this->healthBar.getPosition().y > window->getSize().y - this->healthBar.getSize().y)
	{
		this->healthBar.setPosition(this->healthBar.getPosition().x, window->getSize().y - this->healthBar.getSize().y);
		this->healthBarFrame.setPosition(this->healthBarFrame.getPosition().x, window->getSize().y - this->healthBarFrame.getSize().y);
	}
	*/

}

void HealthBar::render(sf::RenderTarget * target)
{
	target->draw(healthBarFrame);
	target->draw(healthBar);
}

HealthBar::HealthBar(float health, float healthMax, sf::RectangleShape *shape)
{
	this->initHealthBar(health, healthMax, shape);
}

HealthBar::HealthBar()
{
}
HealthBar::~HealthBar()
{
}
