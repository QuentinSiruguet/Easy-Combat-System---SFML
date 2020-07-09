#include "Spear.h"



void Spear::initVariables(playerLookDirection dir, float damage)
{
	this->dir = dir;
	this->damage = damage;
	this->speed = 50.f;
}

void Spear::initShape(sf::Vector2f spawnPos, sf::Vector2f spearSize)
{
	this->shape.setPosition(spawnPos);
	sf::Vector2f size;
	this->shape.setSize(spearSize);
	this->shape.setFillColor(sf::Color(255, 255, 255, 125));
}

Spear::Spear(sf::Vector2f spawnPos, sf::Vector2f spearSize, playerLookDirection dir, float damage)
{
	this->initVariables(dir, damage);
	this->initShape(spawnPos, spearSize);
}


Spear::~Spear()
{

}

sf::FloatRect Spear::getGlobalBounds()
{
	return this->shape.getGlobalBounds();
}

float Spear::getDamage()
{
	return this->damage;
}

void Spear::updateDamage()
{
	this->damage = this->damage*0.8;
}

void Spear::updateMovements()
{
	switch (this->dir)
	{
	case playerLookDirection::Left:
		this->shape.move(sf::Vector2f(-this->speed, 0.f));
		break;
	case playerLookDirection::Right:
		this->shape.move(sf::Vector2f(this->speed, 0.f));
		break;
	case playerLookDirection::Top:
		this->shape.move(sf::Vector2f(0.f, -this->speed));
		break;
	case playerLookDirection::Bottom:
		this->shape.move(sf::Vector2f(0.f, this->speed));
		break;

	}
}

void Spear::update()
{
	this->updateMovements();
}

void Spear::render(sf::RenderTarget * target)
{
	target->draw(this->shape);
}
