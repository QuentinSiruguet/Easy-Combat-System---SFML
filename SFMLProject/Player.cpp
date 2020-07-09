#include "Player.h"



void Player::initVariables()
{
	//Other
	this->leftMouseHeld = false;
	this->rightMouseHeld = false;

	//Player things
	//levelUp = level, speed, invicibleFrameMax, radiusAttack, healthMax
	this->level = 0;
	this->speed = levelUp[this->level][1];
	

	this->healthMax = levelUp[this->level][4];
	this->health = this->healthMax;
	
	this->invicibleFrameMax = levelUp[this->level][2];
	this->invicibleFrame = this->invicibleFrameMax;
	this->dir = playerLookDirection::DefaultDirection;
	this->experience = 0.f;
	this->experienceMax = levelUp[this->level][5];
	
	this->dead = false;
	this->score = 0;

	//Upgrade related
	

	//Global attack related
	this->damage = levelUp[this->level][6];

	//Sword spell
	this->radiusAttack = levelUp[this->level][3];
	this->sword = nullptr;
	this->attackDurationMax = 30.f;
	this->attackDuration = this->attackDurationMax;
	this->attackCoolDownMax = 50.f;
	this->attackCoolDown = this->attackCoolDownMax;

	//Spear spell
	this->spear = nullptr;
	this->spearCoolDownMax = 120.f;
	this->spearCoolDown = this->spearCoolDownMax;

	//Dash spell
	this->dashCoolDownMax = 120.f;
	this->dashCoolDown = this->dashCoolDownMax;
	this->dashDistance = 500.f;

	//Heal spell
	this->healSize = 20.f;
	this->healCoolDownMax = 240.f;
	this->healCoolDown = this->healCoolDownMax;

}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Blue);
	this->shape.setSize(sf::Vector2f(30.f, 30.f));
	this->shape.setPosition(1920 / 2-30, 1080 / 2-30);
}

Player::Player()
{
	this->initVariables();
	this->initShape();
	this->hud = HUDSystem(this->health, this->healthMax, this->experience, this->experienceMax, this->shape);

}

Player::~Player()
{

}

//Accessors

sf::FloatRect Player::getGlobalBounds()
{
	return this->shape.getGlobalBounds();
}

sf::FloatRect Player::getAttackGlobalBounds()
{
	if (this->sword != nullptr)
		return this->sword->getGlobalBounds();
	else return sf::FloatRect();
}

sf::FloatRect Player::getSpearGlobalBounds()
{
	if (this->spear != nullptr)
		return this->spear->getGlobalBounds();
	else return sf::FloatRect();
}

sf::Vector2f Player::getPosition()
{
	return this->shape.getPosition();
}

float Player::getSwordDamage()
{
	if (this->sword != nullptr)
		return this->sword->getDamage();
	else
		return 0;
}

float Player::getSpearDamage()
{
	if (this->spear != nullptr)
		return this->spear->getDamage();
	else
		return 0;
}

int Player::getLevel()
{
	return this->level;
}

bool Player::isDead()
{
	return this->dead;
}

void Player::updateScore(short score)
{
	this->score += score;
}

void Player::takeDamage(float damage)
{
	if (this->invicibleFrame >= this->invicibleFrameMax)
	{
		if (damage > 0)
		{
			this->health -= damage;
			this->invicibleFrame = 0;
		}
	}

	if (this->health <= 0)
		this->dead = true;
}

//Functions

void Player::swordAttack()
{
	if (this->attackDuration < this->attackDurationMax)
		attackDuration++;

	if (this->attackCoolDown < this->attackCoolDownMax)
		this->attackCoolDown++;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->leftMouseHeld == false)
		{
			this->leftMouseHeld = true;
			if (this->attackDuration >= this->attackDurationMax && this->attackCoolDown >= this->attackCoolDownMax)
			{
				this->attackDuration = 0.f;
				this->attackCoolDown = 0.f;
				sf::Vector2f spawnPos(
					(this->shape.getPosition().x + this->shape.getSize().x / 2) - this->radiusAttack,
					(this->shape.getPosition().y + this->shape.getSize().y / 2) - this->radiusAttack
				);
				this->sword = new Sword(this->damage, spawnPos, this->radiusAttack);
			}
		}
	}
	else
		this->leftMouseHeld = false;
	if (this->sword != nullptr && this->attackDuration >= this->attackDurationMax)
	{
		delete this->sword;
		this->sword = nullptr;
	}

}

void Player::spearAttack()
{
	if (this->spearCoolDown < this->spearCoolDownMax)
		this->spearCoolDown++;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (this->rightMouseHeld == false)
		{
			sf::Vector2f spawnPos;
			this->rightMouseHeld = true;
			if (this->spearCoolDown >= this->spearCoolDownMax)
			{
				this->spearCoolDown = 0;
				switch (this->dir)
				{
				case playerLookDirection::Top:
					this->spearSize = sf::Vector2f(20.f, 50.f);
					spawnPos = sf::Vector2f(
						this->shape.getPosition().x + this->shape.getSize().x / 2 - this->spearSize.x / 2,
						this->shape.getPosition().y - this->spearSize.y
					);

					break;
				case playerLookDirection::Bottom:
					this->spearSize = sf::Vector2f(20.f, 50.f);
					spawnPos = sf::Vector2f(
						this->shape.getPosition().x + this->shape.getSize().x / 2 - this->spearSize.x / 2,
						this->shape.getPosition().y + this->shape.getSize().y
					);

					break;
				case playerLookDirection::Left:
					this->spearSize = sf::Vector2f(50.f, 20.f);
					spawnPos = sf::Vector2f(
						this->shape.getPosition().x - this->spearSize.x,
						this->shape.getPosition().y + this->shape.getSize().y / 2 - this->spearSize.y / 2
					);

					break;
				case playerLookDirection::Right:
					this->spearSize = sf::Vector2f(50.f, 20.f);
					spawnPos = sf::Vector2f(
						this->shape.getPosition().x + this->shape.getSize().x,
						this->shape.getPosition().y + this->shape.getSize().y / 2 - this->spearSize.y / 2
					);

					break;
				}
				this->spear = new Spear(spawnPos, spearSize, dir, damage);

			}
		}
	}

	else
		this->rightMouseHeld = false;
	if (this->spear != nullptr && this->spearCoolDown >= this->spearCoolDownMax)
	{
		delete this->spear;
		this->spear = nullptr;
	}
}

