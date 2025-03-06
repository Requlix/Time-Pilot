#pragma once
#include "Object.h"
class Bullet : public Object
{
public:
	Bullet(sf::Vector2f, double);
	~Bullet();
	void move();
private:
};

