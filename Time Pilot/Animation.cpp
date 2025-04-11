#include "Animation.h"

Animation::Animation()
{

}

Animation::~Animation()
{

}

void Animation::setTextures(std::string text1, std::string text2, int length)
{
	/*
	for (int i = 0; i < length; i++)
	{
		sf::Texture tempText1, tempText2;
		tempText1.loadFromFile(text1 + std::to_string(i) + ".png");
		tempText2.loadFromFile(text2 + std::to_string(i) + ".png");
		textures[0].push_back(tempText1);
		textures[1].push_back(tempText2);
	}
	*/
	row1 = text1;
	row2 = text2;
}

sf::Sprite& Animation::getSprite()
{
	return sprite;
}

void Animation::setFrame(int angle)
{
	if (tick % 5 == 0)
		propeler++;

	//sprite.setTexture(textures[propeler % 2][angle]);

	if (propeler % 2 == 0)
		texture.loadFromFile(row1 + std::to_string(angle) + ".png");
	else
		texture.loadFromFile(row2 + std::to_string(angle) + ".png");

	sprite.setTexture(texture);
	sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	tick++;
}

void Animation::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void Animation::setOrigin(sf::Vector2f origin)
{
	sprite.setOrigin(origin);
}

void Animation::move(sf::Vector2f velocity)
{
	sprite.move(velocity);
}