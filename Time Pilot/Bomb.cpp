#include "Bomb.h"

Bomb::Bomb(sf::Vector2f place)
{
	animation.setTextures("bomb", "bomb", 1);
	animation.setFrame(0);
	speed = 8.5;
	animation.setPosition(place);
	tick = Player::tick;
	if (place.x > 112*4) 
	{
		speed = -speed;
	}
	else
		animation.getSprite().rotate(180);
	
}

Bomb::~Bomb()
{

}
void Bomb::move()
{
	setOffset();
	velocity.x += speed;
	velocity.y -= 2*(2.5 - .0855555555 * ( Player::tick-tick));
	animation.setFrame(0);
	Object::move();
	//tick++;
}