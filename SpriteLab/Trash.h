//**************************************************************************** 
// File name:	 Trash.h
// Author:		 Madeleine Tisdale
// Date:		   4/30/2019
// Class:		   CS 250
// Assignment: #7 Ocean Defense
// Purpose:		 Build a class to represent a piece of trash
//****************************************************************************
#ifndef TRASH_H
#define TRASH_H

#include "SDLManager.h"
#include "SDLMovingSprite.h"
#include "Direction2D.h"
#include "MovingObject.h"

using namespace std;

class Trash : public MovingObject {

public:
	Trash(int xCoord = 0, int yCoord = 0,
		const Direction2D &rcDirection = Direction2D::E, int speed = 1);

	virtual void spawnRandom();

	static const string FILE_NAME;

private:
	static const int MAX_SPEED;
	static const int MIN_SPEED;

};

#endif