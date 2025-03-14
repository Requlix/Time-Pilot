#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:
	Player();
	~Player();
	void move();
	Animation getAnimation();
	static int tick;
	static double rotation;
	static double speed;
private:
	double rotateSpeed = 3.75;
	Animation animation;
};

