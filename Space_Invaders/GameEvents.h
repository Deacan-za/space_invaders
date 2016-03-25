//Name:		Deacan
//File:		GameEvents.h
//scope:	Declare our GameEvents class
//			This class will control all game events

#ifndef GAMEEVENTS_H
#define GAMEEVENTS_H
#include <string>

class gameEvents
{
public:
	gameEvents();

	bool gameLoad();
	void gameStart();
	SDL_Surface *load_image(std::string filename);
	bool gameInit();
	void gameInput(Player* player1, LazerList* llist);
	void gameDraw(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
	unsigned short int gameDrawText();
	unsigned short int gameDrawHud(Player *player);
	unsigned short int gameDrawGameOver();
	unsigned short int gameDrawLevel(int level); 
	void gameUpdate(Player *player);
	void gameUpdateLazer(LazerList *llist);
	void gameUpdateEnemy(EnemyList *elist);
	void gameClean();
	void gameReset();
	void setTilteState(bool val);
	bool runningState();
	bool titleState();
	bool gameFlip();


	friend class Player;
	friend class Lazer;
	friend class LazerList;
	friend class EnemyList;

private:
	SDL_Surface* background;
	SDL_Surface* screen;
	SDL_Surface* ship;
	SDL_Surface* lazer;
	SDL_Surface* enemy;
	SDL_Surface* message;
	SDL_Surface* MessageEnter;
	SDL_Surface* MessageLives;
	SDL_Surface* HUDLives;
	SDL_Surface* MessageScore;
	SDL_Surface* PlayerScore;
	SDL_Surface* GameOver;
	SDL_Surface* lvlText;
	SDL_Surface* lvlVal;
	TTF_Font *font;
	TTF_Font *fontHUD;

	bool StartTitle;
	bool gameRunning;
};

#endif