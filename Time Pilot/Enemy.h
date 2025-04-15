#pragma once
#include "Object.h"
class Enemy : public Object
{
public:
	Enemy();
	~Enemy();
	bool move();
	void setVelocity();
private:
};

