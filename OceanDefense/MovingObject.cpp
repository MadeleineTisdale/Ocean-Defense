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
												 	 const Direction2D &rcDirection, int speed) {
  SDLMovingSprite cTempMSprite(spriteName, xCoord, yCoord, rcDirection);
  
  mcMovingObject = cTempMSprite;
  mSpeed = speed;
}

//*****************************************************************************
// Constructor:	MovingObject
//
// Description:	Initializes the MovingObject
//
// Parameters:	rcMovingSprite - the MovingSprite sprite
//              speed          - the speed the MovingObject will move at
//
// Returned:		none
//*****************************************************************************
MovingObject::MovingObject(SDLMovingSprite &rcMovingSprite, int speed) {
  mcMovingObject = rcMovingSprite;
  mSpeed = speed;
}

//*****************************************************************************
// Method:      move
//
// Description: Moves the MovingObject
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void MovingObject::move() {
  // Update the SDLMovingSprite as many times as mSpeed specifies
  for (int i = 0; i < mSpeed; i++) {
    mcMovingObject.update();
  }
}

//*****************************************************************************
// Method:      draw
//
// Description: Draws the MovingObject (mcMovingObject)
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void MovingObject::draw() {
  mcMovingObject.draw();
}

//*****************************************************************************
// Method:      getX
//
// Description: Gets the x coordinate of the SDLMovingObject
//
// Parameters:  none
//
// Returned:	  An int representing the x coordinate of mcMovingObject
//*****************************************************************************
int MovingObject::getX() {
  return mcMovingObject.getX();
}

//*****************************************************************************
// Method:      getY
//
// Description: Gets the y coordinate of the SDLMovingObject
//
// Parameters:  none
//
// Returned:	  An int representing the y coordinate of mcMovingObject
//*****************************************************************************
int MovingObject::getY() {
  return mcMovingObject.getY();
}

//*****************************************************************************
// Method:      getLength
//
// Description: Gets the length of the SDLMovingObject
//
// Parameters:  none
//
// Returned:	  An int representing the length of mcMovingObject
//*****************************************************************************
int MovingObject::getLength() {
  return mcMovingObject.getHeight();
}

//*****************************************************************************
// Method:      getWidth
//
// Description: Gets the width of the SDLMovingObject
//
// Parameters:  none
//
// Returned:	  An int representing the width of mcMovingObject
//*****************************************************************************
int MovingObject::getWidth() {
  return mcMovingObject.getWidth();
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
  mcMovingObject.setX(xCoord);
  mcMovingObject.setY(yCoord);
}