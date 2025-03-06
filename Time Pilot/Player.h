#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	~Player();
	void move();
	static int tick;
	static double rotation;
	static double speed;
private:
	double rotateSpeed = 2;
};

