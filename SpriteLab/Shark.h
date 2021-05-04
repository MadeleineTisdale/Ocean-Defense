//**************************************************************************** 
// File name:	 Shark.h
// Author:		 Madeleine Tisdale
// Date:		   4/30/2019
// Class:		   CS 250
// Assignment: #7 Ocean Defense
// Purpose:		 Build a class to represent a shark
//****************************************************************************
#ifndef SHARK_H
#define SHARK_H

#include "SDLManager.h"
#include "SDLMovingSprite.h"
#include "Direction2D.h"
#include "MovingObject.h"
#include "ShootingElement.h"
#include <cMath>
#include <cTime>
#include <cstdlib>

using namespace std;

class Shark : public MovingObject {

public:
  Shark(int xCoord = 0, int yCoord = 0,
    const Direction2D &rcDirection = Direction2D::E, int speed = 1);

  virtual void spawnRandom();

  bool collision(const ShootingElement &rcShootingElement) const;

  static const string FILE_NAME;

private:
  static const int MAX_SPEED;
  static const int MIN_SPEED;

};

#endif