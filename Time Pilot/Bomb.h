#pragma once
#include "Object.h"
class Bomb : public Object
{
public:
	Bomb(sf::Vector2f);
	~Bomb();
	void move();
private:
	int tick;
};

