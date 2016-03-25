//Name:		Deacan
//File:		Enemy.h
//scope:	Declare the enmy class
//			This class will control the enemy ships

#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
public:
	Enemy();
	~Enemy();

	//Get values:
	signed int getEnemyXvel();
	signed int getEnemyYvel();
	signed int getEnemyXpos();
	signed int getEnemyYpos();

	//Set values:
	void setEnemyYpos(signed int ran);
	void setEnemyYvel(signed int emyVal);
	void setEnemyXvel(signed int emxVal);
	void setEmAlive(bool em_alive);

	Rect GetRect();

	friend class EnemyList;
	friend class LaserList;

private:

	bool EM_ALIVE;

	signed int EMStartPOS;

	//The X and Y offsets of the enemy
    signed int ENEMYXPOS, ENEMYYPOS;

    //The velocity of the enemy
    signed int EMxVel, EMyVel;

	//Pointer to next item on the list:
	Enemy *NEXT;
};

#endif