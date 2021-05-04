//**************************************************************************** 
// File name:	 ShootingElement.h
// Author:		 Madeleine Tisdale
// Date:		   4/30/2019
// Class:		   CS 250
// Assignment: #7 Ocean Defense
// Purpose:		 Build a class to represent a shooting element
//****************************************************************************
#ifndef SHOOTINGELEMENT_H
#define SHOOTINGELEMENT_H

#include "SDLManager.h"
#include "SDLMovingSprite.h"
#include "Direction2D.h"
#include "MovingObject.h"

using namespace std;

class ShootingElement : public MovingObject {

public:
	ShootingElement(int xCoord = 0, int yCoord = 0,
		const Direction2D &rcDirection = Direction2D::W,
		int speed = 10);

	virtual void spawnRandom();

	bool collision(MovingObject *pcMovingObject);

	static const string FILE_NAME;

private:
	static const int MAX_SPEED;
	static const int MIN_SPEED;

};

#endif