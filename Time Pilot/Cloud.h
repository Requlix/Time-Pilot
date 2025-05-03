#pragma once
#include "Object.h"
class Cloud : public Object
{
public:
	Cloud(int);
	~Cloud();
	void setYear(int);
	void move();
private:
	int pos;
	int year;
};

