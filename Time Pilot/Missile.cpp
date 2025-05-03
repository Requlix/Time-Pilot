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
    bool shoot = false;
    sf::Vector2f goal(0, 0);
    goal.x = 896 / 2. - getPosition().x;
    goal.y = 864 / 2. + 128 - getPosition().y;
    int q = atan2(goal.y, goal.x) * 360. / 6.28;
    int agoal;
    if (q < 0)
        q += 360;

    if (Player::tick % 20 == 0)
    {
        agoal = rotation - q;
        int range1 = rotation - 12;
        int range2 = rotation + 12;
        if (range1 < -180)
            range1 += 360;
        if (range2 > 180)
            range2 -= 360;
        if (!(q > range1 && q < range2 && rand() % 2 == 0))
        {
            if (abs(agoal) > 180)
                agoal *= -1;
            if (agoal > 0)
                rotation -= rotateSpeed;
            else
                rotation += rotateSpeed;
        }
    }
    if (rotation >= 360)
        rotation -= 360;
    if (rotation < 0)
        rotation += 360;

    setVelocity();
    Object::move();

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