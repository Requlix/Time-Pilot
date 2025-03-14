#include "Player.h"

Player::Player()
{
    animation.setTextures("player", "player", 32);
    animation.setOrigin(sf::Vector2f(32, 32));
    animation.setPosition(sf::Vector2f(448, 512));
}

Player::~Player()
{

}

int Player::tick = 0;
double Player::rotation = 0;
double Player::speed = 1.5;

Animation Player::getAnimation()
{
    return animation;
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (rotation != 90)
        {
            if (rotation > -90 && rotation < 90)
                rotation += rotateSpeed;
            else
                rotation -= rotateSpeed;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
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

    animation.setFrame((int)(((int)(rotation+360)%360) / 11.25));

    tick++;
}

void shoot()
{

}


