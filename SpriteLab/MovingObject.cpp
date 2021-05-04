//*****************************************************************************
// File name:	 MovingObject.cpp
// Author:		 Kaylie Yamaguchi and Madeleine Tisdale
// Date:		   4/30/2019
// Class:		   CS 250-02
// Assignment: #7 Ocean Defense
// Purpose:		 Implement a MovingObject
//*****************************************************************************

#include "MovingObject.h"

//*****************************************************************************
// Constructor:	MovingObject
//
// Description:	Initializes the MovingObject.
//
// Parameters:	spriteName  - name of graphic file
//              xCoord      - x location of the sprite
//							yCoord      - y location of the sprite
//							rcDirection - direction that the MovingObject will move
//              speed       - the speed the MovingObject will move at
//
// Returned:		none
//*****************************************************************************
MovingObject::MovingObject(string spriteName, int xCoord, int yCoord,
  const Direction2D &rcDirection, int speed) :
  SDLMovingSprite(spriteName, xCoord, yCoord, rcDirection), mSpeed(speed)
{

}

//*****************************************************************************
// Method:	    update
//
// Description:	updates the moving circle to the correct next position
//
// Parameters:	none
//
// Returned:		none
//*****************************************************************************
void MovingObject::update() {
  for (int i = 0; i < mSpeed; i++) {
    SDLMovingSprite::update();
  }
}

//*****************************************************************************
// Method:      spawn
//
// Description: Spawns a MovingObject in the place given in the parameters
//
// Parameters:  xCoord - x position where the Shark will spawn
//							yCoord - y position where the Shark will spawn
//
// Returned:	  none
//*****************************************************************************
void MovingObject::spawn(int xCoord, int yCoord) {
  setX(xCoord);
  setY(yCoord);
}

//*****************************************************************************
// Method:      isOnScreen
//
// Description: Checks to see if the MovingObject is on the screen
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
bool MovingObject::isOnScreen() {
  const int HALF_DIMENSION = 2;

  if ((getX() - (getWidth() / HALF_DIMENSION)) >=
    SDLManager::instance().windowWidth()) {
    mbOnScreen = false;
  }

  return mbOnScreen;
}