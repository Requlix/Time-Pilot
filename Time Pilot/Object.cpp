#include "Object.h"

Object::Object()
{

}
Object::~Object()
{

}

sf::Vector2f Object::getLocation()
{
	//returns location of object
	return location;
}

sf::Vector2f Object::getVelocity()
{
	//returns velocity of objects
	return velocity;
}

void Object::setLocation(sf::Vector2f place)
{
	//sets location of object
	location = place;
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
}

void Object::outOfBounds()
{
	//moves object if it goes out of bounds
}

void Object::rotate()
{
	//rotates object
}

bool Object::inBounds()
{
	//returns if objects is in bounds
}

bool Object::collision(Object thing)
{
	//returns if objects collides with other object
	return false;
}

bool Object::isAlive()
{
	//checks if object is alive
	return alive;
}

int Object::getRotation()
{
	return rotation;
}