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
// Description:	Calls the SDLSprite function and initializes the 
//							health of the User
//
// Parameters:  xCoord - x location of the sprite
//							yCoord - y location of the sprite
//							health - health of the User
//
// Returned:		none
//*****************************************************************************
User::User(int xCoord, int yCoord, int health, int trash) :
  SDLSprite(FILE_NAME, xCoord, yCoord), mHealth(health),
  mTrashCollected(trash) {

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
	if (xCoord > SDLManager::instance().windowWidth() - getWidth()) {
		xCoord = SDLManager::instance().windowWidth() - getWidth();
	}

	if (yCoord > SDLManager::instance().windowHeight() - getHeight()) {
		yCoord = SDLManager::instance().windowHeight() - getHeight();
	}

  setX(xCoord);
  setY(yCoord);
}

//*****************************************************************************
// Method:      hit
//
// Description: Handles the user getting hit by a predator (Shark, Jellyfish,
//              or ShootingElement)
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void User::hit() {
  mHealth--;
}

//*****************************************************************************
// Method:      collectTrash
//
// Description: Handles the user collecting a piece of trash
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void User::collectTrash() {
  mTrashCollected++;
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

//*****************************************************************************
// Method:      collisionWithBoss
//
// Description: Checks if the User collides with the boss (TrashMonster)
//
// Parameters:  pcMovingObject - MovingObject to check collision with
//
// Returned:	  bool - true if collided, false otherwise
//*****************************************************************************
bool User::collisionWithBoss(TrashMonster &rcTrashMonster) {
	const int HALF_DIMENSION = 2;
	bool bCollided = false;

	// If the objects are touching/overlapping on any edges, then they have 
	// collided
	if (getX() <= rcTrashMonster.getX() + rcTrashMonster.getWidth() &&
		getX() + getWidth() >= rcTrashMonster.getX() &&
		getY() <= rcTrashMonster.getY() + rcTrashMonster.getHeight() &&
		getY() + getHeight() > rcTrashMonster.getY())
	{
		bCollided = true;
	}

	return bCollided;
}

//*****************************************************************************
// Method:      isAlive
//
// Description: Checks if the User is alive.
//
// Parameters:  none
//
// Returned:	  bool - true if alive, false otherwise
//*****************************************************************************
bool User::isAlive() const {
  const int DEATH = 0;
  bool bAlive = false;

  if (mHealth > DEATH) {
    bAlive = true;
  }

  return bAlive;
}

//*****************************************************************************
// Method:      getTrash
//
// Description: Gets the number of trash in the object.
//
// Parameters:  none
//
// Returned:	  An integer representing the amount of trash
//*****************************************************************************
int User::getTrash() const {
	return mTrashCollected;
}

//*****************************************************************************
// Method:      getTrash
//
// Description: Gets the health in the object.
//
// Parameters:  none
//
// Returned:	  An integer representing the health
//*****************************************************************************
int User::getHealth() const {
	return mHealth;
}

void User::setTrash(int trash) {
	mTrashCollected = trash;
}
void User::setHealth(int health) {
	mHealth = health;
}

const string User::FILE_NAME = "Images\\ScubaDiver.png";