#include "Animation.h"

Animation::Animation()
{

}

Animation::~Animation()
{

}

void Animation::setTextures(std::string text1, std::string text2, int length)
{
	for (int i = 0; i < length; i++)
	{
		textures[i][0].loadFromFile(text1 + std::to_string(i) + ".png");
		textures[i][1].loadFromFile(text2 + std::to_string(i) + ".png");
	}
}

sf::Sprite Animation::getSprite()
{
	return sprite;
}

void Animation::setFrame(int angle)
{
	sprite.setTexture(textures[angle][tick%2]);
	tick++;
}