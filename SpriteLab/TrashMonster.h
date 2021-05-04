//**************************************************************************** 
// File name:	 TrashMonster.h
// Author:		 Madeleine Tisdale
// Date:		   4/30/2019
// Class:		   CS 250
// Assignment: #7 Ocean Defense
// Purpose:		 Build a class to represent a trash monster
//****************************************************************************
#ifndef TRASHMONSTER_H
#define TRASHMONSTER_H

#include "SDLManager.h"
#include "SDLSprite.h"
#include "Direction2D.h"
#include "MovingObject.h"
#include "ShootingElement.h"

using namespace std;

class TrashMonster : public SDLSprite {

public:
	TrashMonster(int xCoord = 0, int yCoord = 160, int health = 10);

	bool isAlive() const;

	bool collision(const ShootingElement *rcShootingElement) const;

	void hit();

	static const string FILE_NAME;

private:
	int mHealth;

};

#endif