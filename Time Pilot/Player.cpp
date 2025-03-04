#include "Player.h"

Player::Player()
{
    bell.loadFromFile("airman0.png");
    taco.setTexture(bell);
    taco.setOrigin(32, 32);
    taco.setPosition(448, 512);
}

Player::~Player()
{

}

int Player::tick = 0;
double Player::rotation = 0;
double Player::speed = 2;

void Player::move(sf::RenderWindow& window)
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
    taco.setRotation(rotation);
    window.draw(taco);
    tick++;
}


