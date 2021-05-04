//****************************************************************************
// File name:	 Circle.cpp
// Author:		 Madeleine Tisdale
// Date:		   4/5/2019
// Class:		   CS 250
// Assignment: SDL_MovingCircle
// Purpose:		 Implement a circle
//****************************************************************************

#include "Circle.h"
#include <iostream>

//****************************************************************************
// Constructor:	Circle
//
// Description:	Set mXCenter, mYCenter, mRadius, and mcColor with the given
//              parameters
//
// Parameters:	xCenter     - the x-value for the center of the circle
//						  yCenter			- the y-value for the center of the circle
//              radius      - the radius of the circle
//              rcColor     - the color of the circle
//
// Returned:		none
//****************************************************************************
Circle::Circle(int xCenter, int yCenter, int radius,
  const Color &rcColor) {
  mXCenter = xCenter;
  mYCenter = yCenter;
  mRadius = radius;
  mcColor = rcColor;
}

//****************************************************************************
// Constructor:	Circle
//
// Description:	Set mXCenter, mYCenter, mRadius, and mcColor with the given
//              parameter
//
// Parameters:	rcCircle - another object of Circle class by reference
//
// Returned:		none
//****************************************************************************
Circle::Circle(Circle &rcCircle) {
  mXCenter = rcCircle.mXCenter;
  mYCenter = rcCircle.mYCenter;
  mRadius = rcCircle.mRadius;
  mcColor = rcCircle.mcColor;
}

//****************************************************************************
// Name:	      draw
//
// Description:	Draw the circle to the screen
//
// Parameters:	rcManager - the SDLManager to be draw to
//
// Returned:		none
//****************************************************************************
void Circle::draw(SDLManager &rcManager) const {
  rcManager.drawFilledCircle(mXCenter, mYCenter, mRadius, mcColor);
}

//****************************************************************************
// Name:	      read
//
// Description:	Read in a circle from a stream
//
// Parameters:	rcInStream - the stream to be read from
//
// Returned:		A bool that is true if the circle has been read
//****************************************************************************
bool Circle::read(istream &rcInStream) {
  bool bIsRead = false;

  // If the x and y values of the center, the radius, and the color are read
  // from the stream passed in, then set the bool bIsRead to true
  if (rcInStream >> mXCenter >> mYCenter >> mRadius >> mcColor) {
    bIsRead = true;
  }

  return bIsRead;
}

//****************************************************************************
// Name:	      collision
//
// Description:	Determine if the calling circle and a passed in circle have
//              collided or intersected.
//
// Parameters:	rcCircle - a circle by reference
//
// Returned:		A bool that is true if the circles have collided or 
//              intersected and false if not
//****************************************************************************
bool Circle::collision(Circle &rcCircle) {
  bool bHaveCollided = false;
  int distance;

  // Calculate the distance between the center of the calling circle and the
  // circle passed in
  distance = static_cast<int> (sqrt(pow(mXCenter - rcCircle.mXCenter, 2) +
    pow(mYCenter - rcCircle.mYCenter, 2)));

  // If the distance is less than or equal to the sum of both radiuses, then
  // set bHaveCollided to true
  if (distance <= (mRadius + rcCircle.mRadius)) {
    bHaveCollided = true;
  }

  return bHaveCollided;
}