//*****************************************************************************
// File name:	 Shark.cpp
// Author:		 Kaylie Yamaguchi and Madeleine Tisdale
// Date:		   4/30/2019
// Class:		   CS 250-02
// Assignment: #7 Ocean Defense
// Purpose:		 Implement a Shark
//*****************************************************************************

#include "Shark.h"

//*****************************************************************************
// Constructor:	Shark
//
// Description:	Calls the MovingCircle constructor and initializes the 
//							direction of the Shark
//
// Parameters:  xCoord      - x location of the sprite
//							yCoord      - y location of the sprite
//							rcDirection - direction that the Shark will move
//              speed       - the speed the Shark will move
//
// Returned:		none
//*****************************************************************************
Shark::Shark(int xCoord, int yCoord, const Direction2D &rcDirection, 
             int speed) : MovingObject(FILE_NAME, xCoord, yCoord, rcDirection,
                                       speed)
{

}

//*****************************************************************************
// Constructor:	Shark
//
// Description:	Initializes the Shark.
//
// Parameters:	rcMovingSprite - a MovingSprite by referenece
//              speed          - an integer representing the speed of the 
//                               object
//
// Returned:		none
//*****************************************************************************
Shark::Shark(SDLMovingSprite &rcMovingSprite, int speed)  
                                         : MovingObject(rcMovingSprite, speed)
{
  
}

//*****************************************************************************
// Method:      spawnRandom
//
// Description: Places a Shark in a random spot
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void Shark::spawnRandom() {
  const int HALF_DIMENSION = 2;
  const int MIN_WINDOW = 0;

  // Set the x value of mcMovingObject to a random value within the bounds 
  // of the screen
  mcMovingObject.setX(rand() % (SDLManager::instance().windowWidth() - 
    mcMovingObject.getWidth() / HALF_DIMENSION) + (MIN_WINDOW + 
    mcMovingObject.getWidth() / HALF_DIMENSION));

  // Set the y value of mcMovingObject to a random value within the bounds 
  // of the screen
  mcMovingObject.setY(rand() % (SDLManager::instance().windowHeight() -
    mcMovingObject.getHeight() / HALF_DIMENSION) + (MIN_WINDOW +
      mcMovingObject.getHeight() / HALF_DIMENSION));

  // Set the speed of mcMovingObject to a random value
  mSpeed = rand() % MAX_SPEED + MIN_SPEED;
}

const string Shark::FILE_NAME = "Images\\SharkMovingDown.png";

const int Shark::MAX_SPEED = 1;

const int Shark::MIN_SPEED = 3;