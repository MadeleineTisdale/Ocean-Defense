//*****************************************************************************
// File name:	 StageThree.h
// Author:		 Kaylie Yamaguchi
// Date:		   5/3/2019
// Class:		   CS 250-02
// Assignment: #7 Ocean Defense
// Purpose:		 Build a class to represent Stage three of the game.
//*****************************************************************************

#include "StageThree.h"

const double FULL_ROTATION = 360.0;

//*****************************************************************************
// Constructor:	StageThree
//
// Description:	Initializes mcUser to the given parameter and initializes the 
//							array of pointers to nullptr.
//
// Parameters:  cUser - the user object being used in the game.
//
// Returned:		none
//*****************************************************************************
StageThree::StageThree(User cUser) {
	mcUser = cUser;
	for (int i = 0; i < MAX_SHARKS; i++) {
		mapcSharks[i] = nullptr;
	}

	mpcSpear = nullptr;
	mRotation = 0.0;
}

//*****************************************************************************
// Destructor:	StageThree
//
// Description:	Deletes any allocated memory in StageThree.
//
// Parameters:	none
//
// Returned:		none
//*****************************************************************************
StageThree::~StageThree() {
	for (int i = 0; i < MAX_SHARKS; i++) {
		if (mapcSharks[i] != nullptr) {
			delete mapcSharks[i];
			mapcSharks[i] = nullptr;
		}
	}
}

//*****************************************************************************
// Method: createPredators
//
// Description:	Creates the predators in stage three.
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void StageThree::createPredators() {
	const int MIN_Y_SPAWN = 1;
	int size = mSize;

	if ((areSharksDone() || mSize == 0) && mSize < MAX_SHARKS && mcBoss.isAlive()) {
		for (int i = size; i < size + SIZE_WAVE; i++) {
			mapcSharks[i] = new Shark();
			mapcSharks[i]->spawnRandom();
			mSize++;
		}
	}

	if (isSpearDone() && mcBoss.isAlive()) {
		mpcSpear = new ShootingElement();
		if (mcUser.getY() < 1) {
			mpcSpear->spawn(mcUser.getX(), MIN_Y_SPAWN);
		}
		else {
			mpcSpear->spawn(mcUser.getX(), mcUser.getY());
		}
	}

}

//*****************************************************************************
// Method: draw
//
// Description:	Draws the active sharks.
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void StageThree::draw() {
	for (int i = 0; i < mSize; i++) {
		if (mapcSharks[i] != nullptr && mapcSharks[i]->isOnScreen()) {
			mapcSharks[i]->draw();
		}
	}

	if (!(mcBoss.isAlive())) {
		bossDefeated();
	}

	if (mcBoss.isAlive()) {
		mcBoss.draw();
	}

	if (mpcSpear != nullptr && isSpearOnScreen()) {
		mpcSpear->draw();
	}

	mcUser.draw();

	return;
}

//*****************************************************************************
// Method: update
//
// Description:	Move the sharks.
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void StageThree::update() {
	for (int i = 0; i < mSize; i++) {
		if (mapcSharks[i] != nullptr && mapcSharks[i]->isOnScreen()) {
			mapcSharks[i]->update();
		}
	}

	if (mpcSpear != nullptr && isSpearOnScreen()) {
		mpcSpear->update();
	}
}

//*****************************************************************************
// Method: updateUser
//
// Description:	Updates the user's position.
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void StageThree::updateUser(int xCoord, int yCoord) {
	mcUser.move(xCoord, yCoord);
}

//*****************************************************************************
// Method:	    getUser
//
// Description:	Gets the member User variable
//
// Parameters:  none
//
// Returned:		A User object (mcUser)
//*****************************************************************************
User StageThree::getUser() const {
	return mcUser;
}

//*****************************************************************************
// Method: handleCollision
//
// Description: Handles all collision in stage three.
//
// Parameters:  rcManager - object of class SDLManager
//
// Returned:	  none
//*****************************************************************************
void StageThree::handleCollision(SDLManager &rcManager) {
	collisionWithBoss(rcManager);

	collisionWithShark(rcManager);

	spearCollisionBoss(rcManager);

	spearCollisionShark(rcManager);

	return;
}

//*****************************************************************************
// Method: collisionWithShark
//
// Description:	Checks if the User collides with a shark.
//
// Parameters:  none
//
// Returned:	  bool - true if collided, false otherwise.
//*****************************************************************************
void StageThree::collisionWithShark(SDLManager &rcManager) {
	for (int i = mSize - SIZE_WAVE; i < mSize; i++) {
		if (mapcSharks[i] != nullptr && mcUser.collision(mapcSharks[i])) {
			playOuchSound(rcManager);
			mcUser.hit();
			delete mapcSharks[i];
			mapcSharks[i] = nullptr;
		}
	}

	return;
}

//*****************************************************************************
// Method: collisionWithBoss
//
// Description:	Checks if the User collides with the boss.
//
// Parameters:  none
//
// Returned:	  bool - true if collided, false otherwise.
//*****************************************************************************
void StageThree::collisionWithBoss(SDLManager &rcManager) {
	if (mcUser.collisionWithBoss(mcBoss)) {
		delete mpcSpear;
		mpcSpear = nullptr;
		playBiteSound(rcManager);
		mcUser.hit();
	}

	return;
}

