#include "Cloud.h"

Cloud::Cloud()
{
	animation.setTextures("cloud", "cloud", 1);
	animation.setOrigin(sf::Vector2f(32,32));
	animation.setPosition(sf::Vector2f(400, 400));
	animation.setFrame(0);
	
}

Cloud::~Cloud()
{

}