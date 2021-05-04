//**************************************************************************** 
// File name:	 ExpandingCircle.h
// Author:		 Madeleine Tisdale
// Date:		   4/12/2019
// Class:		   CS 250
// Assignment: #6 Boomshine
// Purpose:		 Build a class to represent an expanding circle
//****************************************************************************
#ifndef EXPANDINGCIRCLE_H
#define EXPANDINGCIRCLE_H

#include "SDLManager.h"
#include "Circle.h"
#include "Direction2D.h"

using namespace std;

class ExpandingCircle : public Circle {

public:
  ExpandingCircle(int xCenter = 100, int yCenter = 100,
    Color cColor = Color::BLACK);
  ExpandingCircle(Circle &rcCircle);

  bool expand();

  virtual void draw(SDLManager &rcManager) const;

  bool getStatus() const;

private:
  static const int MAX_RADIUS;
  static const int INITIAL_RADIUS;

  bool mbIsDone;
};

#endif