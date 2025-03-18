#pragma once
#include "Enemy.h"
class Grunt : public Enemy
{
public:
	Grunt(int, sf::Vector2f);
	~Grunt();
	void move();
private:
	int gruntType;
};

