//**************************************************************************** 
// File name:	 User.h
// Author:		 Madeleine Tisdale
// Date:		   4/30/2019
// Class:		   CS 250
// Assignment: #7 Ocean Defense
// Purpose:		 Build a class to represent a user
//****************************************************************************
#ifndef USER_H
#define USER_H

#include "SDLManager.h"
#include "SDLSprite.h"
#include "Direction2D.h"
#include "MovingObject.h"

using namespace std;

class User {

public:
  User(int xCoord = 0, int yCoord = 0, int health = 0);
  User(SDLSprite &rcSprite, int health);

  void move(int xCoord, int yCoord);

  bool collision(MovingObject *pcMovingObject);

  static const string FILE_NAME;

private:
  SDLSprite mcUser;
  int mHealth;

};

#endif