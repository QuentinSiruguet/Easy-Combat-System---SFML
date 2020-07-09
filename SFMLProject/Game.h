#pragma once

#include "ressource.h"

#include "Player.h"

#include "LootSystem.h"
#include "EnemiesSystem.h"


class Game
{
private:
	sf::RenderWindow *window;
	sf::VideoMode videoMode;
	sf::View view;
	sf::Event SFMLEvent;
	bool gamePaused;
	Player player;

	

	LootSystem lootSystem;
	EnemiesSystem enemiesSystem;
	


	void initVariables();
	void initWindow();
public:
	Game();
	~Game();

	bool isRunning();

	void pollEvents();

	void update();
	void render();
};

