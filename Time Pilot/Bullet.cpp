#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, double angle, std::string side)
{
	type = side;
	animation.setTextures(side + "Bullet", side + "Bullet", 1);
	animation.setFrame(0);
	animation.setOrigin(sf::Vector2f(0, 0));
	animation.setPosition(position);
	rotation = angle;
	speed = 16;
	if (side != "p")
		speed = 8;
}

Bullet::~Bullet()
{

}

void Bullet::move()
{
	Object::setOffset();
	if (type == "s" && tick++ % 5 == 0)
		animation.setFrame((otherTick++) % 8);
	velocity.x += speed * cos(rotation * 6.28 / 360);
	velocity.y += speed * -sin(rotation * 6.28 / 360);
	Object::move();
}