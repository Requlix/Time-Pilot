#include "Object.h"

Object::Object()
{
	winSize = { 896,1024 };
}
Object::~Object()
{

}

sf::Vector2f Object::getVelocity()
{
	//returns velocity of objects
	return velocity;
}

sf::Vector2f Object::getPosition()
{
	return animation.getSprite().getPosition();
}

Animation Object::getAnimation()
{
	return animation;
}

bool Object::inBounds()
{
	//returns if objects is in bounds
	int count = 0;

	if (getPosition().y + animation.getSprite().getOrigin().y < 96 ||
		getPosition().y - animation.getSprite().getOrigin().y > 992 ||
		getPosition().x - animation.getSprite().getOrigin().x > 896 ||
		getPosition().y + animation.getSprite().getOrigin().y < 0)
		return false;
	else
		return true;
}

bool Object::collision(Object other)
{
	//returns if objects collides with other object
	return false;
}

bool Object::isAlive()
{
	//checks if object is alive
	return alive;
}

void Object::setOffset()
{
	//sets velocity of object
	setVelocity(-Player::speed * cos(Player::rotation), Player::speed * sin(Player::rotation));
}

void Object::setVelocity(double x, double y)
{
	velocity.x = x;
	velocity.y = y;
}


void Object::die()
{
	//kills object
	alive = false;
}

void Object::move()
{
	int x = velocity.x;
	int y = velocity.y;
	setOffset();
	velocity.x += x;
	velocity.y += y;
	animation.getSprite().move(velocity);//velocity minus player velocity
}

void Object::outOfBounds()
{
	//moves object if it goes out of bounds
	animation.getSprite().move(speed * cos(rotation * 6.28 / 360.), speed * sin(rotation * 6.28 / 360.));
	if (animation.getSprite().getPosition().x < -50)
		animation.getSprite().setPosition(animation.getSprite().getPosition().x + 900, animation.getSprite().getPosition().y);
	if (animation.getSprite().getPosition().x > winSize.x + 50)
		animation.getSprite().setPosition(animation.getSprite().getPosition().x - 900, animation.getSprite().getPosition().y);
	if (animation.getSprite().getPosition().y < -50)
		animation.getSprite().setPosition(animation.getSprite().getPosition().x, animation.getSprite().getPosition().y + 900);
	if (animation.getSprite().getPosition().y > winSize.y + 50)
		animation.getSprite().setPosition(animation.getSprite().getPosition().x, animation.getSprite().getPosition().y - 900);
}

void Object::rotate()
{
	//rotates object
	velocity.x = speed * cos(((2 * asin(1)) / 32) * rotation);
	velocity.y = speed * sin(((2 * asin(1)) / 32) * rotation);
	animation.setFrame(rotation);
}