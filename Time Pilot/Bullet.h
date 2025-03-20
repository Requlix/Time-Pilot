#pragma once
#include "Object.h"
class Bullet : public Object
{
public:
	Bullet(sf::Vector2f,double,std::string);
	~Bullet();
	void move();
private:
};

