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
	void setLocation();
	void setVelocity();
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
	std::vector<sf::Texture> textures;
	int rotation, rotateSpeed;
	Animation animation;
	bool alive;
};

