//*****************************************************************************
// File name:	 Jellyfish.cpp
// Author:		 Kaylie Yamaguchi
// Date:		   4/30/2019
// Class:		   CS 250-02
// Assignment: 07 Ocean Defense
// Purpose:		 Implement a Jellyfish.
//*****************************************************************************

#include "Jellyfish.h"

//*****************************************************************************
// Constructor:	Jellyfish
//
// Description:	Calls the MovingCircle constructor and initializes the 
//							direction of the Jellyfish
//
// Parameters:  xCoord - x location of the sprite
//							yCoord - y location of the sprite
//							rcDirection - direction that the Jellyfish will move
//              speed  - the speed of the MovingObject
//
// Returned:		none
//*****************************************************************************
Jellyfish::Jellyfish(int xCoord, int yCoord,
	const Direction2D &rcDirection, int speed) :
	MovingObject(FILE_NAME, xCoord, yCoord, rcDirection, speed)
{

}

//*****************************************************************************
// Method:      spawnRandom
//
// Description:	Places the Jellyfish in a random spot
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void Jellyfish::spawnRandom()
{
	const int HALF_DIMENSION = 2;

	const int MIN_WINDOW = 1;

	// Set the x value to a random value within the bounds of the screen
	setX(rand() % MIN_WINDOW - getWidth());

	// Set the y value of mcMovingObject to a random value within the bounds 
	// of the screen
	do {
		setY(rand() % (SDLManager::instance().windowHeight() - getHeight()) +
			(MIN_WINDOW + getHeight()));
	} while (getY() > (SDLManager::instance().windowHeight() - getHeight()));

	Direction2D::CompassDirection randDirection =
		static_cast <Direction2D::CompassDirection> (rand() % 3 + 1);
	mSpeed = rand() % MAX_SPEED + MIN_SPEED;
	mcDirection = randDirection;
}

const string Jellyfish::FILE_NAME = "Images\\Jellicent.png";
const int Jellyfish::MAX_SPEED = 4;
const int Jellyfish::MIN_SPEED = 3;