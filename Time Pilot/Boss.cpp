#include "Boss.h"

Boss::Boss(int type, sf::Vector2f pos)
{
	year = std::to_string(type);
	if(type == 2000)
		animation.setTextures(year + "boss", year + "boss", 16);
	else
		animation.setTextures(year + "bossu", year + "bossd", 16);

	if (abs(Player::rotation) > 90)
	{
		speed = 3;
		rotation = 180;
	}
	else
	{
		rotation = 0;
		speed = -3;
	}

	animation.setPosition(pos);
		
}

Boss::~Boss()
{

}

void Boss::move()
{
	Enemy::setVelocity();
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

bool Boss::hit()
{
	hits++;
	return hits > 9;
}
