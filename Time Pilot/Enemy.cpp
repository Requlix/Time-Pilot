#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::move()
{

}

double Enemy::findAngle()
{
	return atan2(512 - getAnimation().getPosition().y , 448 - getAnimation().getPosition().x) + 180;
}


