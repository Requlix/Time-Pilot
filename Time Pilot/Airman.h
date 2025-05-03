#pragma once
#include "Object.h"
class Airman : public Object
{
public:
	Airman();
	~Airman();

	void move();
	bool inBounds();
private:
	int tick = 0;
	int otherTick = 0;
};

