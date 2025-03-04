#pragma once
#include "Object.h"
class Enemy : public Object
{
public:
	Enemy();
	~Enemy();
	void move(sf::RenderWindow& window);
private:
	sf::Sprite taco;
	sf::Texture bell;
};

