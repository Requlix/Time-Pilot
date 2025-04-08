#include "Animation.h"

Animation::Animation()
{

}

Animation::~Animation()
{

}

void Animation::setTextures(std::vector<sf::Texture>& temp1, std::vector<sf::Texture>& temp2)
{
	textures[0] = temp1;
	textures[1] = temp2;
}

sf::Sprite& Animation::getSprite()
{
	return sprite;
}

void Animation::setFrame(int angle)
{
	if (tick % 5 == 0)
		propeler++;
		sprite.setTexture(textures[propeler % 2][angle]);
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