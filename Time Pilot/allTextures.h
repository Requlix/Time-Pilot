#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>

class allTextures
{
public:
	allTextures();
	~allTextures();

	std::vector<sf::Texture>& allTextures::getTextures(std::string);

private:
	std::vector<sf::Texture> plane1918[2];
	std::vector<sf::Texture> player[2];
	std::vector<sf::Texture> eBullet[2];
	std::vector<sf::Texture> pBullet[2];
	std::vector<sf::Texture> airman[2];
	std::vector<sf::Texture> cloud[2]; //temperary until all cloud sprites are ready

};

