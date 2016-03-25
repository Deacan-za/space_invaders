//Name:		Deacan
//File:		Rect.cpp
//scope:	Define our Rect class 
//			This class will control the Hit boxes for objects

#include "includes.h"

Rect::Rect(signed short int x1, signed short int y1, signed short int x2, signed short int y2):
x1(x1), y1(y1), x2(x2), y2(y2)
{
}

Rect::~Rect()
{
}

bool Rect::Intersects(const Rect other)
{
	// The rectangles don't Intersects if
    // one rectangle's minimum
    // is greater than the other's maximum

    //Notice I use the ' ! ' (not operator), if any of the statements are true this function returns false.
    return !(x1 > other.x2 || other.x1 > x2 || y1 > other.y2 || other.y1 > y2);
}