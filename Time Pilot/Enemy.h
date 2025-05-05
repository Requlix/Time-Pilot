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
	int formation = 0;
private:
	bool coward=false;
	int retreat=360;
	int agression = rand() % 20 + 5;
};

