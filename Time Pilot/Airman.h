#pragma once
#include "Object.h"
class Airman : public Object
{
public:
	Airman();
	~Airman();

	void move();
private:
	int tick = 0;
	int otherTick = 0;
};

