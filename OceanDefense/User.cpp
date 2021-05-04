//*****************************************************************************
// File name:	 User.cpp
// Author:		 Kaylie Yamaguchi and Madeleine Tisdale
// Date:		   4/30/2019
// Class:		   CS 250-02
// Assignment: #7 Ocean Defense
// Purpose:		 Implement a User
//*****************************************************************************

#include "User.h"

//*****************************************************************************
// Constructor:	User
//
// Description:	Calls the MovingCircle constructor and initializes the 
//							health of the User
//
// Parameters:  xCoord - x location of the sprite
//							yCoord - y location of the sprite
//							health - health of the User
//
// Returned:		none
//*****************************************************************************
User::User(int xCoord, int yCoord, int health) {
  SDLSprite cTempSprite(FILE_NAME, xCoord, yCoord);

  mcUser = cTempSprite;
  mHealth = health;
}

//*****************************************************************************
// Constructor:	User
//
// Description:	Initializes the User
//
// Parameters:	rcSprite - a sprite by reference
//							health   - health of the User
//
// Returned:		none
//*****************************************************************************
User::User(SDLSprite &rcSprite, int health) {
  mcUser = rcSprite;
  mHealth = health;
}

//*****************************************************************************
// Method:      move
//
// Description: Handles the movement of the user.
//
// Parameters:  xCoord - x position the user will be moved to
//							yCoord - y position the user will be moved to
//
// Returned:	  none
//*****************************************************************************
void User::move(int xCoord, int yCoord) {
  mcUser.setX(xCoord);
  mcUser.setY(yCoord);
}

//*****************************************************************************
// Method:      collision
//
// Description: Checks if the User collides with a MovingObject (predator)
//
// Parameters:  pcMovingObject - MovingObject to check collision with
//
// Returned:	  bool - true if collided, false otherwise
//*****************************************************************************
bool User::collision(MovingObject *pcMovingObject) {
  const int HALF_DIMENSION = 2;
  bool bCollided = false;
  int distance;

  // Calculate the distance between the center of the calling circle and the
  // circle passed in
  distance = static_cast<int> (sqrt(pow(mcUser.getX() - pcMovingObject->getX(),
                               2) + pow(mcUser.getY() - 
                               pcMovingObject->getY(), 2)));

  // If the distance is less than or equal to the sum of both radiuses, then
  // set bHaveCollided to true
  if (distance <= (mcUser.getHeight() / HALF_DIMENSION + 
    pcMovingObject->getLength() / HALF_DIMENSION) || distance <= 
    (mcUser.getWidth() / HALF_DIMENSION + pcMovingObject->getWidth() / 
      HALF_DIMENSION)) {
    bCollided = true;
  }

  return bCollided;
}

const string User::FILE_NAME = "";