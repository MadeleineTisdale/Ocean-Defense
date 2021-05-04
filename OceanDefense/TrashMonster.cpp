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
TrashMonster::TrashMonster(string spriteName, int xCoord, int yCoord,
													 int health) {

	SDLSprite::SDLSprite(spriteName, xCoord, yCoord);
	mHealth = 0;
}


//*****************************************************************************
// Constructor: TrashMonster
//
// Description:	Expands the circle until it reaches the max radius. 
//
// Parameters:  rcSprite - TrashMonster sprite
//							health - health of the TrashMonster
//
// Returned:	  none
//*****************************************************************************
TrashMonster::TrashMonster(SDLSprite &rcSprite, int health) {

	mBoss = rcSprite;
	mHealth = health;
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
// Method: handleDefeat
//
// Description:	rcManager - object of class SDLManager
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void TrashMonster::handleDefeat(SDLManager &rcManager) {
	const double FULL_ROTATION = 360.0;
	double rotate = 1.0;

	while (rotate < FULL_ROTATION) {
		if (!isAlive()) {
			rotate += 1.0;
			mBoss.setRotation(rotate);
		}
	}

	return;
}