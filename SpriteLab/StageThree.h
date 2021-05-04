//*****************************************************************************
// File name:	 StageThree.h
// Author:		 Kaylie Yamaguchi
// Date:		   5/3/2019
// Class:		   CS 250-02
// Assignment: #7 Ocean Defense
// Purpose:		 Build a class to represent Stage three of the game.
//*****************************************************************************
#ifndef STAGETHREE_H
#define STAGETHREE_H

#include "User.h"
#include "TrashMonster.h"
#include "Shark.h"
#include "ShootingElement.h"

class StageThree {
public:
	StageThree(User mcUser);
	~StageThree();

	void createPredators();
	void draw();
	void update();
	void updateUser(int xCoord, int yCoord);
	User getUser() const;

	void collisionWithShark(SDLManager &rcManager);
	void spearCollisionShark(SDLManager &rcManager);
	void spearCollisionBoss(SDLManager &rcManager);
	void collisionWithBoss(SDLManager &rcManager);
	void handleCollision(SDLManager &rcManager);

	bool areSharksDone();

	void playBiteSound(SDLManager &rcManager) const;
	void playBossSound(SDLManager &rcManager) const;
	void playOuchSound(SDLManager &rcManager) const;

	bool isSpearDone();
	bool isSpearOnScreen();

	void bossDefeated();
	bool isDone();

private:
	static const int SIZE_WAVE;
	static const int MAX_SHARKS = 600;
	User mcUser;
	TrashMonster mcBoss;
	Shark *mapcSharks[MAX_SHARKS];
	ShootingElement *mpcSpear;
	int mSize;
	double mRotation;
	bool mbIsDone = false;
};
#endif