//*****************************************************************************
// File name:	 ShootingElement.cpp
// Author:		 Kaylie Yamaguchi
// Date:		   4/30/2019
// Class:		   CS 250-02
// Assignment: 07 Ocean Defense
// Purpose:		 Implement a ShootingElement
//*****************************************************************************

#include "ShootingElement.h"

//*****************************************************************************
// Constructor:	ShootingElement
//
// Description:	Calls the MovingCircle constructor and initializes the 
//							direction of the ShootingElement
//
// Parameters:	spriteName - name of graphic file
//              xCoord - x location of the sprite
//							yCoord - y location of the sprite
//							rcDirection - direction that the ShootingElement will move
//
// Returned:		none
//*****************************************************************************
ShootingElement::ShootingElement(int xCoord, int yCoord,
  const Direction2D &rcDirection, int speed)
  : MovingObject(FILE_NAME, xCoord, yCoord,
    rcDirection, speed) {

}

//*****************************************************************************
// Constructor:	ShootingElement
//
// Description:	Initializes the ShootingElement
//
// Parameters:	rcMovingSprite - the ShootingElement sprite.
//							speed - the speed of the sprite
//
// Returned:		none
//*****************************************************************************
ShootingElement::ShootingElement(SDLMovingSprite &rcMovingSprite, int speed)
  : MovingObject(rcMovingSprite, speed) {

}

//*****************************************************************************
// Method: spawnRandom
//
// Description:	Spawns the ShootingElement.
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void ShootingElement::spawnRandom() {
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

const string ShootingElement::FILE_NAME = "Images\\Spear.png";
const int ShootingElement::MAX_SPEED = 1;
const int ShootingElement::MIN_SPEED = 3;