void Player::dashSpell()
{
	if (this->dashCoolDown >= this->dashCoolDownMax)
	{
		this->dashCoolDown = 0.;
		switch (dir)
		{
		case playerLookDirection::Top:
			this->shape.move(0.f, -this->dashDistance);
			break;
		case playerLookDirection::Bottom:
			this->shape.move(0.f, this->dashDistance);
			break;
		case playerLookDirection::Left:
			this->shape.move(-this->dashDistance, 0.f);
			break;
		case playerLookDirection::Right:
			this->shape.move(this->dashDistance, 0.f);
			break;
		}
	}
}

void Player::healSpell()
{

	if (this->healCoolDown >= this->healCoolDownMax)
	{
		this->healCoolDown = 0.f;
		this->health += this->healSize;
		if (this->health > this->healthMax)
			this->health = this->healthMax;
	}
}

void Player::pickUpExperience(float experienceNumber)
{
	this->experience += experienceNumber;
	if (this->experience >= this->experienceMax)
	{
		level++;
		if (this->health / 2 < this->healthMax / 2)
			this->health = this->healthMax / 2;
		this->experience = 0;
		this->speed = levelUp[this->level][1];
		this->invicibleFrameMax = levelUp[this->level][2];
		this->radiusAttack = levelUp[this->level][3];
		this->healthMax = levelUp[this->level][4];
		this->experienceMax = levelUp[this->level][5];
		this->healSize = this->healthMax * 0.1;
	}
}

//Updates

void Player::updateSword()
{
	sf::Vector2f movePos(
		(this->shape.getPosition().x + this->shape.getSize().x / 2) - this->radiusAttack,
		(this->shape.getPosition().y + this->shape.getSize().y / 2) - this->radiusAttack
	);
	if (this->sword != nullptr)
		this->sword->update(movePos); //Deplace attack if player moove
}

void Player::updateSpear()
{
	if (this->spear != nullptr)
		this->spear->update();
}

void Player::updateSpearDamage()
{
	this->spear->updateDamage();
}

void Player::updateDash()
{
	if (this->dashCoolDown < this->dashCoolDownMax)
		this->dashCoolDown++;
}

void Player::updateHeal()
{
	if (this->healCoolDown < this->healCoolDownMax)
		this->healCoolDown++;
}

void Player::updatePlayerActions(sf::RenderWindow *window)
{
	this->swordAttack();
	this->spearAttack();

	this->updateMovement();
	

	this->updateSword();
	this->updateSpear();
	this->updateDash();
	this->updateHeal();
}

void Player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		this->shape.move(0.f, -this->speed);
		dir = playerLookDirection::Top;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->shape.move(0.f, this->speed);
		dir = playerLookDirection::Bottom;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		this->shape.move(-this->speed, 0.f);
		dir = playerLookDirection::Left;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->shape.move(this->speed, 0.f);
		dir = playerLookDirection::Right;
	}
}

void Player::updateGlobalBoundsCollision(sf::RenderWindow *window)
{
	/*
	if (this->shape.getPosition().x < 0)
		this->shape.setPosition(0, this->shape.getPosition().y);

	if (this->shape.getPosition().x > window->getSize().x - this->shape.getSize().x)
		this->shape.setPosition(window->getSize().x - this->shape.getSize().x, this->shape.getPosition().y);

	if (this->shape.getPosition().y < 0)
		this->shape.setPosition(this->shape.getPosition().x, 0);

	if (this->shape.getPosition().y > window->getSize().y - this->shape.getSize().y)
		this->shape.setPosition(this->shape.getPosition().x, window->getSize().y - this->shape.getSize().y);*/

}

void Player::update(sf::RenderWindow *window, sf::View view)
{

	if (this->invicibleFrame < this->invicibleFrameMax)
	{
		this->invicibleFrame++;
		this->shape.setFillColor(sf::Color::Cyan);
	}
	else
		this->shape.setFillColor(sf::Color::Blue);

	this->updatePlayerActions(window);
	view.setCenter(this->shape.getPosition());
	window->setView(view);
	this->updateGlobalBoundsCollision(window);

	this->hud.update(window, this->health, this->healthMax, this->experience, this->experienceMax, this->level,this->score, this->shape);

}

//Renders

void Player::renderSpells(sf::RenderTarget *target)
{
	if (this->sword != nullptr)
		this->sword->render(target);
	if (this->spear != nullptr)
		this->spear->render(target);
}

void Player::render(sf::RenderTarget * target)
{
	this->renderSpells(target);
	target->draw(this->shape);
	this->hud.render(target);

}

