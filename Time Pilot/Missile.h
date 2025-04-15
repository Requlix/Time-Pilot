#pragma once
#include "Enemy.h"
class Missile : public Enemy
{
public:
	Missile(int,sf::Vector2f);
	~Missile();

	void move();
private:
	int year;
};

