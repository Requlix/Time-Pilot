#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <Math.h>
#include "Player.h"

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
	void setVelocity(double, double);
	void die();
	void move();
	void outOfBounds();
	void rotate();
	
protected:
	sf::Vector2f velocity;
	double rotation, rotateSpeed, speed = 1;
	sf::Vector2f winSize;
private:
	Animation animation;
	bool alive = true;
};

