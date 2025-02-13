#include "Animation.h"

Animation::Animation()
{

}

Animation::~Animation()
{

}

void Animation::setFrame(int angle)
{
	setTexture(textures[angle]);
}

void Animation::setTextures(std::vector<sf::Texture> temp)
{
	textures = temp;
}