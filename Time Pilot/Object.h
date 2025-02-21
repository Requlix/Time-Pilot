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
	Animation getAnimation();
	int getRotation();
	bool inBounds();
	bool collision(Object thing);
	bool isAlive();
	void setVelocity(sf::Vector2f);
	void die();
	void move();
	void outOfBounds();
	void rotate();
private:
	sf::Vector2f velocity;
	int rotation, rotateSpeed, speed = 1;
	Animation animation;
	bool alive = true;
	sf::Vector2f winSize;
};

