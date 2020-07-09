#include "Sword.h"




void Sword::initVariables(float damage, float radiusAttack)
{
	this->damage = damage;
	this->radius = radiusAttack;
}

void Sword::initShape(sf::Vector2f spawnPos)
{
	this->shape.setRadius(radius);
	this->shape.setPosition(spawnPos);
	this->shape.setFillColor(sf::Color(255, 255, 255,125));
}

Sword::Sword(float damage, sf::Vector2f spawnPos, float radiusAttack)
{
	this->initVariables(damage, radiusAttack);
	this->initShape(spawnPos);
}

Sword::~Sword()
{

}

sf::FloatRect Sword::getGlobalBounds()
{
	return this->shape.getGlobalBounds();
}

float Sword::getDamage()
{
	return this->damage;
}

void Sword::updatePosition(sf::Vector2f movePos)
{
	this->shape.setPosition(movePos);
}

void Sword::update(sf::Vector2f movePos)
{
	this->updatePosition(movePos);
}

void Sword::render(sf::RenderTarget *target)
{
	target->draw(this->shape);
}
