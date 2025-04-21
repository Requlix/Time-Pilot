#pragma once
#include "Object.h"
class Boss : Object
{
public:
	Boss(int, sf::Vector2f);
	~Boss();
	void move();
	bool hit();
	Animation& getAnimation();
private:
	std::string year;
	int hits = 0;
};

