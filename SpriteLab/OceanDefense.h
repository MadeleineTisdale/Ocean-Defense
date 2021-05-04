//**************************************************************************** 
// File name:	 OceanDefense.h
// Author:		 Kaylie Yamaguchi and Madeleine Tisdale
// Date:		   4/30/2019
// Class:		   CS 250-02
// Assignment: #7 Ocean Defense
// Purpose:		 Build a class to represent OceanDefense
//****************************************************************************
#ifndef OCEANDEFENSE_H
#define OCEANDEFENSE_H

#include "StageOne.h"
#include "StageTwo.h"
#include "StageThree.h"

class OceanDefense {
public:
	OceanDefense();
	~OceanDefense();

	void drawStartInstructions(SDLManager &rcManager) const;
	void drawGameOver(SDLManager &rcManager);
	void drawWin(SDLManager &rcManager);
	void drawUser();
	void updateUser(int xVal, int yVal);
	void updateObjects();
	void drawObjects();
	int calcGameScore();
	void drawGameScore(SDLManager &rcManager);
	void handleCollisions(SDLManager &rcManager);
	bool isGameStarted() const;
	void startGame();
	void beginNewStage();

	bool isStageOneDone() const;
	bool isStageTwoDone() const;
	bool isStageThreeDone() const;
	bool isGameDone();
	void playAgain();

private:
	StageOne *mpcStageOne;
	StageTwo *mpcStageTwo;
	StageThree *mpcStageThree;
	User mcUser;
	bool mbIsStarted;

};

#endif