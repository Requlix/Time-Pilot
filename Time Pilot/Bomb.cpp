#include "Bomb.h"

Bomb::Bomb(sf::Vector2f place)
{
	speed = 3;
	getAnimation().setPosition(place);
	tick = Player::tick;
	if (place.x > 112*4) 
	{
		getAnimation().getSprite().rotate(180);
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
	velocity.y -= 2*(2.5 - .055555555 * (tick - Player::tick));
	Object::move();
	tick++;
}