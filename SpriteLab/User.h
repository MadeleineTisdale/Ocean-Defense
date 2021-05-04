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
#include "TrashMonster.h"

using namespace std;

class User : public SDLSprite {

public:
  User(int xCoord = 0, int yCoord = 0, int health = 3, int trash = 0);
	
  void move(int xCoord, int yCoord);
  void hit();
  void collectTrash();

  bool collision(MovingObject *pcMovingObject);
	bool collisionWithBoss(TrashMonster &rcTrashMonster);
  bool isAlive() const;
	int getTrash() const;
	int getHealth() const;
	void setTrash(int trash);
	void setHealth(int health);

  static const string FILE_NAME;

private:
  int mHealth;
  int mTrashCollected;

};

#endif