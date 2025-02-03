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
}

sf::Vector2f Object::getVelocity()
{
	//returns velocity of objects
}

void Object::setLocation()
{
	//sets location of object
}

void Object::setVelocity()
{
	//sets velocity of object
}

void Object::die()
{
	//kills object
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