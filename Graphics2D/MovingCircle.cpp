//****************************************************************************
// File name:	 MovingCircle.cpp
// Author:		 Madeleine Tisdale
// Date:		   4/5/2019
// Class:		   CS 250
// Assignment: SDL_MovingCircle
// Purpose:		 Implement a moving circle
//****************************************************************************

#include "MovingCircle.h"
#include <iostream>

//****************************************************************************
// Constructor:	MovingCircle
//
// Description:	Call the Circle constructor and set mcDirection and mSpeed 
//              with the given parameters.
//
// Parameters:	xCenter     - the x-value for the center of the circle
//						  yCenter			- the y-value for the center of the circle
//              radius      - the radius of the circle
//              rcColor     - the color of the circle
//              rcDirection - the direction the circle will move
//              speed       - the speed the circle will move
//
// Returned:		none
//****************************************************************************
MovingCircle::MovingCircle(int xCenter, int yCenter, int radius,
  const Color &rcColor,
  const Direction2D &rcDirection, int speed) :
  Circle(xCenter, yCenter, radius, rcColor),
  mcDirection(rcDirection), mSpeed(speed)
{
}

//****************************************************************************
// Name:	      move
//
// Description:	Move the circle
//
// Parameters:	none
//
// Returned:		A bool that is true if the circle has been moved
//****************************************************************************
bool MovingCircle::move() {
  bool bIsMoved = false;

  // Continue changing the position of the circle based on it's position 
  // relative to the bounding box until the circle is moved and not beyond
  // the bounding box
  while (mXCenter + mRadius > mXMax || mXCenter - mRadius < mXMin ||
    mYCenter + mRadius > mYMax || mYCenter - mRadius < mYMin ||
    bIsMoved == false) {

    // If the edge of the circle is set to go beyond the bounding box on the 
    // right or if the circle is already beyond the right, then reflect the 
    // direction (have the circle "bounce")
    if ((mXCenter + (mcDirection.getXMove() * mSpeed) + mRadius >
      mXMax && bIsMoved == false) || mXCenter + mRadius > mXMax) {
      setDirection(mcDirection.reflectOnRightSide());
      mXCenter += mcDirection.getXMove() * mSpeed;
      mYCenter += mcDirection.getYMove() * mSpeed;
      bIsMoved = true;
    }

    // If the edge of the circle is set to go beyond the bounding box on the 
    // left or if the circle is already beyond the left, then reflect the 
    // direction (have the circle "bounce")
    if ((mXCenter + (mcDirection.getXMove() * mSpeed) - mRadius <
      mXMin && bIsMoved == false) || mXCenter - mRadius < mXMin) {
      setDirection(mcDirection.reflectOnLeftSide());
      mXCenter += mcDirection.getXMove() * mSpeed;
      mYCenter += mcDirection.getYMove() * mSpeed;
      bIsMoved = true;
    }

    // If the edge of the circle is set to go beyond the bounding box on the 
    // bottom or if the circle is already beyond the bottom, then reflect the 
    // direction (have the circle "bounce")
    if ((mYCenter + (mcDirection.getYMove() * mSpeed) + mRadius >
      mYMax && bIsMoved == false) || mYCenter + mRadius > mYMax) {
      setDirection(mcDirection.reflectOnBottom());
      mXCenter += mcDirection.getXMove() * mSpeed;
      mYCenter += mcDirection.getYMove() * mSpeed;
      bIsMoved = true;
    }

    // If the edge of the circle is set to go beyond the bounding box on the 
    // top or if the circle is already beyond the top, then reflect the 
    // direction (have the circle "bounce")
    if ((mYCenter + (mcDirection.getYMove() * mSpeed) - mRadius <
      mYMin && bIsMoved == false) || mYCenter - mRadius < mYMin) {
      setDirection(mcDirection.reflectOnTop());
      mXCenter += mcDirection.getXMove() * mSpeed;
      mYCenter += mcDirection.getYMove() * mSpeed;
      bIsMoved = true;
    }

    // Otherwise, just set the new center to be moving in the original 
    // direction
    if (bIsMoved == false) {
      mXCenter += mcDirection.getXMove() * mSpeed;
      mYCenter += mcDirection.getYMove() * mSpeed;
      bIsMoved = true;
    }
  }

  return bIsMoved;
}

//****************************************************************************
// Name:	      setDirection
//
// Description:	Set the direction of the circle
//
// Parameters:	rcDirection - a constant direction by reference
//
// Returned:		none
//****************************************************************************
void MovingCircle::setDirection(const Direction2D &rcDirection) {
  mcDirection = rcDirection;
}

//****************************************************************************
// Name:	      getDirection
//
// Description:	Get the direction of the circle
//
// Parameters:	none
//
// Returned:		The direction of the circle
//****************************************************************************
Direction2D MovingCircle::getDirection() const {
  return mcDirection;
}

//****************************************************************************
// Name:	      setSpeed
//
// Description:	Set the speed of the circle to the given parameter
//
// Parameters:	speed - an integer
//
// Returned:		none
//****************************************************************************
void MovingCircle::setSpeed(int speed) {
  mSpeed = speed;
}

//****************************************************************************
// Name:	      getSpeed
//
// Description:	Get the speed of the circle
//
// Parameters:	none
//
// Returned:		An integer representing the speed of the moving circle
//****************************************************************************
int MovingCircle::getSpeed() const {
  return mSpeed;
}

//****************************************************************************
// Name:	      setMovementBoundingBox
//
// Description:	Set the dimensions of the bounding box
//
// Parameters:	xMin - an integer representing the lowest x-value
//              yMin - an integer representing the lowest y-value
//              xMax - an integer representing the greatest x-value
//              yMax - an integer representing the greatest y-value
//
// Returned:		none
//****************************************************************************
void MovingCircle::setMovementBoundingBox(int xMin, int yMin, int xMax,
  int yMax) {
  mXMin = xMin;
  mYMin = yMin;
  mXMax = xMax;
  mYMax = yMax;
}

//****************************************************************************
// Name:	      read
//
// Description:	Read in a moving circle from a stream
//
// Parameters:	rcInStream - the stream to be read from
//
// Returned:		A bool that is true if the moving circle has been read
//****************************************************************************
bool MovingCircle::read(istream &rcInStream) {
  bool bIsRead = false;

  if (Circle::read(rcInStream) && rcInStream >> mcDirection >> mSpeed) {
    bIsRead = true;
  }

  return bIsRead;
}