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

void Enemy::move()
{
    sf::Vector2f goal(0, 0);
    goal.x = winSize.x / 2. - getPosition().x;
    goal.y = winSize.y / 2. - getPosition().y;
    int q = atan2(goal.y, goal.x) * 360. / 6.28;
    int agoal;
    if (q < 0)
        q += 360;
    
    if (Player::tick % 20 == 0)
    {
        agoal = rotation - q;
        if (abs(agoal) > 180)
            agoal *= -1;
        if (agoal > 0)
            rotation -= rotateSpeed;
        else
            rotation += rotateSpeed;
    }
    if (rotation > 360)
        rotation -= 360;
    if (rotation < 0)
        rotation += 360;

    setVelocity();
    Object::move();
}

void Enemy::setVelocity()
{
    setOffset();
    velocity.x += speed * cos(rotation * 6.28 / 360.);
    velocity.y += speed * sin(rotation * 6.28 / 360.);
}


