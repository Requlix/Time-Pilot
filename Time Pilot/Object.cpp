#include "Object.h"

Object::Object()
{

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
}

void Object::rotate()
{
	//rotates object
	velocity.x = speed * cos(((2 * asin(1)) / 32) * rotation);
	velocity.y = speed * sin(((2 * asin(1)) / 32) * rotation);
	animation.setFrame(rotation);
}