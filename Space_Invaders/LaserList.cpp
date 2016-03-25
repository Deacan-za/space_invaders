//Name:		Deacan
//File:		LazerList.cpp
//scope:	Define our Lazer list class
//			This class will control the lazer List

#include "includes.h"


LazerList::LazerList():HEAD(NULL), LL_SIZE(0)
{
}

LazerList::~LazerList()
{
}

signed short LazerList::getListSize()
{
	return LL_SIZE;
}

void LazerList::addToHead(Player *player)
{
	Lazer* newOne = new Lazer();
	newOne->setAlive(true);
	newOne->setXYpos(player->getX() + (SHIP_WIDTH/2), player->getY() + (SHIP_HEIGHT/2));

	if(HEAD == 0)
	{
		HEAD = newOne;
	}
	else
	{
		newOne->NEXT = HEAD;
		HEAD = newOne;
	}
	LL_SIZE++;
}

//void LazerList::checkAlive()
//{
//	Lazer* tp = HEAD;
//	
//	while(tp != 0)
//	{
//		signed int xpostion = tp->getLazerXpos();
//		signed int yposition = tp->getLazerYpos();
//		tp = tp->NEXT;
//	}
//}

void LazerList::moveLazer(gameEvents *GE)
{
	Lazer* tp = HEAD;

	while(tp != 0)
	{
		//Move the lazer right
 		tp->setLazerVel(tp->getLazerVel() + LAZER_WIDTH / 2);
		tp->XPOS += tp->LAZERXVEL;
		GE->gameDraw(tp->getLazerXpos(), tp->getLazerYpos(), GE->lazer, GE->screen, NULL);
		tp = tp->NEXT;
	}
}

void LazerList::checkCollision()
{
	//Case 1: Empty list:
   	if(HEAD == 0)
	{
 		return;
	}
	else
	{
		Lazer* curr = HEAD;
		Lazer* trail = 0;

		while(curr != 0)
		{
			if((curr->getLazerXpos() + LAZER_WIDTH > SCREEN_WIDTH) || curr->ALIVE == false)
			{
				//Case 2: Delete from Head:
				if(HEAD == curr)
				{
					HEAD = HEAD->NEXT;
					delete curr;
					curr = HEAD;
   					LL_SIZE--;
				}
			
				//Case 3: Delete within the list:
				else
				{
					trail->NEXT = curr->NEXT;
					delete curr;
					curr = trail->NEXT;
   					LL_SIZE--;
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
