//**************************************************************************** 
// File name:	 MovingObject.h
// Author:		 Madeleine Tisdale
// Date:		   4/30/2019
// Class:		   CS 250
// Assignment: #7 Ocean Defense
// Purpose:		 Build a class to represent a moving object (or animal)
//****************************************************************************
#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "SDLManager.h"
#include "SDLMovingSprite.h"
#include "Direction2D.h"
#include <cMath>
#include <cTime>
#include <cstdlib>

using namespace std;

class MovingObject : public SDLMovingSprite {

public:
  MovingObject(string spriteName = "", int xCoord = 0, int yCoord = 0,
    const Direction2D &rcDirection = Direction2D::E, int speed = 1);

  virtual void update();

  void spawn(int, int);

  virtual void spawnRandom() = 0;

  bool isOnScreen();

protected:
  int mSpeed;
  bool mbOnScreen;

};

#endif