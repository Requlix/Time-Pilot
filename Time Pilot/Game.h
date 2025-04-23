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

class Game
{
public:
	Game();
	~Game();
	void draw(std::vector<Bullet>& bullets, std::vector<Grunt>& grunts, Cloud cloud[], Player& player, int& lives, bool& playerLiving, int&, std::vector<Bullet>&, int&, int&,std::vector<Bomb>&);

	void run();

private:
	sf::RenderWindow window;

	int sizeMult = 4;
	int winSizeX = 224 * sizeMult, winSizeY = 256 * sizeMult;
	sf::Sprite background;
	sf::Texture txt1918;
};