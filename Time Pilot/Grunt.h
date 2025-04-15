#pragma once
#include "Enemy.h"
class Grunt : public Enemy
{
public:
	Grunt(int, sf::Vector2f);
	~Grunt();
	bool move();
private:
	int gruntType;
};