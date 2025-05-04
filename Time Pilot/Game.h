#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Cloud.h"
#include "Grunt.h"
#include "Bullet.h"
#include <vector>
#include <time.h>
#include "Boss.h"
#include "Animation.h"
#include "Bomb.h"
#include "Missile.h"
#include "Airman.h"

class Game
{
public:
	Game();
	~Game();
	void draw(std::vector<Bullet>& bullets, std::vector<Grunt>& grunts, Cloud cloud[], Player& player, int& lives, bool& playerLiving, int&, std::vector<Bullet>&, int&, int&,std::vector<Bomb>&, std::vector<Missile>&);

	void run();

private:
	sf::RenderWindow window;
	int levels[5] = { 1918,1940,1970,1980,2000 };
	std::string killBoardStr[5] = { "1918planer8.png","1940planer8.png","1970planer8.png","1980plane8.png","2000plane1.png"};
	int level = 0;
	int sizeMult = 4;
	int winSizeX = 224 * sizeMult, winSizeY = 256 * sizeMult;
	sf::Sprite background;
	sf::Texture txt1918;
};