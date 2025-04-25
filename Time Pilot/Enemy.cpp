#include "Enemy.h"

Enemy::Enemy()
{
    speed = 2;
    rotation = ((int)(((int)(((int)(Player::rotation + 360) % 360) / 11.25) + 1) / 2) - 1) * 22.5;
    rotateSpeed = 22.5;
}

Enemy::~Enemy()
{

}

bool Enemy::move()
{
    bool shoot = false;
    sf::Vector2f goal(0, 0);
    goal.x = 896 / 2. - getPosition().x;
    goal.y = 864 / 2.+128 - getPosition().y;
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
        if (q > range1 && q < range2&&rand()%2==0)
        {
            shoot = true;
        }
        else {
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
    return shoot;
}

void Enemy::setVelocity()
{
    setOffset();
    velocity.x += speed * cos(rotation * 6.28 / 360.);
    velocity.y += speed * sin(rotation * 6.28 / 360.);
}