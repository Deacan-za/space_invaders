//Name:		Deacan
//File:		GameEvents.cpp
//scope:	Define our GameEvents class
//			This class will control all game events

#include "includes.h"

gameEvents::gameEvents()
{
	background = NULL;
	screen = NULL;
	ship = NULL;
	lazer = NULL;
	enemy = NULL;
	message = NULL;
	MessageEnter = NULL;
	MessageLives = NULL;
	HUDLives = NULL;
	MessageScore = NULL;
	PlayerScore = NULL;
	GameOver =NULL;
	font = NULL;
	fontHUD = NULL;
	StartTitle = true;
	gameRunning = true;
}

void gameEvents::gameStart()
{
	SDL_Event event;

	if(SDL_PollEvent(&event))
	{
		if(event.type == SDL_KEYDOWN)
		{
			//Set gameRunning to true:
			switch(event.key.keysym.sym)
			{
				case SDLK_RETURN: StartTitle = false;
			}
		}
		else if(event.type == SDL_QUIT)
		{
			StartTitle = false;
			gameRunning = false;
		}
	}
}

bool gameEvents::gameLoad()
{
	background = load_image("Images\\background.png");
	ship = load_image("Images\\SpaceFlier.png");
	lazer = load_image("Images\\laser.png");
	enemy = load_image("Images\\enemy.png");

	//Open the font:
	font = TTF_OpenFont("Fonts\\BeyondControl.ttf",33);
	fontHUD = TTF_OpenFont("Fonts\\7theb.ttf",40);

    //If there was an error in setting up the backgroud:
   if( background == NULL )
    {
        return false;
    }

	//If there was an error in setting up the ship:
	if(ship == NULL)
	{
		return false;
	}

	////If there was an error in setting up the lazer:
	if(lazer == NULL)
	{
		return false;
	}

	////If there was an error in setting up the enemy:
	if(enemy == NULL)
	{
		return false;
	}

	////If there was an error in setting up the Font:
	if(font == NULL)
	{
		return false;
	}

    //If everything loaded fine
    return true;
}

