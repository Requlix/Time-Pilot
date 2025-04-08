#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, double angle, std::string side)
{
	animation.setTextures(side + "bullet", side + "bullet", 1);
	animation.setFrame(0);
	animation.setOrigin(sf::Vector2f(0, 0));
	animation.setPosition(position);
	rotation = angle;
	speed = 20;
}

Bullet::~Bullet()
{

}

void Bullet::move()
{
	Object::setOffset();
	velocity.x += speed * cos(rotation * 6.28 / 360);
	velocity.y += speed * -sin(rotation * 6.28 / 360);
	Object::move();
}