//Name:		Deacan
//File:		LazerList.h
//scope:	Declare our Lazer list class
//			This class will control the lazer List

#ifndef LAZERLIST_H
#define LAZERLIST_H

class gameEvents;
class LazerList
{
public:
	LazerList();
	~LazerList();

	void addToHead(Player *player);
	void checkCollision();
	void moveLazer(gameEvents *GE);
	signed short getListSize();

	friend class EnemyList;

private:
	Lazer* HEAD;
	signed short LL_SIZE;
};

#endif