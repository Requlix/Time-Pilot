#pragma once
#include "Object.h"
class Cloud : public Object
{
public:
	Cloud(int);
	~Cloud();
	void setYear(int);
private:
	int pos;
};

