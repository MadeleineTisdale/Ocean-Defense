//*****************************************************************************
// File name:	 TrashMonster.cpp
// Author:		 Kaylie Yamaguchi
// Date:		   4/30/2019
// Class:		   CS 250-02
// Assignment: 07 Ocean Defense
// Purpose:		 Implement a TrashMonster
//*****************************************************************************

#include "TrashMonster.h"

//*****************************************************************************
// Constructor:	TrashMonster
//
// Description:	Initialize health of the TrashMonster
//
// Parameters:	spriteName - name of graphic file
//              xCoord - x location of the sprite
//							yCoord - y location of the sprite
//							health - health of the trash monster
//
// Returned:		none
//*****************************************************************************
TrashMonster::TrashMonster(int xCoord, int yCoord, int health)
	: SDLSprite(FILE_NAME, xCoord, yCoord),
	mHealth(health) {

}

//*****************************************************************************
// Method: isAlive
//
// Description:	Checks if the TrashMonster is still alive.
//
// Parameters:  none
//
// Returned:	  bool - true if alive, false otherwise.
//*****************************************************************************
bool TrashMonster::isAlive() const {
	const int NO_HEALTH = 0;
	bool bIsAlive = true;

	if (mHealth <= NO_HEALTH) {
		bIsAlive = false;
	}

	return bIsAlive;
}

//*****************************************************************************
// Method:      collision
//
// Description: Checks if the a MovingObject collides with TrashMonster
//
// Parameters:  pcMovingObject - MovingObject to check collision with
//
// Returned:	  bool - true if collided, false otherwise
//*****************************************************************************
bool TrashMonster::collision(const ShootingElement *pcShootingElement) const {
	bool bCollided = false;

	// If the objects are touching/overlapping on any edges, then they have 
	// collided
	if (getX() <= pcShootingElement->getX() + pcShootingElement->getWidth() &&
		getX() + getWidth() >= pcShootingElement->getX() &&
		getY() <= pcShootingElement->getY() + pcShootingElement->getHeight() &&
		getY() + getHeight() > pcShootingElement->getY())
	{
		bCollided = true;
	}

	return bCollided;
}

//*****************************************************************************
// Method:      hit
//
// Description: Removes one life from the boss's health.
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void TrashMonster::hit() {
	mHealth--;

	return;
}

const string TrashMonster::FILE_NAME = "Images\\TrashMonster.png";