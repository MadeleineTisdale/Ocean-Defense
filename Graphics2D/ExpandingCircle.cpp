//**************************************************************************** 
// File name:	 ExpandingCircle.cpp
// Author:		 Madeleine Tisdale
// Date:		   4/12/2019
// Class:		   CS 250
// Assignment: #6 Boomshine
// Purpose:		 Implement an expanding circle
//****************************************************************************

#include "ExpandingCircle.h"

using namespace std;

//****************************************************************************
// Constructor:	ExpandingCircle
//
// Description:	Set mXCenter, mYCenter, and mcColor with the given parameters
//
// Parameters:	xCenter     - the x-value for the center of the circle
//						  yCenter			- the y-value for the center of the circle
//              cColor     - the color of the circle
//
// Returned:		none
//****************************************************************************
ExpandingCircle::ExpandingCircle(int xCenter, int yCenter, Color cColor) {
  mXCenter = xCenter;
  mYCenter = yCenter;
  mRadius = INITIAL_RADIUS;
  mcColor = cColor;
  mbIsDone = false;
}

//****************************************************************************
// Constructor:	ExpandingCircle
//
// Description:	Set mXCenter, mYCenter, mRadius, and mcColor with the given
//              parameter
//
// Parameters:	rcCircle - an object of Circle class by reference
//
// Returned:		none
//****************************************************************************
ExpandingCircle::ExpandingCircle(Circle &rcCircle) : Circle(rcCircle) {
  mRadius = INITIAL_RADIUS;
  mbIsDone = false;
}

//****************************************************************************
// Name:	      expand
//
// Description:	Increment the radius of the object
//
// Parameters:	none
//
// Returned:		none
//****************************************************************************
bool ExpandingCircle::expand() {

  if (mRadius < MAX_RADIUS) {
    mRadius++;
    mbIsDone = false;
  }
  else {
    mbIsDone = true;
  }

  return mbIsDone;
}

//****************************************************************************
// Name:	      draw
//
// Description:	Draw the expanding circle to the screen
//
// Parameters:	rcManager - the SDLManager to be draw to
//
// Returned:		none
//****************************************************************************
void ExpandingCircle::draw(SDLManager &rcManager) const {
  if (mbIsDone == false) {
    Circle::draw(rcManager);
  }
}

//****************************************************************************
// Name:	      getStatus
//
// Description:	Determine if the circle is done expanding
//
// Parameters:	none
//
// Returned:		none
//****************************************************************************
bool ExpandingCircle::getStatus() const {
  return mbIsDone;
}

// Static variable definitions
const int ExpandingCircle::MAX_RADIUS = 120;

const int ExpandingCircle::INITIAL_RADIUS = 15;