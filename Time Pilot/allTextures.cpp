#include "allTextures.h"

allTextures::allTextures()
{
	sf::Texture tempText1, tempText2;

	for (int i = 0; i < 32; i++)
	{
		tempText1.loadFromFile("player" + std::to_string(i) + ".png");
		player[0].push_back(tempText1);
		player[1].push_back(tempText1);
	}
	for (int i = 0; i < 16; i++)
	{
		tempText1.loadFromFile("1918planer" + std::to_string(i) + ".png");
		tempText2.loadFromFile("1918planel" + std::to_string(i) + ".png");
		plane1918[0].push_back(tempText1);
		plane1918[1].push_back(tempText2);
	}

	for (int i = 0; i < 4; i++)
	{
		tempText1.loadFromFile("airman" + std::to_string(i) + ".png");
		airman[0].push_back(tempText1);
		airman[1].push_back(tempText1);
	}

	tempText1.loadFromFile("eBullet0.png");
	eBullet[0].push_back(tempText1);
	eBullet[1].push_back(tempText1);

	tempText1.loadFromFile("pBullet0.png");
	pBullet[0].push_back(tempText1);
	pBullet[1].push_back(tempText1);

	tempText1.loadFromFile("cloud0.png");
	cloud[0].push_back(tempText1);
	cloud[1].push_back(tempText1);
}

allTextures::~allTextures()
{

}

std::vector<sf::Texture>& allTextures::getTextures(std::string)
{

}