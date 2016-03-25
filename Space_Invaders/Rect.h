//Name:		Deacan
//File:		Rect.h
//scope:	Declare our Rect class 
//			This class will control the Hit boxes for objects

#ifndef RECT_H
#define RECT_H

class Rect
{
public:
	Rect(signed short int x1, signed short int y1, signed short int x2, signed short int y2);
	~Rect();

	bool Intersects(const Rect other);

private:
	signed short int x1, y1, x2, y2;
};

#endif