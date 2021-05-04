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
  int speed) : MovingObject(FILE_NAME, xCoord, yCoord,
    rcDirection, speed)
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
//*****************************************************************************
// Method:      collision
//
// Description: Checks to see if the calling object has collided with a 
//              ShootingElement
//
// Parameters:  none
//
// Returned:	  A bool that is true if the objects collided and false otherwise
//*****************************************************************************
bool Shark::collision(const ShootingElement &rcShootingElement) const {
  bool bCollided = false;

  // If the objects are touching/overlapping on any edges, then they have 
  // collided
  if (getX() <= rcShootingElement.getX() + rcShootingElement.getWidth() &&
    getX() + getWidth() >= rcShootingElement.getX() &&
    getY() <= rcShootingElement.getY() + rcShootingElement.getHeight() &&
    getY() + getHeight() > rcShootingElement.getY())
  {
    bCollided = true;
  }

  return bCollided;
}

const string Shark::FILE_NAME = "Images\\MegaSharpedo.png";

const int Shark::MAX_SPEED = 7;

const int Shark::MIN_SPEED = 5;