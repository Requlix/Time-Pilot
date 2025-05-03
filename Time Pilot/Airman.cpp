#include "Airman.h"
Airman::Airman()
{
	animation.setTextures("airman", "airman", 1);
	animation.setFrame(0);
	animation.setPosition({ 448,160 });
}

Airman::~Airman()
{

}

void Airman::move()
{
	Object::setOffset();

	if ((tick++) % 30 == 0)
		animation.setFrame((otherTick++) % 4);

	velocity.y += 1;
	Object::move();
}