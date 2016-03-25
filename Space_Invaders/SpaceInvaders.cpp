//Name:		Deacan
//File:		SpaceInvader.cpp
//scope:	Main cpp file.

#include "includes.h"

//Function Declaration:

unsigned int RandomNumber();

int main( int argc, char* args[] )
{
	/* initialize random seed: */
	srand ((unsigned)time(NULL));

	//Create instances of the gameEvents object:
	gameEvents *GE = new gameEvents();
	Player *player = new Player();
	LazerList* LList = new LazerList();
	EnemyList* EList = new EnemyList();

	//add initial Enemy ship to list:
	signed int ran = RandomNumber();
	EList->addEtoHead(ran);

	int frameNumber = 0;

	//Random number for enemy ship postion:
	unsigned int ranNum = 0;

	//Level counter: NOT USED YET
	unsigned int lvl = 1;

	Uint32 startTime = SDL_GetTicks();

	////Initialize
	if( GE->gameInit() == false )
    {
        return 1;
    }

    //Load the files
    if( GE->gameLoad() == false )
    {
        return 1;
    }

	/*For the Title screen
	checks the the StartTitle bool is true
	While its true the the Title screen shows*/
	while(GE->titleState())
	{
		//Draw the Text on screen:
		GE->gameDrawText();

		//Checks for and event. If event = enter games starts.
		GE->gameStart();

		//Refresh the screen:
		GE->gameFlip();
	}

	while(GE->runningState())
	{	
		if(player->getLives() >=0)
		{
			//Determine the level:
			if(player->getKills() >= (5 * lvl))
			{
				GE->setTilteState(true);
				lvl += 1;
				while(GE->titleState())
				{
					player->resetKills();
					player->setPos();

					//Draw the Text on screen:
					GE->gameDrawLevel(lvl);

					//Checks for and event. If event = enter games starts.
					GE->gameStart();

					//Refresh the screen:
					GE->gameFlip();
				}
			}

			frameNumber++;

			//Draw HUD:
			GE->gameDrawHud(player);

			//Handle Events:
			GE->gameInput(player,LList);

			//Update:
			GE->gameUpdate(player);
			player->move();
			
			LList->moveLazer(GE);

  			if(LList->getListSize() != 0)
			{
				LList->checkCollision();
			}

			EList->moveEnemy(lvl);
			
			/*If the Enemy List is less than 10 and the last object
			added has moved X pixels then added next object: 
			*/
			if(EList->getELsize() < 10)
			{
				if(EList->getELsize() == 0)
				{
					signed int ran = RandomNumber();
					EList->addEtoHead(ran);
				}   
				else if(EList->EnemyMoved())// What if the EList size is zero... The Head would be null
				 {
					signed int ran = RandomNumber();
					EList->addEtoHead(ran);
				}
			}


			EList->drawEnemy(GE);
		
			//If the EmenyList is not empty:
			if(EList->getELsize() != 0)
			{
        		EList->checkEnemyCollision(player);
  				EList->checkEnemyKilled(LList, player);
				LList->checkCollision();
			}
		 
			//Refresh the screen:
			GE->gameFlip();

			 //=================== Framerate capping =========================//
			Uint32 timeshouldTacken = startTime + frameNumber *FPS;
			Uint32 timeItTook = SDL_GetTicks();

			if(timeItTook <= timeshouldTacken )
			{
				SDL_Delay(timeshouldTacken - timeItTook);
			}
			else
			{
				//if it took longer than it should
				//reset the frames and the startTime
				frameNumber = 0;
				startTime = SDL_GetTicks();
			}
		}
		else
		{

			GE->setTilteState(true);

			while(GE->titleState())
			{
				//Refresh the screen:
				//Set player, enemy and lazer surface back to NULL:
				GE->gameReset();
				GE->gameUpdate(player);

				//Draw the Text on screen:
				GE->gameDrawGameOver();

				//Checks for and event. If event = to enter, games restarts.
				GE->gameStart();

				//Refresh the screen:
				GE->gameFlip();
			}

			//Clean Previous games objects:
			player->resetPlayer();
			EList->clearEmemyList();

			//add initial Enemy ship to list:
			signed int ran = RandomNumber();
			EList->addEtoHead(ran);

			//reset the level:
			lvl = 1;

			//reload the files:
			if(GE->gameLoad() == false)
			{
				return 1;
			}
		}
	}

	//Close SDL
	GE->gameClean();

	delete GE;
	delete player;
	delete LList;
	delete EList;

	return 0;
}

//Function Definition:
//Generate random y position for enemy ships.
unsigned int RandomNumber()
{
	return rand() % (500 - HUD) + 10;
}