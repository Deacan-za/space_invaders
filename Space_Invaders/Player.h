//Name:		Deacan
//File:		Player.cpp
//scope:	Declare our Player class
//			This class will control all game events


#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
	Player();
	~Player();

    //Moves the ship
    void move();
 
	//Get values:
	int getYvel();
	int getXvel();
	int getX();
	int getY();
	int getLives();
	int getKills();
	signed int getScore();

	//Set values:
	void setYvel(int yVal);
	void setXvel(int xVal);
	void setPlayerLives();
	void setScore();
	void setKills();
	void setPos();
	void resetKills();
	void resetLives(int lives);
	void resetPlayer();

	Rect GetRect();


	friend class GameEvents;
	friend class LazerList;


private:

	//The X and Y offsets of the ship
    signed int PLAYERXPOS, PLAYERYPOS;

    //The velocity of the ship
    signed int xVel, yVel;

	//To be displayed on onscreen HUD:
	signed int SCORE;
	int LIVES;

	//Number of enemy ships killed:
	int KILLS;
};

#endif