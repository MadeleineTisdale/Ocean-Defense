//**************************************************************************** 
// File name:	 StageOne.h
// Author:		 Kaylie Yamaguchi and Madeleine Tisdale
// Date:		   5/3/2019
// Class:		   CS 250-02
// Assignment: #7 Ocean Defense
// Purpose:		 Build a class to represent Stage one of the game.
//****************************************************************************
#ifndef STAGEONE_H
#define STAGEONE_H

#include "User.h"
#include "Shark.h"

class StageOne {
public:
  StageOne(User rUser);
  StageOne();
  ~StageOne();

  void addSharks();
  void draw() const;
  void update();
  void updateUser(int xCoord, int yCoord);

  void handleCollision(SDLManager &rcManager);
  bool isDone();
  bool areSharksDone() const;

  void playOuchSound(SDLManager &rcManager) const;

  User getUser() const;

private:
  static const int SIZE_WAVE;
  static const int MAX_SHARKS = 30;
  User mcUser;
  Shark *mpacSharks[MAX_SHARKS];
  bool mbIsDone = false;
  int mSizeSharks;
};

#endif