#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, double angle)
{
	getAnimation().setPosition(position);
	rotation = angle;
	speed = 5;
}

Bullet::~Bullet()
{

}

void Bullet::move()
{
	Object::setOffset();
	velocity.x += speed * cos(rotation);
	velocity.y += speed * sin(rotation);
	Object::move();
}

