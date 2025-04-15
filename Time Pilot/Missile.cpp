#include "Missile.h"

Missile::Missile(int type, sf::Vector2f spawn)
{
	year = type;
	sf::String yearStr = std::to_string(type);

	speed = 8;
	rotation = std::round((((int)(Player::rotation + 360) % 360 / 11.25 + 1) / 2 - 1) * 22.5 - 180);
	if (rotation > 360)
		rotation -= 360;
	rotation -= 360;
	rotation *= -1;
	rotateSpeed = 22.5;

	animation.setPosition(spawn);

	animation.setTextures(yearStr + "missile", yearStr + "missile", 16);
}	

Missile::~Missile()
{
	
}

void Missile::move()
{
	Enemy::move();
	switch (year)
	{
	case 1970:
		animation.setFrame(((int)(abs(rotation - 360) / 22.5)) % 16);
		break;
	case 2000:
		animation.setFrame(Player::tick % 8);
		break;
	default:
		std::cout << "Error: Not a valid year of grunt" << std::endl;
		break;
	}
}