//*****************************************************************************
// Method: spearCollisionShark
//
// Description:	Checks if a spear collides with a shark.
//
// Parameters:  none
//
// Returned:	  bool - true if collided, false otherwise.
//*****************************************************************************
void StageThree::spearCollisionShark(SDLManager &rcManager) {
	for (int i = mSize - SIZE_WAVE; i < mSize; i++) {
		if (mapcSharks[i] != nullptr && mpcSpear != nullptr
			&& mpcSpear->collision(mapcSharks[i])) {
			playBiteSound(rcManager);
			delete mpcSpear;
			mpcSpear = nullptr;
		}
	}

	return;
}

//*****************************************************************************
// Method: spearCollisionBoss
//
// Description:	Checks if a spear collides with a shark.
//
// Parameters:  none
//
// Returned:	  bool - true if collided, false otherwise.
//*****************************************************************************
void StageThree::spearCollisionBoss(SDLManager &rcManager) {
	if (mpcSpear != nullptr && mcBoss.collision(mpcSpear)) {
		delete mpcSpear;
		mpcSpear = nullptr;
		playBossSound(rcManager);
		mcBoss.hit();
	}


	return;
}

//*****************************************************************************
// Method: areSharksDone
//
// Description:	Determines if all Sharks in mpacSharks are done (off screen)
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
bool StageThree::areSharksDone() {
	bool bIsOnScreen = true;

	for (int i = 0; i < mSize; i++) {
		if (mapcSharks[i] != nullptr && mapcSharks[i]->isOnScreen()) {
			bIsOnScreen = false;
		}
	}

	return bIsOnScreen;
}

//*****************************************************************************
// Method:	    playBiteSound
//
// Description: Plays a bite sound.
//
// Parameters:  rcManager - object of class SDLManager
//
// Returned:	  none
//*****************************************************************************
void StageThree::playBiteSound(SDLManager &rcManager) const {
	const string SOUND = "BiteSound.wav";
	bool bIsRepeated = false;

	rcManager.playSound(SOUND, bIsRepeated);

	return;
}

//*****************************************************************************
// Method:	    playBossSound
//
// Description: Plays a bite sound.
//
// Parameters:  rcManager - object of class SDLManager
//
// Returned:	  none
//*****************************************************************************
void StageThree::playBossSound(SDLManager &rcManager) const {
	const string SOUND = "Garbodor.wav";
	bool bIsRepeated = false;

	rcManager.playSound(SOUND, bIsRepeated);

	return;
}

//*****************************************************************************
// Method:	    playOuchSound
//
// Description: Plays an ouch sound.
//
// Parameters:  rcManager - object of class SDLManager
//
// Returned:	  none
//*****************************************************************************
void StageThree::playOuchSound(SDLManager &rcManager) const {
	const string SOUND = "OuchSound.wav";
	bool bIsRepeated = false;

	rcManager.playSound(SOUND, bIsRepeated);

	return;
}

//*****************************************************************************
// Method:	    isSpearDone
//
// Description: Determines if the spear is off the screen.
//
// Parameters:  none
//
// Returned:	  bool - true if off screen, false otherwise.
//*****************************************************************************
bool StageThree::isSpearDone() {
	bool bIsSpearDone = true;

	if (mpcSpear != nullptr && (isSpearOnScreen() == false)) {
		delete mpcSpear;
		mpcSpear = nullptr;
	}

	if (mpcSpear != nullptr && isSpearOnScreen()) {
		bIsSpearDone = false;
	}

	return bIsSpearDone;
}

//*****************************************************************************
// Method:      isSpearOnSceen
//
// Description: Checks to see if the MovingObject is on the screen
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
bool StageThree::isSpearOnScreen() {
	const int MIN_WINDOW = 1;
	bool bIsOnScreen = true;

	if ((mpcSpear->getX() + mpcSpear->getWidth()) <= MIN_WINDOW) {
		bIsOnScreen = false;
	}

	return bIsOnScreen;
}

//*****************************************************************************
// Method:      bossDefeated
//
// Description: Handles the boss's behavior after death.
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void StageThree::bossDefeated() {
	if (mcBoss.isAlive() == false) {
		if (mRotation < FULL_ROTATION) {
			mRotation += 3.0;
			mcBoss.setRotation(mRotation);
			mcBoss.draw();
		}
		else {
			mcBoss.setX(SDLManager::instance().windowWidth() - mcBoss.getWidth());
		}
	}

	delete mpcSpear;
	mpcSpear = nullptr;
}

//*****************************************************************************
// Method:	    isDone
//
// Description:	Determines if the stage is over
//
// Parameters:  none
//
// Returned:		A bool that is true if all (the max number) the Sharks are 
//              done and false otherwise
//*****************************************************************************
bool StageThree::isDone() {
	if (mRotation == 360.0) {
		mbIsDone = true;
	}

	return mbIsDone;
}
const int StageThree::SIZE_WAVE = 6;