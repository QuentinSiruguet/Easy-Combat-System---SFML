#include "Enemy.h"



void Enemy::initVariables(int playerLevel)
{
	this->speed = 5.f;
	this->healthMax = 200.f*(playerLevel + 1);
	this->health = this->healthMax;
	this->damage = 10.f*((playerLevel + 1));
	this->invicibleFrameMax = 30.f;
	this->invicibleFrame = this->invicibleFrameMax;
}

void Enemy::initShape(float x, float y)
{
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setSize(sf::Vector2f(60.f, 60.f));
	this->shape.setPosition(sf::Vector2f(x, y));
}

Enemy::Enemy()
{
}

Enemy::Enemy(float x, float y, int playerLevel)
{
	this->initVariables(playerLevel);
	this->initShape(x, y);
	this->healthBar = HealthBar(this->health, this->healthMax, &this->shape);
}

Enemy::~Enemy()
{

}

sf::FloatRect Enemy::getGlobalBounds()
{
	return this->shape.getGlobalBounds();
}

float Enemy::getDamage()
{
	if (this->health <= 0.f)
		return 0.f;
	else return this->damage;
}

float Enemy::getLife()
{
	return this->health;
}

sf::Vector2f Enemy::getPosition()
{
	return this->shape.getPosition();
}

void Enemy::takeDamage(float damage)
{
	if (this->invicibleFrame >= this->invicibleFrameMax)
	{
		this->health -= damage;
		this->invicibleFrame = 0.f;
	}
}

void Enemy::updateMovment(sf::Vector2f playerPos)
{
	sf::Vector2f diff = playerPos - this->shape.getPosition();

	float hyp = hypot(diff.x, diff.y);
	diff /= hyp;

	this->shape.move(diff*speed);
}

void Enemy::update(sf::Vector2f playerPos, sf::RenderWindow *window)
{
	if (this->health <= 0)
		this->shape.setFillColor(sf::Color::Green);
	if (this->invicibleFrame < this->invicibleFrameMax)
		this->invicibleFrame++;
	this->healthBar.updateHealthBar(this->health, this->healthMax, &this->shape, window);

	this->updateMovment(playerPos);
}

void Enemy::render(sf::RenderTarget *target)
{
	target->draw(shape);
	this->healthBar.render(target);
}
