#include "Game.h"



void Game::initVariables()
{
	//this->videoMode = sf::VideoMode::getDesktopMode();

	this->videoMode = sf::VideoMode(1920, 1080);

	this->lootSystem = LootSystem(&this->player);
	this->enemiesSystem = EnemiesSystem(&this->player, &this->lootSystem);
	this->gamePaused = false;
}


void Game::initWindow()
{
	this->window = new sf::RenderWindow(this->videoMode, "Jeu 3", sf::Style::None);
	this->window->setFramerateLimit(60);
	this->view = window->getDefaultView();
	this->window->setView(this->view);
}

Game::Game() {
	this->initVariables();
	this->initWindow();
}


Game::~Game()
{
	delete this->window;
}



bool Game::isRunning()
{
	return (this->window->isOpen() && !this->player.isDead());
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->SFMLEvent))
	{
		switch (this->SFMLEvent.type)
		{
		case sf::Event::KeyPressed:
			if (this->SFMLEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			if (this->SFMLEvent.key.code == sf::Keyboard::LShift)
				this->player.dashSpell();
			if (this->SFMLEvent.key.code == sf::Keyboard::A)
				this->player.healSpell();
			if (this->SFMLEvent.key.code == sf::Keyboard::Space)
			{
				if (this->gamePaused)
					this->gamePaused = false;
				else
					this->gamePaused = true;
			}
			break;
		}
	}
}




void Game::update()
{
	this->pollEvents();
	if (!this->gamePaused)
	{
		this->player.update(this->window, this->view);
		this->enemiesSystem.update(this->window->getSize(), this->window);
		this->lootSystem.update();
	}
}

void Game::render()
{
	this->window->clear();

	this->lootSystem.render(this->window);
	this->enemiesSystem.render(this->window);
	this->player.render(this->window);

	this->window->display();
}
