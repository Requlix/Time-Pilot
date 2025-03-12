#pragma once
#include <SFML/Graphics.hpp>
#include <string>


class Animation
{
public:
	Animation();
	~Animation();
	sf::Sprite getSprite();
	void setFrame(int);
	void setTextures(std::string, std::string, int);
private:
	sf::Sprite sprite;
	std::vector<sf::Texture> textures[2];
	int tick = 0;
};

