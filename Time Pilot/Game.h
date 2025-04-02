#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Cloud.h"
#include "Grunt.h"
#include "Bullet.h"
#include <vector>
#include <time.h>

class Game
{
public:
	Game();
	~Game();
	

	void run();

private:
	sf::RenderWindow window;

	int sizeMult = 4;
	int winSizeX = 224 * sizeMult, winSizeY = 256 * sizeMult;

};

