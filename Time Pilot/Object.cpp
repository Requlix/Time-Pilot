#include "Object.h"

Object::Object()
{
	winSize = { 896,1024 };
}
Object::~Object()
{

}

int Object::getRotation()
{
	return rotation;
}

sf::Vector2f Object::getVelocity()
{
	//returns velocity of objects
	return velocity;
}

bool Object::inBounds()
{
	//returns if objects is in bounds
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

void Object::setRotation(double angle)
{
	rotation = angle;
}

void Object::setVelocity(sf::Vector2f vel)
{
	//sets velocity of object
	velocity = vel;
}

void Object::die()
{
	//kills object
	alive = false;
}

void Object::move()
{
	//moves object given with velocity
	animation.move(velocity);//velocity minus player velocity
}

void Object::outOfBounds()
{
	//moves object if it goes out of bounds
	if (animation.getPosition().x < -50)
		animation.setPosition(animation.getPosition().x + 900, animation.getPosition().y);
	if (animation.getPosition().x > winSize.x + 50)
		animation.setPosition(animation.getPosition().x - 900, animation.getPosition().y);
	if (animation.getPosition().y < -50)
		animation.setPosition(animation.getPosition().x, animation.getPosition().y + 900);
	if (animation.getPosition().y > winSize.y + 50)
		animation.setPosition(animation.getPosition().x, animation.getPosition().y - 900);
}

void Object::rotate()
{
	//rotates object
	velocity.x = speed * cos(((2 * asin(1)) / 32) * rotation);
	velocity.y = speed * sin(((2 * asin(1)) / 32) * rotation);
	animation.setFrame(rotation);
}