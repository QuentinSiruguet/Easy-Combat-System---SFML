#pragma once

#include "ressource.h"
#include "HealthBar.h"

class Enemy
{
private:
	sf::RectangleShape shape;
	HealthBar healthBar;

	float speed;
	float health;
	float healthMax;
	float damage;
	float invicibleFrame;
	float invicibleFrameMax;

	void initVariables(int playerLevel);
	void initShape(float x, float y);
public:
	Enemy();
	Enemy(float x, float y, int playerLevel);
	~Enemy();

	sf::FloatRect getGlobalBounds();
	float getDamage();
	float getLife();
	sf::Vector2f getPosition();

	void takeDamage(float damage);

	void updateMovment(sf::Vector2f playerPos);
	void update(sf::Vector2f playerPos, sf::RenderWindow *window);
	void render(sf::RenderTarget *target);
};

