#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Object
{
public:
	Object();
	~Object();
	sf::Vector2f getLocation();
	sf::Vector2f getVelocity();
	void setLocation(sf::Vector2f);
	void setVelocity(sf::Vector2f);
	void die();
	void move();
	void outOfBounds();
	void rotate();
	bool inBounds();
	bool collision(Object thing);
	bool isAlive();
	int getRotation();

	
private:
	sf::Vector2f location;
	sf::Vector2f velocity;
	sf::Sprite sprite;
	int rotation, rotateSpeed;
	Animation animation;
	bool alive = true;
};

