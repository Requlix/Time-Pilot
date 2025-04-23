#include "Bomb.h"

Bomb::Bomb(sf::Vector2f place)
{
	animation.setTextures("airman", "airman", 1);
	animation.setFrame(0);
	speed = 9;
	animation.setPosition(place);
	tick = Player::tick;
	if (place.x > 112*4) 
	{
		animation.getSprite().rotate(180);
		speed = -speed;
	}
	
}

Bomb::~Bomb()
{

}
void Bomb::move()
{
	setOffset();
	velocity.x += speed;
	velocity.y -= 2*(2.5 - .0855555555 * ( Player::tick-tick));
	Object::move();
	//tick++;
}