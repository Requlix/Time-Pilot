#pragma once
#include "Object.h"
class Boss : Object
{
public:
	Boss();
	~Boss();
private:
	int health = 7;
};