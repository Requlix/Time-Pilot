#pragma once
#include "Object.h"
class Bomb : public Object
{
public:
	Bomb(double,double);
	~Bomb();
	void move();
private:
	int tick;
};

