#pragma once
#include "Object.h"
#include <string>
class Explosion : public Object
{
public:
	Explosion(std::string,sf::Vector2f);
	~Explosion();
	void move();
	int getTick() { return tick; }
private:
	std::string type;
	int tick = 0;
};

