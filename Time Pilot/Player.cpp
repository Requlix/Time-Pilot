#include "Player.h"

Player::Player()
{
    tick = 0;
    rotation = 0;
}

Player::~Player()
{

}

void Player::move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (rotation != 180)
        {
            if (rotation > 0)
                rotation += rotateSpeed;
            else
                rotation -= rotateSpeed;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (rotation != 0)
        {
            if (rotation > 0)
                rotation -= rotateSpeed;
            else
                rotation += rotateSpeed;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (rotation != 90)
        {
            if (rotation > -90 && rotation < 90)
                rotation += rotateSpeed;
            else
                rotation -= rotateSpeed;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (rotation != -90)
        {
            if (rotation > -90 && rotation < 90)
                rotation -= rotateSpeed;
            else
                rotation += rotateSpeed;
        }
    }
    if (rotation > 180)
        rotation -= 360;
    if (rotation < -179)
        rotation += 360;
    
    tick++;
}

