//**************************************************************************** 
// File name:	 MovingCircle.h
// Author:		 Computer Science, Pacific University
// Date:		   4/3/2019
// Class:		   CS 250
// Assignment: MovingCircles
// Purpose:		 Build a class to represent a moving circle
//****************************************************************************
#ifndef MOVINGCIRCLE_H
#define MOVINGCIRCLE_H

#include "SDLManager.h"
#include "Circle.h"
#include "Direction2D.h"

using namespace std;

class MovingCircle : public Circle {

public:
  MovingCircle(int xCenter = 100, int yCenter = 100, int radius = 10,
    const Color &rcColor = Color::BLACK,
    const Direction2D &rcDirection = Direction2D::N,
    int speed = 1);

  bool move();

  void setDirection(const Direction2D &rcDirection);
  Direction2D getDirection() const;

  void setSpeed(int speed);
  int getSpeed() const;

  void setMovementBoundingBox(int xMin, int yMin,
    int xMax, int yMax);

  bool read(istream &rcInStream);

private:
  // bounding box of movement
  int mXMin = 0;
  int mYMin = 0;
  int mXMax = 640;
  int mYMax = 640;

  Direction2D mcDirection;
  int mSpeed;
};

#endif