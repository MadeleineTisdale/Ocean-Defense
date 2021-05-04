//****************************************************************************
// File name:	 OceanDefenseDriver.cpp
// Author:		 Kaylie Yamaguchi, Madeleine Tisdale, and Zach Rodriguez
// Date:		   4/26/2017
// Class:		   CS250-02
// Purpose:		 To create an application, Ocean Defense, that uses sprites, 
//             object-oriented code, animation, user interaction, dynamic 
//             memory allocation, and proper object-oriented design 
//             principals.
// Hours:      40 hours
//****************************************************************************

#include "MovingObject.h"
#include "Shark.h"
#include "Trash.h"
#include "ShootingElement.h"
#include "TrashMonster.h"
#include "User.h"
#include "StageOne.h"
#include "StageTwo.h"
#include "StageThree.h"
#include "OceanDefense.h"
#include <cTime>
#include <cMath>
#include "stdlib.h"
#include "SDL_mixer.h"

using namespace std;

//****************************************************************************
// Function:    main
//
// Description: draw one moving sprite and rotate one sprite on the screen
//
// Parameters:  argc, argv: command line arguments
//
// Returned:    EXIT_SUCCESS on success
//****************************************************************************
int main(int argc, char *argv[])
{
	// Seed the random number generator
	srand(static_cast<unsigned> (time(static_cast<time_t *>(NULL))));

	int windowXPosition = 100,
		windowYPosition = 100,
		windowSizeX = 850,
		windowSizeY = 600;
	int xVal = 0;
	int yVal = 0;

	//Load Music PTR
	Mix_Music *music = NULL;

	// Initialize SDL.
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		return -1;

	//Initialize SDL_mixer 
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
		return -1;
	SDLManager &rcManager = SDLManager::instance();
	SDL_Event uEvent;


	rcManager.initializeWorld(windowXPosition, windowYPosition,
		windowSizeX, windowSizeY);

	music = Mix_LoadMUS("BattleMusic.oga");

	if (music == NULL)
		return -1;


	Mix_PlayMusic(music, -1);



	SDLSprite cBackgroundSprite("Images\\Background.png", 0, 0);
	SDLSprite cStartGameButton("Images\\StartButton.png", 360, 400);
	SDLSprite cExitGameButton("Images\\ExitGame.png", 360, 450);
	SDLSprite cPlayAgainButton("Images\\PlayAgain.png", 360, 400);

	OceanDefense cOceanDefense;

	rcManager.setBackgroundColor(Color::WHITE);
	rcManager.setForegroundColor(Color::WHITE);


	rcManager.animationStart();
	rcManager.clearBackground();

	// game loop
	while (rcManager.animationIsRunning())
	{
		// update
		// move items, change position of objects.
		cOceanDefense.beginNewStage();
		rcManager.mousePosition(xVal, yVal);
		cOceanDefense.updateUser(xVal, yVal);
		cOceanDefense.updateObjects();
		cOceanDefense.handleCollisions(rcManager);

		// end update code

		rcManager.clearBackground();

		// draw
		// draw items on the screen.

		if (cOceanDefense.isGameStarted()) {
			cBackgroundSprite.draw();
			cOceanDefense.drawObjects();
			cOceanDefense.drawUser();
		}

		else {
			cBackgroundSprite.draw();
			cOceanDefense.drawStartInstructions(rcManager);
			cStartGameButton.draw();
			cExitGameButton.draw();
		}

		if (cOceanDefense.isGameDone()) {
			cOceanDefense.drawGameOver(rcManager);
			cOceanDefense.drawWin(rcManager);
			cPlayAgainButton.draw();
			cExitGameButton.draw();
		}

		// end draw code


		if (rcManager.getSDLEvent(uEvent))
		{
			if (SDL_MOUSEBUTTONDOWN == uEvent.type) {
				rcManager.mousePosition(xVal, yVal);
				if (cExitGameButton.clicked(xVal, yVal)) {
					uEvent.type = SDL_QUIT;
				}
			}
			if (uEvent.type == SDL_QUIT)
			{
				rcManager.animationStop();

				// customize QUIT event handling

				// end QUIT event handling
			}

			// handle event

			 // If the mouse is clicked then call startGame
			if (SDL_MOUSEBUTTONDOWN == uEvent.type) {
				rcManager.mousePosition(xVal, yVal);
				if ((!(cOceanDefense.isGameStarted())) && cStartGameButton.clicked(xVal, yVal)) {
					cOceanDefense.startGame();
				}
				else if (cPlayAgainButton.clicked(xVal, yVal)) {
					cOceanDefense.playAgain();
				}
			}

			// end handle event code
		}

		rcManager.render();
	}

  // clean up music
  Mix_FreeMusic (music);

  // quit SDL_mixer
  Mix_CloseAudio ();

	return EXIT_SUCCESS;
}
