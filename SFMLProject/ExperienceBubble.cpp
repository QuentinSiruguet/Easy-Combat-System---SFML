#include "ExperienceBubble.h"



void ExperienceBubble::initShape(sf::Vector2f spawnPos, int level)
{
	this->shape.setPosition(spawnPos);
	this->shape.setRadius(10);
	this->shape.setFillColor(sf::Color::Green);
	this->experienceNumber = rand() % 50 + 75*level;
	this->speed = 1.f;
}

ExperienceBubble::ExperienceBubble()
{
}

ExperienceBubble::ExperienceBubble(sf::Vector2f spawnPos, int level)
{
	this->initShape(spawnPos, level);
}


ExperienceBubble::~ExperienceBubble()
{

}

sf::FloatRect ExperienceBubble::getGlobalBounds()
{
	return this->shape.getGlobalBounds();
}


float ExperienceBubble::getExperienceNumber()
{
	return this->experienceNumber;
}

void ExperienceBubble::updateMovment(sf::Vector2f playerPos)
{
	sf::Vector2f diff = playerPos - this->shape.getPosition();
	float hyp = hypot(diff.x, diff.y);
	diff /= hyp;
	this->speed = (1 / hyp)*750;
	this->shape.move(diff*this->speed);
}

void ExperienceBubble::update(sf::Vector2f playerPos)
{
	this->updateMovment(playerPos);
}

void ExperienceBubble::render(sf::RenderTarget *target)
{
	target->draw(this->shape);
}
