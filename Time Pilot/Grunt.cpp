#include "Grunt.h"

Grunt::Grunt(int type, sf::Vector2f spawn)
{
	gruntType = type;
	sf::String year = std::to_string(type);

	speed = 4;
	rotation = std::round((((int)(Player::rotation + 360) % 360 / 11.25 + 1) / 2 - 1) * 22.5 - 180);
	if (rotation > 360)
		rotation -= 360;
	rotation -= 360;
	rotation *= -1;
	rotateSpeed = 22.5;

	animation.setPosition(spawn);



	switch (gruntType)
	{
	case 1918:
	case 1940:
		animation.setTextures(year + "planer", year + "planel", 16);
		break;
	case 1980:
		animation.setTextures(year + "plane", year + "plane", 16);
		break;
	case 1970:
		animation.setTextures(year + "planer", year + "planel", 9);
		break;
	case 2000:
		animation.setTextures(year + "plane", year + "plane", 4);
		break;
	default:
		std::cout << "Error: Not a valid year of grunt" << std::endl;
	}
}

Grunt::~Grunt()
{

}

bool Grunt::move()
{
	bool shoot = false;
	if (Enemy::move())
		shoot = true;
	switch (gruntType)
	{
	case 1918:
	case 1940:
	case 1980:
		animation.setFrame(((int)(abs(rotation - 360) / 22.5)) % 16);
		break;
	case 1970:
		animation.setFrame((int)(abs(abs(rotation-180)-180)/22.5));
		break;
	case 2000:
		animation.setFrame(Player::tick % 4);
		break;
	default:
		std::cout << "Error: Not a valid year of grunt" << std::endl;
	}
	return shoot;
}