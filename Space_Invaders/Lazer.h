//Name:		Deacan
//File:		Includes.h
//scope:	Declare our Lazer node class
//			This class will control the lazer

#ifndef LAZER_H
#define LAZER_H

class gameEvents;
class Lazer
{
public:
	Lazer();
	~Lazer();

	void setAlive(bool alive);
	void setXYpos(signed int Lx, signed int Ly);	
	void setLazerVel(signed int lazerVel);
	signed int getLazerXpos();
	signed int getLazerYpos();
	signed int getLazerVel();

	Rect GetRect();

	friend class LazerList;
	friend class EnemyList;

private:
	Lazer* NEXT;
	bool ALIVE;

	signed int XPOS;
	signed int YPOS;

	signed LAZERXVEL;
};

#endif

