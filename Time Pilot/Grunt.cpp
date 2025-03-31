#include "Grunt.h"

Grunt::Grunt(int type, sf::Vector2f spawn)
{
	gruntType = type;
	sf::String year = std::to_string(type);

	speed = 4;

	animation.setPosition(spawn);



	switch (gruntType)
	{
	case 1918:
	case 1920:
		animation.setTextures(year + "planer", year + "planel", 16);
		break;
	case 1970:
		animation.setTextures(year + "plane", year + "plane", 16);
		break;
	case 1980:
		animation.setTextures(year + "planer", year + "planel", 5);
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

void Grunt::move()
{
	Enemy::move();
	switch (gruntType)
	{
	case 1918:
	case 1920:
	case 1970:
		animation.setFrame(((int)(abs(rotation - 360) / 22.5))%16);
		break;
	case 1980:
		//animation.setFrame();
		break;
	case 2000:
		//animation.setFrame();
		break;
	default:
		std::cout << "Error: Not a valid year of grunt" << std::endl;
	}
}
