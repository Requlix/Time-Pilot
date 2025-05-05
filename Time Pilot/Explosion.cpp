#include "Explosion.h"

Explosion::Explosion(std::string thing, sf::Vector2f place)
{
	type = thing;
	animation.setPosition(place);
	animation.setTextures(type + "explosion", type + "explosion", 16);
}
Explosion::~Explosion()
{

}

void Explosion::move()
{
	setOffset();
	Object::move();
	animation.setFrame(tick / 5);
	tick++;
}
