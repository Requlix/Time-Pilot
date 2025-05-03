#include "Boss.h"

Boss::Boss(int type, sf::Vector2f pos)
{
	year = std::to_string(type);
	if(type >= 1980 || type == 1918)
		animation.setTextures(year + "boss", year + "boss", 16);
	else
		animation.setTextures(year + "bossu", year + "bossd", 16);

	if (abs(Player::rotation) > 90)
	{
		speed = 2;
		rotation = 180;
	}
	else
	{
		rotation = 0;
		speed = -2;
	}
	animation.setOrigin({64,32});
	animation.setPosition(pos);
	Object::setVelocity(speed,0);
}

Boss::~Boss()
{

}

void Boss::setYear(int type)
{
	year = std::to_string(type);
	if (type >= 1980 || type == 1918)
		animation.setTextures(year + "boss", year + "boss", 16);
	else
		animation.setTextures(year + "bossu", year + "bossd", 16);
}

void Boss::move()
{
	setOffset();
	velocity += sf::Vector2f(speed,0);
	Object::move();
	if (year == "2000")
		animation.setFrame(Player::tick % 2);
	else
	{
		if (rotation == 0)
			animation.setFrame(hits / 3);
		else
			animation.setFrame(hits / 3 + 4);
	}
}

void Boss::setSpeed(double newSpeed)
{
	speed = newSpeed;
}

bool Boss::hit()
{
	hits++;
	if (hits > 9)
	{
		hits = 0;
		return true;
	}
	else
		return false;
}

void Boss::outOfBounds()
{
	if(!inBounds()&&rand()%20==1)
	{
		double radians = Player::rotation * 3.14 / 180.;
		sf::Vector2f temp(448, 512);
		if (Player::rotation > -45 && Player::rotation <= 0)
		{
			temp.x = 928;
			temp.y += Player::rotation / abs(Player::rotation)*tan(radians) * 448;
		}
		else if (Player::rotation > 0 && Player::rotation < 45)
		{
			temp.x = 928;
			temp.y -= Player::rotation / abs(Player::rotation) * tan(radians) * 448;
		}
		else if (Player::rotation > 135)
		{
			temp.x = -32;
			temp.y += Player::rotation / abs(Player::rotation)* tan(radians) * 448;
		}
		else if (Player::rotation < -135)
		{
			temp.x = -32;
			temp.y -= Player::rotation / abs(Player::rotation) * tan(radians) * 448;
		}
		else if (abs(Player::rotation) > 90)
		{
			temp.x = -32;
			temp.y -= Player::rotation / abs(Player::rotation) * 448;
		}
		else {
			temp.x = 928;
			temp.y -= Player::rotation / abs(Player::rotation) * 448;
		}
		if (abs(Player::rotation) > 90)
		{
			speed = 2;
			rotation = 180;
		}
		else
		{
			rotation = 0;
			speed = -2;
		}
		animation.getSprite().setPosition(temp);
	}
}