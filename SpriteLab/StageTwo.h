//**************************************************************************** 
// File name:	 StageTwo.h
// Author:		 Kaylie Yamaguchi
// Date:		   5/3/2019
// Class:		   CS 250-02
// Assignment: #7 Ocean Defense
// Purpose:		 Build a class to represent Stage two of the game.
//****************************************************************************
#ifndef STAGETWO_H
#define STAGETWO_H

#include "User.h"
#include "Jellyfish.h"
#include "Trash.h"

class StageTwo {
public:
	StageTwo(const User &rcUser);
	StageTwo();
	~StageTwo();

	void createJellyfishAndTrash();
	void draw();
	void update();
	void updateUser(int xCoord, int yCoord);
	void handleCollision(SDLManager &rcManager);
	bool isDone();
	bool areJellyfishDone();
	bool isTrashDone();
	User getUser() const;

	void playJellySound(SDLManager &rcManager) const;
	void playTrashSound(SDLManager &rcManager) const;

private:
	static const int SIZE_WAVE;
	static const int MAX_JELLYFISH = 20;
	static const int MAX_TRASH = 20;

	Jellyfish * mapcJellyfish[MAX_JELLYFISH];
	Trash *mapcTrash[MAX_TRASH];
	User mcUser;
	bool mbJellyIsDone = false;
	int mNumJellyfish;
	int mNumTrash;
	int mTrashCollected;

};

#endif