//*****************************************************************************
// File name:	 StageOne.cpp
// Author:		 Kaylie Yamaguchi and Madeleine Tisdale
// Date:		   4/30/2019
// Class:		   CS 250-02
// Assignment: #7 Ocean Defense
// Purpose:		 Implement stage one
//*****************************************************************************

#include "StageOne.h"

//*****************************************************************************
// Constructor:	StageOne
//
// Description:	Initializes the user in the class to one that is given in the
//              parameter and all of the Sharks to nullptrs
//
// Parameters:  rUser - an object of User class
//
// Returned:		none
//*****************************************************************************
StageOne::StageOne(User rUser) {
  const int INITIAL_VAL = 0;

	mcUser = rUser;
	mSizeSharks = INITIAL_VAL;

	for (int i = 0; i < MAX_SHARKS; i++) {
		mpacSharks[i] = nullptr;
	}

}

//*****************************************************************************
// Constructor:	StageOne
//
// Description:	Initializes the user and the size of the Shark array and all of
//              the Sharks to nullptrs
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
StageOne::StageOne() {
  const int INITIAL_VAL = 0;

  User cTempUser;
  mcUser = cTempUser;
  mSizeSharks = INITIAL_VAL;

	for (int i = 0; i < MAX_SHARKS; i++) {
		mpacSharks[i] = nullptr;
	}
}

//*****************************************************************************
// Destructor:  ~StageOne
//
// Description:	Deletes all the dynamically allocated Sharks from mpacSharks
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
StageOne::~StageOne() {

  // Delete all the dynamically allocated Shark objects
  for (int i = 0; i < MAX_SHARKS; i++) {
    if (mpacSharks[i] != nullptr) {
      delete mpacSharks[i];
			mpacSharks[i] = nullptr;
    }
  }
}

//*****************************************************************************
// Method:	    addSharks
//
// Description:	Add sharks mpacSharks
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
void StageOne::addSharks() {
  int size = mSizeSharks;
  if ((areSharksDone() || mSizeSharks == 0) && mSizeSharks < MAX_SHARKS) {
    for (int i = size; i < size + SIZE_WAVE; i++) {
      mpacSharks[i] = new Shark();

      mpacSharks[i]->spawnRandom();

      mSizeSharks++;
    }
  }
}

//*****************************************************************************
// Method:	    draw
//
// Description:	Draw the active sharks to the screen
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
void StageOne::draw() const {
  for (int i = 0; i < mSizeSharks; i++) {
    if (mpacSharks[i] != nullptr && mpacSharks[i]->isOnScreen()) {
      mpacSharks[i]->draw();
    }
  }

  mcUser.draw();
}

//*****************************************************************************
// Method:	    update
//
// Description:	Update all the active sharks
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
void StageOne::update() {
  for (int i = 0; i < mSizeSharks; i++) {
    if (mpacSharks[i] != nullptr && mpacSharks[i]->isOnScreen()) {
      mpacSharks[i]->update();
    }
  }
}

//*****************************************************************************
// Method:      updateUser
//
// Description:	Updates the user's position.
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void StageOne::updateUser(int xCoord, int yCoord) {
  mcUser.move(xCoord, yCoord);
}

//*****************************************************************************
// Method:	    handleCollision
//
// Description:	If the user collides with a shark, make a sound, adjusts 
//              the user's health, and deletes the shark
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
void StageOne::handleCollision(SDLManager &rcManager) {
  for (int i = mSizeSharks - SIZE_WAVE; i < mSizeSharks; i++) {
    if (mpacSharks[i] != nullptr && mcUser.collision(mpacSharks[i])) {
      // Make a sound
      playOuchSound(rcManager);

      // Decrease the health of the user
      mcUser.hit();

      // Delete the shark and set it to nullptr
      delete mpacSharks[i];
      mpacSharks[i] = nullptr;
    }
  }
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
bool StageOne::isDone() {
  if (areSharksDone() && mSizeSharks == MAX_SHARKS) {
    mbIsDone = true;
  }

  return mbIsDone;
}

//*****************************************************************************
// Method:	    areSharksDone
//
// Description:	Determines if all Sharks in mpacSharks are done (off screen)
//
// Parameters:  none
//
// Returned:		A bool that is true if the Sharks are done and false otherwise
//*****************************************************************************
bool StageOne::areSharksDone() const {
  bool bSharksDone = true;

  for (int i = 0; i < mSizeSharks; i++) {
    if (mpacSharks[i] != nullptr && mpacSharks[i]->isOnScreen()) {
      bSharksDone = false;
    }
  }

  return bSharksDone;
}

//*****************************************************************************
// Method:	    playOuchSound
//
// Description: Plays a ouch sound.
//
// Parameters:  rcManager - object of class SDLManager
//
// Returned:	  none
//*****************************************************************************
void StageOne::playOuchSound(SDLManager &rcManager) const {
  const string SOUND = "OuchSound.wav";
  bool bIsRepeated = false;

  rcManager.playSound(SOUND, bIsRepeated);

  return;
}

//*****************************************************************************
// Method:	    getUser
//
// Description: Gets the user from the object and returns it
//
// Parameters:  none
//
// Returned:	  A User object (mcUser)
//*****************************************************************************
User StageOne::getUser() const {
  return mcUser;
}

// Define the static variables
const int StageOne::SIZE_WAVE = 6;