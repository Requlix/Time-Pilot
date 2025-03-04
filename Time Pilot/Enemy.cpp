#include "Enemy.h"

Enemy::Enemy()
{

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
    if (q < 0)
        q += 360;
    
    if (Player::tick % 20 == 0)
    {
        if (rotation != q && q > 180)
        {
            if (rotation > (q + 180) % 360 && rotation < q)
            {
                rotation += rotateSpeed;
            }
            else
            {
                rotation -= rotateSpeed;
            }
        }
        if (rotation != q && q <= 180)
        {
            if (rotation < (q + 180) % 360 && rotation > q)
            {
                rotation -= rotateSpeed;
            }
            else
            {
                rotation += rotateSpeed;
            }
        }
    }
    
    if (rotation > 360)
        rotation -= 360;
    if (rotation < 0)
        rotation += 360;
    
    velocity.x = speed * cos(rotation * 6.28 / 360.); 
    velocity.y = speed * sin(rotation * 6.28 / 360.);
    getAnimation().move(-velocity);
}


