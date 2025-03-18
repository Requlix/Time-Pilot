#include "Cloud.h"

Cloud::Cloud(int number)
{
	animation.setTextures("cloud", "cloud", 1);
	animation.setOrigin(sf::Vector2f(32,32));
	animation.setFrame(0);
	switch (number)
	{
	case 0:
		animation.setPosition(sf::Vector2f(winSize.x/5., winSize.y*2./5.));
		break;
	case 1:
		animation.setPosition(sf::Vector2f(winSize.x*3./5., winSize.y*4./5.));
		break;
	case 2:
		animation.setPosition(sf::Vector2f(winSize.x*4./5., winSize.y/5.));
		break;
	default:
		animation.setPosition(sf::Vector2f(winSize.x*2./5., winSize.y));
	}
	
}

Cloud::~Cloud()
{

}