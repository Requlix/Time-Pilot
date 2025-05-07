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
	bool formation = false;
	bool beige=false;
private:
	bool coward=false;
	int retreat=360;
	int agression = rand() % 20 + 5;
	double rot;
};

