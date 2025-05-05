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
	if ((type == "O"|| type == "C"|| type == "M"|| type == "B" || type == "P") && tick < 20)
		animation.setFrame(tick / 5);
	else if (type == "G" && tick < 30)
		animation.setFrame(tick / 5);
		

	tick++;
}

bool Explosion::over()
{
	if (type == "G")
		return tick < 30;
	else
		return tick < 20;
}