SDL_Surface* gameEvents::load_image(std::string filename)
{
	//The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );


    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

bool gameEvents::gameInit()	
{
	//Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen:
    if( screen == NULL )
    {
        return false;
    }

	//If there was an error setting up the font:
	if(TTF_Init() == -1)
	{
		return false;
	}

    //Set the window caption
    SDL_WM_SetCaption( "Space Invaders", NULL );

    //If everything initialized fine
    return true;
}

void gameEvents::gameInput(Player *player, LazerList* llist)
{
	SDL_Event event;

	if(SDL_PollEvent(&event))
	{
		//If a key was pressed
		if(event.type == SDL_KEYDOWN)
		{
			//Adjust the velocity
			switch(event.key.keysym.sym)
			{
				case SDLK_UP:		player->setYvel(player->getYvel() - SHIP_HEIGHT / 4); break;
				case SDLK_DOWN:		player->setYvel(player->getYvel() + SHIP_HEIGHT / 4); break;
				case SDLK_LEFT:		player->setXvel(player->getXvel() - SHIP_WIDTH / 4); break;
				case SDLK_RIGHT:	player->setXvel(player->getXvel() + SHIP_WIDTH / 4); break;
				case SDLK_SPACE:	llist->addToHead(player); break;
			}
		}
		//If a key is released
		else if(event.type == SDL_KEYUP)
		{
			//Adjust velocity
			switch(event.key.keysym.sym)
			{
				case SDLK_UP:		player->setYvel(player->getYvel() + SHIP_HEIGHT / 4); break;
				case SDLK_DOWN:		player->setYvel(player->getYvel() - SHIP_HEIGHT / 4); break;
				case SDLK_LEFT:		player->setXvel(player->getXvel() + SHIP_WIDTH / 4); break;
				case SDLK_RIGHT:	player->setXvel(player->getXvel() - SHIP_WIDTH / 4); break;
			}
		}
		else if(event.type == SDL_QUIT)
		{
			gameRunning = false;
		}
	}
}

void gameEvents::gameDraw(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
	//Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

unsigned short int gameEvents::gameDrawText()
{
	//The color of the font:
	SDL_Color textColor = { 255, 255, 0 };
	int w1,h1;
	int w2,h2;

	//Render the text:
    message = TTF_RenderText_Solid( font, "SPACE INVADERS", textColor );
	TTF_SizeText(font, "SPACE INVADERS", &w1, &h1);
	MessageEnter = TTF_RenderText_Solid( font, "Press Enter to start", textColor );
	TTF_SizeText(font, "Press Enter to start", &w2, &h2);

    //If there was an error in rendering the text
    if( message == NULL )
    {
        return 1;    
    }

	if(MessageEnter == NULL)
	{
		return 1;
	}
    
    //Apply the images to the screen
	gameDraw((SCREEN_WIDTH - w1) / 2, (SCREEN_HEIGHT - h1) / 2, message, screen, NULL);
	gameDraw((SCREEN_WIDTH - w2) / 2, ((SCREEN_HEIGHT - h1) / 2) + h2, MessageEnter, screen, NULL);
}

unsigned short int gameEvents::gameDrawHud(Player *player)
{
	//Colorof the font:
	SDL_Color textColor = {255, 255, 0};

	//Converting lives integer to string:
	std::stringstream lives, score;
	lives << player->getLives();
	score << player->getScore();

	//Render the text:
	MessageLives = TTF_RenderText_Solid(fontHUD, "Lives:", textColor);
	MessageScore = TTF_RenderText_Solid(fontHUD, "Score:", textColor);
	HUDLives = TTF_RenderText_Solid(fontHUD, lives.str().c_str(), textColor);
	PlayerScore = TTF_RenderText_Solid(fontHUD, score.str().c_str(), textColor); 

	//If there is an issue loading the text
	if(MessageLives == NULL)
	{
		return 1;
	}

	if(MessageScore == NULL)
	{
		return 1;
	}


}

unsigned short int gameEvents::gameDrawGameOver()
{
	//Color of the font:
	SDL_Color textColor = {255, 255, 0};

	int w1,h1;
	int w2,h2;
	
	//Render the text:
	GameOver = TTF_RenderText_Solid( font, "GAME OVER", textColor );
	TTF_SizeText(font, "GAME OVER", &w1, &h1);
	MessageEnter = TTF_RenderText_Solid( font, "Press Enter to retry", textColor );
	TTF_SizeText(font, "Press Enter to retry", &w2, &h2);
	
	//If there was an error in rendering the text
	if( GameOver == NULL )
	{
	    return 1;    
	}
	
	if(MessageEnter == NULL)
	{
		return 1;
	}
	
	//Apply the images to the screen
	gameDraw((SCREEN_WIDTH - w1) / 2, (SCREEN_HEIGHT - h1) / 2, GameOver, screen, NULL);
	gameDraw((SCREEN_WIDTH - w2) / 2, ((SCREEN_HEIGHT - h1) / 2) + h2, MessageEnter, screen, NULL);
}

unsigned short int gameEvents::gameDrawLevel(int level)
{
	//color of the font:
	SDL_Color textColor = {255, 255, 0};

	int w1, h1;
	int w2, h2;

	//Converting level integer to string:
	std::stringstream lvl;
	lvl << level;

	//Render Text:
	lvlText = TTF_RenderText_Solid(font, "Level:", textColor);
	TTF_SizeText(font, "Level:", &w1, &h1);

	lvlVal = TTF_RenderText_Solid(font, lvl.str().c_str(), textColor);
	TTF_SizeText(font, lvl.str().c_str(), &w2, &h2);

	if(lvlText == NULL)
	{
		return 1;
	}

	if(lvlVal == NULL)
	{
		return 1;
	}

	//Apply the images to the screen
	gameDraw((SCREEN_WIDTH - w1) / 2, (SCREEN_HEIGHT - h1) / 2, lvlText, screen, NULL);
	gameDraw((SCREEN_WIDTH - w2) / 2, ((SCREEN_HEIGHT - h1) / 2) + h2, lvlVal, screen, NULL);

}

void gameEvents::gameUpdate(Player *player)
{
	int lw1,lh1;
	int sw2,sh2;

	gameDraw(0,0,background,screen,NULL);
	gameDraw(player->getX(),player->getY(),ship,screen,NULL);
	gameDraw(0, 0, MessageLives, screen, NULL);
	gameDraw(0, 0, MessageLives, screen, NULL);
	gameDraw(300, 0, MessageScore, screen, NULL);

	TTF_SizeText(fontHUD, "Lives:", &lw1, &lh1);
	gameDraw(OFFSET + lw1, 0, HUDLives, screen, NULL);

	TTF_SizeText(fontHUD, "Score:", &sw2, &sh2);
	gameDraw( (300 + OFFSET + sw2), 0, PlayerScore, screen, NULL);

}

bool gameEvents::gameFlip()
{
	//Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }
}

void gameEvents::gameClean()
{
	SDL_FreeSurface(screen);
	SDL_FreeSurface(background);
	SDL_FreeSurface(ship);
	SDL_FreeSurface(lazer);
	SDL_FreeSurface(enemy);
	SDL_FreeSurface(message);
	SDL_FreeSurface(MessageEnter);
	SDL_FreeSurface(MessageLives);
	SDL_FreeSurface(MessageScore);
	TTF_CloseFont(font);
	TTF_CloseFont(fontHUD);
	SDL_Quit();
	TTF_Quit();
	exit(0);
}

void gameEvents::gameReset()
{
	ship = NULL;
	lazer = NULL;
	enemy = NULL;
}

bool gameEvents::runningState()
{
	return gameRunning;
}

bool gameEvents::titleState()
{
	return StartTitle;
}

void gameEvents::setTilteState(bool val)
{
	StartTitle = val;
}
