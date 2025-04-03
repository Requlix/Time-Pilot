#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "allTextures.h"


class Animation
{
public:
	Animation();
	~Animation();
	sf::Sprite& getSprite();
	void setFrame(int);
	void setTextures(std::string, std::string, int);
	void setPosition(sf::Vector2f);
	void setOrigin(sf::Vector2f);
	void move(sf::Vector2f);
private:
	sf::Sprite sprite;
	std::vector<sf::Texture> textures[2];
	int tick = 0, propeler = 0;
	static allTextures yay;
};

