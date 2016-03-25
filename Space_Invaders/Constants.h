//Name:		Deacan
//File:		Constants.h
//scope:	Declare our contants

#ifndef CONSTANTS_H
#define CONSTANTS_H

//Screen attributes
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

//Player ship attributes:
const int SHIP_WIDTH = 128;
const int SHIP_HEIGHT = 69;

//Enemy ship attributes:
const int EMY_WIDTH = 103;
const int EMY_HEIGHT = 52;

//Lazer attributes
const int LAZER_WIDTH = 58;
const int LAZER_HEIGHT = 24;

//The frames per second
const int FRAMERATE = 25;
const float FPS = 1000.f / FRAMERATE;

//Area for HUD
const int HUD = 30;

//Text offset:
const int OFFSET = 10;

//Points allocated for a kill:
const int KILLPOINTS = 25;

#endif