#pragma once
#include "Tgrunt.h"
class Boss : public Tgrunt
{
public:
	Boss(int, sf::Vector2f);
	~Boss();
	void move();
	bool hit();
private:
	std::string year;
	int hits = 8;
};

