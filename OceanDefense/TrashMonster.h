//**************************************************************************** 
// File name:	 TrashMonster.h
// Author:		 Madeleine Tisdale
// Date:		   4/30/2019
// Class:		   CS 250
// Assignment: #7 Ocean Defense
// Purpose:		 Build a class to represent a trash monster
//****************************************************************************
#ifndef TRASHMONSTER_H
#define TRASHMONSTER_H

#include "SDLManager.h"
#include "SDLSprite.h"
#include "Direction2D.h"

using namespace std;

class TrashMonster {

public:
  TrashMonster(string spriteName = "", int xCoord = 0, int yCoord = 0,
					     int health = 0);
  TrashMonster(SDLSprite &rcSprite, int health);

  bool isAlive() const;

  void handleDefeat(SDLManager &rcManager);

  static const string FILE_NAME;

private:
  SDLSprite mBoss;
  int mHealth;

};

#endif