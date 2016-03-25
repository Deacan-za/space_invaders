//Name:		Deacan
//File:		Enemy.cpp
//scope:	Declare our GameEvents class
//			This class will control the enemy ships

#include "includes.h"


Enemy::Enemy():EM_ALIVE(false),EMStartPOS(1028),ENEMYXPOS(1028),ENEMYYPOS(0),EMxVel(0),EMyVel(0),NEXT(NULL)
{
}

Enemy::~Enemy()
{
}

signed int Enemy::getEnemyXvel()
{
	return EMxVel;
}

signed int Enemy::getEnemyYvel()
{
	return EMyVel;
}

signed int Enemy::getEnemyXpos()
{
	return ENEMYXPOS;
}

signed int Enemy::getEnemyYpos()
{
	return ENEMYYPOS;
}

void Enemy::setEnemyXvel(signed int emxVal)
{
	EMxVel = emxVal;
}

void Enemy::setEnemyYvel(signed int emyVal)
{
	EMyVel = emyVal;
}

void Enemy::setEnemyYpos(signed int ran)
{
	ENEMYYPOS = ran;
}

void Enemy::setEmAlive(bool em_alive)
{
	EM_ALIVE = em_alive;
}

Rect Enemy::GetRect()
{
	return Rect(ENEMYXPOS, ENEMYYPOS, ENEMYXPOS + EMY_WIDTH, ENEMYYPOS + EMY_HEIGHT);
}
