#pragma once
#include "Object.h"
class Enemy : public Object
{
public:
	Enemy();
	~Enemy();
	bool move();
	void setVelocity();
	bool retreating();
private:
	bool coward=false;
	int retreat=360;
	int agression = rand() % 20 + 5;
};

