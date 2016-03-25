//Name:		Deacan
//File:		EnemyList.cpp
//scope:	Define the enmey list class
//			This class will control the list for the enemy list

#include "includes.h"

EnemyList::EnemyList():ELHEAD(NULL), EL_SIZE(0)
{
}

EnemyList::~EnemyList()
{
}

//add to the head of the list:
void EnemyList::addEtoHead(signed int ran)
{
	Enemy* newOne = new Enemy();
	newOne->setEmAlive(true);
	newOne->setEnemyYpos(ran);

	if(ELHEAD == NULL)
	{
		ELHEAD = newOne;
	}
	else
	{
		newOne->NEXT = ELHEAD;
		ELHEAD = newOne;
	}
	EL_SIZE++;
}

void EnemyList::moveEnemy(int level)
{
	Enemy* tp = ELHEAD;

	while(tp != 0)
	{
		//Move the lazer right
 		tp->setEnemyXvel(tp->getEnemyXvel() + EMY_WIDTH/ ( 100 / level) );
		tp->ENEMYXPOS -= tp->EMxVel;
		tp = tp->NEXT;
	}
}

void EnemyList::drawEnemy(gameEvents *GE)
{
	Enemy* tp = ELHEAD;

	while(tp != 0)
	{
		GE->gameDraw(tp->getEnemyXpos(), tp->getEnemyYpos(), GE->enemy, GE->screen, NULL);
		tp = tp->NEXT;
	}
}

//Check if the enemy ship gets the the end of the screen:
void EnemyList::checkEnemyCollision(Player* player)
{

	//Case 1: Empty List
	if(ELHEAD == 0)
	{
		return;
	}
	else
	{
		Enemy* curr = ELHEAD;
		Enemy* trail = 0;

		while(curr != 0)
		{
			if(curr->getEnemyXpos() < 0)
			{
				//Case 2: delete from head:
				if(ELHEAD == curr)
				{
					ELHEAD = ELHEAD->NEXT;
					delete curr;
					curr = ELHEAD;
					EL_SIZE--;
				}

				//Case 3: Delete within the list:
				else
				{
					trail->NEXT = curr->NEXT;
					delete curr;
					curr = trail->NEXT;
					EL_SIZE--;
				}
			}
			else if(curr->GetRect().Intersects(player->GetRect()))
			{
				//Case 2: delete from head:
				if(ELHEAD == curr)
				{
					ELHEAD = ELHEAD->NEXT;
					delete curr;
					curr = ELHEAD;
					EL_SIZE--;
					player->setPlayerLives();
					player->setPos();
				}
				
				//Case 3: Delete within the list:
				else
				{
					trail->NEXT = curr->NEXT;
					delete curr;
					curr = trail->NEXT;
					EL_SIZE--;
					player->setPlayerLives();
					player->setPos();
				}
			}
			else
			{
				//Push the pointers along the list:
				trail = curr;
				curr = curr->NEXT;
			}
		}
	}
}

unsigned int EnemyList::getELsize()
{
	return EL_SIZE;
}

signed int EnemyList::getEmXpos()
{
	Enemy *tp = ELHEAD;

	while (tp != 0)
	{
		if(tp->NEXT == NULL)
		{
			return tp->getEnemyXpos();
		}
		else
		{
			tp = tp->NEXT;
		}
	}
}

signed int EnemyList::getEmStart()
{
	Enemy* tp = ELHEAD;

	while(tp != 0)
	{
		if(tp->NEXT == NULL)
		{
			return tp->EMStartPOS;
		}
		else
		{
			tp = tp->NEXT;
		}
	}
}

bool EnemyList::EnemyMoved()
{
	if(ELHEAD->EMStartPOS - ELHEAD->getEnemyXpos() >= 300)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//This is where I seem to be having the issue:
void EnemyList::checkEnemyKilled(LazerList *llist, Player* player)
{
	Lazer* beam = llist->HEAD;
	
	while(beam != 0)
	{
		Enemy* curr = ELHEAD;
		Enemy* trail = 0;

		while(curr != 0 )
 		{
			if(curr->GetRect().Intersects(beam->GetRect()))
			{
				//Case 2: delete from head:
				if(ELHEAD == curr)
				{
					ELHEAD = ELHEAD->NEXT;
					delete curr;
					curr = ELHEAD;
					EL_SIZE--;
					beam->setAlive(false);
					player->setScore();
					player->setKills();
				}
			
				//Case 3: Delete within the list:
				else
				{
					trail->NEXT = curr->NEXT;
					delete curr;
					curr = trail->NEXT;
					EL_SIZE--;
					beam->setAlive(false);
					player->setScore();
					player->setKills();
				}
			}
			else
			{
				//Push the pointers along the list:
				trail = curr;
				curr = curr->NEXT;
			}
		}
		beam = beam->NEXT;
	}
}

void EnemyList::clearEmemyList()
{
	Enemy* tp = ELHEAD;

	while(tp != 0)
	{
		ELHEAD = tp->NEXT;
		delete tp;
		tp = ELHEAD;
		EL_SIZE--;
	}
}