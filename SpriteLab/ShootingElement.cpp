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
// Method: spawnRandom
//
// Description:	Spawns the ShootingElement.
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void ShootingElement::spawnRandom() {

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
bool ShootingElement::collision(MovingObject *pcMovingObject) {
	const int HALF_DIMENSION = 2;
	bool bCollided = false;

	// If the objects are touching/overlapping on any edges, then they have 
	// collided
	if (getX() <= pcMovingObject->getX() + pcMovingObject->getWidth() &&
		getX() + getWidth() >= pcMovingObject->getX() &&
		getY() <= pcMovingObject->getY() + pcMovingObject->getHeight() &&
		getY() + getHeight() > pcMovingObject->getY())
	{
		bCollided = true;
	}

	return bCollided;
}
const string ShootingElement::FILE_NAME = "Images\\Spear.png";


const int ShootingElement::MAX_SPEED = 1;
const int ShootingElement::MIN_SPEED = 1;