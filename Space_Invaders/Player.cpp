//Name:		Deacan
//File:		Player.cpp
//scope:	Declare our Player class
//			This class will control all game events

#include "includes.h"


Player::Player()
{
	//Initialize the offsets
	PLAYERXPOS = 0;
	PLAYERYPOS = (SCREEN_HEIGHT - (HUD + (SHIP_HEIGHT/2)) )/2;

    //Initialize the velocity
    xVel = 0;
    yVel = 0;

	//Initialize Player score:
	SCORE = 0;

	//Initialize Player Lives:
	LIVES = 2;

	//Initialize Player kills:
	KILLS = 0;
}

Player::~Player()
{
}

void Player::move()
{
    //Move the Ship left or right
	PLAYERXPOS += xVel;

    //If the ship went too far to the left or right
    if( ( PLAYERXPOS < 0 ) || ( PLAYERXPOS + SHIP_WIDTH > SCREEN_WIDTH ) )
    {
        //move back
        PLAYERXPOS -= xVel;
    }

    //Move the ship up or down
	PLAYERYPOS += yVel;

    //If the ship went too far up or down
	if( ( PLAYERYPOS < HUD ) || ( PLAYERYPOS + SHIP_HEIGHT > SCREEN_HEIGHT ) )
    {
        //move back
        PLAYERYPOS -= yVel;
    }
}

//get X velocity
int Player::getXvel()
{
	return xVel;
}

//get Y velocity
int Player::getYvel()
{
	return yVel;
}

//get X Offset
int Player::getX()
{
	return PLAYERXPOS;
}

//get Y Offset
int Player::getY()
{
	return PLAYERYPOS;
}

//get player lives:
int Player::getLives()
{
	return LIVES;
}

//get player kills:
int Player::getKills()
{
	return KILLS;
}

//get players score:
signed int Player::getScore()
{
	return SCORE;
}

//set X velocity
void Player::setXvel(int xVal)
{
	xVel = xVal;
}

//set X velocity
void Player::setYvel(int yVal)
{
	yVel = yVal;
}

void Player::setPlayerLives()
{
	LIVES -= 1;
}

void Player::setScore()
{
	SCORE += KILLPOINTS;
}

void Player::setKills()
{
	KILLS += 1;
}

void Player::setPos()
{
	//Initialize the offsets
	PLAYERXPOS = 0;
	PLAYERYPOS = (SCREEN_HEIGHT - (HUD + (SHIP_HEIGHT/2)) )/2;

	//Initialize the velocity
    xVel = 0;
    yVel = 0;
}

void Player::resetKills()
{
	KILLS = 0;
}

void Player::resetLives(int lives)
{
	LIVES = lives;
}

void Player::resetPlayer()
{
	//Initialize the offsets
	PLAYERXPOS = 0;
	PLAYERYPOS = (SCREEN_HEIGHT - (HUD + (SHIP_HEIGHT/2)) )/2;

    //Initialize the velocity
    xVel = 0;
    yVel = 0;

	//Initialize Player score:
	SCORE = 0;

	//Initialize Player Lives:
	LIVES = 2;

	//Initialize Player kills:
	KILLS = 0;
}

Rect Player::GetRect()
{
	return Rect(PLAYERXPOS, PLAYERYPOS, PLAYERXPOS + SHIP_WIDTH, PLAYERYPOS + SHIP_HEIGHT);
}
