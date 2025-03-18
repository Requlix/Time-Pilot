#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <Math.h>
#include "Player.h"
#include <iostream>

class Object
{
public:
	Object();
	~Object();
	sf::Vector2f getVelocity();
	sf::Vector2f getPosition();
	Animation getAnimation();
	bool inBounds();
	bool collision(Object thing);
	bool isAlive();
	void setOffset();
	void setVelocity(double x, double y);
	void die();
	void move();
	void outOfBounds();
	void rotate();
	
protected:
	sf::Vector2f velocity;
	double rotation, rotateSpeed, speed = 1;
	sf::Vector2f winSize;
	Animation animation;
	bool alive = true;
private:
};

