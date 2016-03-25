//Name:		Deacan
//File:		EnemyList.h
//scope:	Declare the enmey list class
//			This class will control the list for the enemy list


#ifndef ENEMYLIST_H
#define ENEMYLIST_H

class gameEvents;
class EnemyList
{
public:
	EnemyList();
	~EnemyList();

	void addEtoHead(signed int ran);
	void enemyCheckAlive();
	void moveEnemy(int level);
	void drawEnemy(gameEvents *GE);
	void checkEnemyCollision(Player* player);
	void checkEnemyKilled(LazerList* llist, Player* player);
	void clearEmemyList();
	unsigned int getELsize();
	signed int getEmXpos();
	signed int getEmStart();
	signed int getEmYpos();
	bool EnemyMoved();


	friend class Enemy;
	friend class Player;

private:
	Enemy* ELHEAD;
	unsigned int EL_SIZE;
};

#endif
