#include "Cloud.h"

Cloud::Cloud(int number)
{
	pos = number;
	switch (number)
	{
	case 0:
		animation.setPosition({ 716, 160});
		break;
	case 1:
		animation.setPosition({16,	416});
		break;
	case 2:
		animation.setPosition({224,384});
		break;
	case 3:
		animation.setPosition({538,416});
		break;
	case 4:
		animation.setPosition({ 180,704 });
		break;
	case 5:
		animation.setPosition({ 16,864 });
		break;
	case 6:
		animation.setPosition({ 568,864 });
		break;
	case 7:
		animation.setPosition({ 844,800 });
		break;
	default:
		//mini clouds
		break;
	}

}

Cloud::~Cloud()
{

}

void Cloud::setYear(int type)
{
	animation.setTextures(std::to_string(type) + "cloud", std::to_string(type) + "cloud", 1);
	int frame;
	switch (pos)
	{
	case 0:
	case 4:
		frame = 0;
		break;
	case 3:
	case 5:
		frame = 1;
		break;
	case 1:
	case 6:
		frame = 2;
		break;
	case 2:
	case 7:
		frame = 3;
		break;
	}
	animation.setFrame(frame);

	switch (pos)
	{
	case 0:
		animation.setPosition({ 716, 160 });
		break;
	case 1:
		animation.setPosition({ 16,	416 });
		break;
	case 2:
		animation.setPosition({ 224,384 });
		break;
	case 3:
		animation.setPosition({ 538,416 });
		break;
	case 4:
		animation.setPosition({ 180,704 });
		break;
	case 5:
		animation.setPosition({ 16,864 });
		break;
	case 6:
		animation.setPosition({ 568,864 });
		break;
	case 7:
		animation.setPosition({ 844,800 });
		break;
	default:
		//mini clouds
		break;
	}
}