//*****************************************************************************
// File name:	 Trash.cpp
// Author:		 Kaylie Yamaguchi and Madeleine Tisdale
// Date:		   4/30/2019
// Class:		   CS 250-02
// Assignment: 07 Ocean Defense
// Purpose:		 Implement a Trash
//*****************************************************************************

#include "Trash.h"

//*****************************************************************************
// Constructor:	Trash
//
// Description:	Calls the MovingCircle constructor and initializes the 
//							direction of the Trash
//
// Parameters:	spriteName - name of graphic file
//              xCoord - x location of the sprite
//							yCoord - y location of the sprite
//							rcDirection - direction that the Trash will move
//
// Returned:		none
//*****************************************************************************
Trash::Trash(int xCoord, int yCoord, const Direction2D &rcDirection, int speed)
	: MovingObject(FILE_NAME, xCoord, yCoord, rcDirection, speed) {

}

//*****************************************************************************
// Method: spawnRandom
//
// Description:	Spawns the Trash.
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void Trash::spawnRandom() {
	const int MIN_WINDOW = 1;

	// Set the x value to a random value within the bounds of the screen
	setX(rand() % MIN_WINDOW - getWidth());

	// Set the y value of mcMovingObject to a random value within the bounds 
	// of the screen
	do {
		setY(rand() % (SDLManager::instance().windowHeight()) + MIN_WINDOW);
	} while (getY() >= (SDLManager::instance().windowHeight() - getHeight()));

	// Set the speed of mcMovingObject to a random value
	mSpeed = rand() % MAX_SPEED + MIN_SPEED;
}

const string Trash::FILE_NAME = "Images\\GarbageBag.png";

const int Trash::MAX_SPEED = 4;

const int Trash::MIN_SPEED = 3;