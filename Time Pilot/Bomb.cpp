#include "Bomb.h"

Bomb::Bomb(double x,double y)
{
	/*
	speed = 3;
	getAnimation().setPosition(x, y);
	tick = Player::tick;
	if (x > 112*4) 
	{
		getAnimation().rotate(180);
		speed = -speed;
	}
	*/
}

Bomb::~Bomb()
{

}
void Bomb::move()
{
	setOffset();
	velocity.x += speed;
	velocity.y -= 2*(2.5 - .055555555 * (tick - Player::tick));
	Object::move();
	tick++;
}