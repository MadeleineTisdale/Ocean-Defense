//****************************************************************************
// File name:  Circle.h
// Author:     Computer Science, Pacific University
// Date:       4/4/19
// Class:      CS250
// Assignment: SDL Simple Circle
// Purpose:    Specify the Circle interface for displaying a fixed circle on
//             the screen.
//****************************************************************************
#ifndef CIRCLE_H
#define CIRCLE_H

#include "SDLManager.h"
#include "Color.h"
#include <iostream>

using namespace std;

class Circle
{
public:
  Circle(int xCenter = 10, int yCenter = 10, int radius = 10,
    const Color &rcColor = Color::getColor(Color::BLACK));
  Circle(Circle &rcCircle);
  virtual void draw(SDLManager &rcManager) const;
  bool read(istream &rcInStream);
  bool collision(Circle &rcCircle);

protected:
  int mXCenter, mYCenter, mRadius;
  Color mcColor;
};

#endif