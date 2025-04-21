#pragma once
#include "Object.h"
class Boss : public Object
{
public:
	Boss(int, sf::Vector2f);
	~Boss();
	void move();
	bool hit();
private:
	std::string year;
	int hits = 0;
};

