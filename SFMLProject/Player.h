#pragma once
#include "ressource.h"

#include "Sword.h"
#include "Spear.h"
#include "HUDSystem.h"


class Player
{
private:
	sf::RectangleShape shape;

	//HUD

	HUDSystem hud;

	Sword *sword;
	Spear *spear;

	//Game related
	bool leftMouseHeld;
	bool rightMouseHeld;

	//Player related
	playerLookDirection dir;
	float invicibleFrame;
	float invicibleFrameMax;
	float speed;
	float health;
	float healthMax;
	int level;
	float experience;
	float experienceMax;
	bool dead;
	unsigned short score;
	float levelUp[20][7] = {
		{ 0, 10, 20, 80, 200, 500,50 },
		{ 1, 10, 22, 90, 250, 750,100 },
		{ 2, 10, 25, 100, 300, 1000,400 },
		{ 3, 10, 30, 100, 350, 1250,800 },
		{ 4, 10, 35, 110, 400, 1500,3000 },
		{ 5, 10, 35, 110, 500, 2000,6000 },
		{ 6, 12, 35, 110, 600, 2500,10000 },
		{ 7, 12, 35, 120, 700, 3000,15000 },
		{ 8, 12, 35, 120, 800, 4000,20000 },
		{ 9, 12, 35, 120, 900, 5000,40000 },
		{ 10, 12, 40, 120, 1000, 6000,60000 },
		{ 11, 12, 40, 120, 1200, 7000,100000 },
		{ 12, 12, 40, 120, 1400, 8000,100000 },
		{ 13, 15, 50, 120, 1600, 9000,100000 },
		{ 14, 15, 50, 140, 1800, 10000,100000 },
		{ 15, 15, 50, 140, 2000, 10000,100000 },
		{ 16, 15, 50, 140, 2200, 10000,100000 },
		{ 17, 15, 50, 140, 2400, 10000,100000 },
		{ 18, 15, 60, 150, 2600, 10000,100000 },
		{ 19, 15, 60, 150, 2800, 10000,100000 }
	};
	//level, speed, invicibleFrameMax, radiusAttack, healthMax, experienceMax, damage

	//Attack related
	float damage;

	//BasicAttack related
	float radiusAttack;
	float attackDuration;
	float attackDurationMax;
	float attackCoolDown;
	float attackCoolDownMax;

	//Spear related

	sf::Vector2f spearSize;
	float spearCoolDown;
	float spearCoolDownMax;

	//Dash related
	float dashDistance;
	float dashCoolDown;
	float dashCoolDownMax;

	//Heal related
	float healSize;
	float healCoolDown;
	float healCoolDownMax;

	//Private functions
	void initVariables();
	void initShape();




public:
	Player();
	~Player();

	sf::FloatRect getGlobalBounds();
	sf::FloatRect getAttackGlobalBounds();
	sf::FloatRect getSpearGlobalBounds();
	sf::Vector2f getPosition();
	float getSwordDamage();
	float getSpearDamage();
	int getLevel();
	bool isDead();

	void updateScore(short score);
	void takeDamage(float damage);

	void swordAttack();
	void spearAttack();
	void dashSpell();
	void healSpell();
	void pickUpExperience(float experienceNumber);

	void updateSword();
	void updateSpear();
	void updateSpearDamage();
	void updateDash();
	void updateHeal();
	void updatePlayerActions(sf::RenderWindow *window);
	void updateMovement();
	void updateGlobalBoundsCollision(sf::RenderWindow *window);
	void update(sf::RenderWindow *window, sf::View view);


	void renderSpells(sf::RenderTarget *target);
	void render(sf::RenderTarget *target);

};

