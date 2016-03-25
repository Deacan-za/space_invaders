//Name:		Deacan
//File:		Includes.cpp
//scope:	Define our Lazer node class
//			This class will control the lazer

#include "includes.h"

Lazer::Lazer():NEXT(NULL), ALIVE(false), XPOS(0), YPOS(0), LAZERXVEL(0)
{
}

Lazer::~Lazer()
{
}

void Lazer::setXYpos(signed int Lx, signed int Ly)
{
	XPOS = Lx;
	YPOS = Ly;
}

void Lazer::setAlive(bool alive)
{
	ALIVE = alive;
}

void Lazer::setLazerVel(signed int lazerVel)
{
	LAZERXVEL = lazerVel;
}

signed int Lazer::getLazerXpos()
{
	return XPOS;
}

signed int Lazer::getLazerYpos()
{
	return YPOS;
}

signed int Lazer::getLazerVel()
{
	return LAZERXVEL;
}

Rect Lazer::GetRect()
{
	return Rect(XPOS, YPOS, XPOS + LAZER_WIDTH, YPOS + LAZER_HEIGHT);
}