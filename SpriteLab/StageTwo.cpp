//*****************************************************************************
// File name:	 StageTwo.h
// Author:		 Kaylie Yamaguchi
// Date:		   5/3/2019
// Class:		   CS 250-02
// Assignment: #7 Ocean Defense
// Purpose:		 Build a class to represent Stage two of the game.
//*****************************************************************************

#include "StageTwo.h"

//*****************************************************************************
// Constructor:	StageTwo
//
// Description:	Initializes mcUser to the given parameter and initializes the 
//							arrays of pointers to nullptr.
//
// Parameters:  cUser - the user object being used in the game.
//
// Returned:		none
//*****************************************************************************
StageTwo::StageTwo(const User & rcUser) {
	mcUser = rcUser;

	for (int i = 0; i < MAX_JELLYFISH; i++) {
		mapcJellyfish[i] = nullptr;
	}

	for (int i = 0; i < MAX_TRASH; i++) {
		mapcTrash[i] = nullptr;
	}
	mNumJellyfish = 0;
	mNumTrash = 0;
	mTrashCollected = 0;
}

//*****************************************************************************
// Constructor:	StageTwo
//
// Description:	Initializes mcUser and initializes the arrays of pointers to  
//							nullptr.
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
StageTwo::StageTwo() {
	User cTempUser;

	mcUser = cTempUser;

	for (int i = 0; i < MAX_JELLYFISH; i++) {
		mapcJellyfish[i] = nullptr;
	}

	for (int i = 0; i < MAX_TRASH; i++) {
		mapcTrash[i] = nullptr;
	}
	mNumJellyfish = 0;
	mNumTrash = 0;
	mTrashCollected = 0;
}

//*****************************************************************************
// Destructor:	~StageTwo
//
// Description:	Deletes any allocated memory in StageTwo.
//
// Parameters:	none
//
// Returned:		none
//*****************************************************************************
StageTwo::~StageTwo() {
	for (int i = 0; i < MAX_JELLYFISH; i++) {
		if (mapcJellyfish[i] != nullptr) {
			delete mapcJellyfish[i];
		}
	}

	for (int i = 0; i < MAX_TRASH; i++) {
		if (mapcTrash != nullptr) {
			delete mapcTrash[i];
		}
	}
}

//*****************************************************************************
// Method: createJellyAndTrashfish
//
// Description:	Creates the jellyfish in stage two.
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void StageTwo::createJellyfishAndTrash() {
	int mAmountJelly = mNumJellyfish;
	int size = mNumTrash;

	if (mNumJellyfish < MAX_JELLYFISH && ((areJellyfishDone() && isTrashDone())
		|| mNumJellyfish == 0)) {

		for (int i = mAmountJelly; i < mAmountJelly + SIZE_WAVE; i++) {
			mapcJellyfish[i] = new Jellyfish();
			mapcJellyfish[i]->spawnRandom();
			mNumJellyfish++;
		}
		for (int i = size; i < size + SIZE_WAVE; i++) {
			mapcTrash[i] = new Trash();
			mapcTrash[i]->spawnRandom();
			mNumTrash++;
		}
	}
}

//*****************************************************************************
// Method:	    update
//
// Description:	Update all the active Jellyfish
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
void StageTwo::update()
{
	for (int i = 0; i < mNumJellyfish; i++)
	{
		if (mapcJellyfish[i] != nullptr && mapcJellyfish[i]->isOnScreen())
		{
			mapcJellyfish[i]->update();
		}
	}

	for (int i = 0; i < mNumTrash; i++)
	{
		if (mapcTrash[i] != nullptr && mapcTrash[i]->isOnScreen())
		{
			mapcTrash[i]->update();
		}
	}


}

//*****************************************************************************
// Method: draw
//
// Description:	Draws the active moving objects to the screen.
//
// Parameters:  none
//
// Returned:	  none
//*****************************************************************************
void StageTwo::draw() {
	// Draw the active Jellyfish objects
	for (int i = 0; i < mNumJellyfish; i++) {
		if (mapcJellyfish[i] != nullptr && mapcJellyfish[i]->isOnScreen()) {
			mapcJellyfish[i]->draw();
		}
	}

	// Draw the active Trash objects
	for (int i = 0; i < mNumTrash; i++) {
		if (mapcTrash[i] != nullptr && mapcTrash[i]->isOnScreen()) {
			mapcTrash[i]->draw();
		}
	}

	mcUser.draw();
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
void StageTwo::updateUser(int xCoord, int yCoord)
{
	mcUser.move(xCoord, yCoord);
}

//*****************************************************************************
// Method:	    handleCollision
//
// Description:	If the user collides with a jellyfish, make a sound, adjusts 
//              the user's health, and deletes the jellyfish
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
void StageTwo::handleCollision(SDLManager &rcManager)
{
	for (int i = mNumJellyfish - SIZE_WAVE; i < mNumJellyfish; i++) {
		if (mapcJellyfish[i] != nullptr && mcUser.collision(mapcJellyfish[i])) {
			// Make a sound
			playJellySound(rcManager);

			// Decrease the health of the user
			mcUser.hit();

			// Delete the Jellyfish and set it to null
			delete mapcJellyfish[i];
			mapcJellyfish[i] = nullptr;
		}
	}
	for (int i = mNumTrash - SIZE_WAVE; i < mNumTrash; i++) {
		if (mapcTrash[i] != nullptr && mcUser.collision(mapcTrash[i])) {
			// Make a sound
			playTrashSound(rcManager);

			// Decrease the health of the user
			mcUser.collectTrash();

			// Delete the Jellyfish and set it to null
			delete mapcTrash[i];
			mapcTrash[i] = nullptr;
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
// Returned:		A bool that is true if all (the max number) the Jellyfish are 
//              done and false otherwise
//*****************************************************************************
bool StageTwo::isDone()
{
	if ((areJellyfishDone() && mNumJellyfish == MAX_JELLYFISH) &&
		(isTrashDone() && mNumTrash == MAX_TRASH))
	{
		mbJellyIsDone = true;
	}
	return mbJellyIsDone;
}

//*****************************************************************************
// Method:	    areJellyfishDone
//
// Description:	Determines if all Jellyfish in mapcJellyfish are done (off 
//							screen)
//
// Parameters:  none
//
// Returned:		A bool that is true if the Jellyfish are done and false 
//							otherwise
//*****************************************************************************
bool StageTwo::areJellyfishDone() {
	bool bJellyfishDone = true;

	// For each of the jellyfish in mapcJellyfish if it is not equal to a null 
	// pointer and on the screen, then the Jellyfish are not done
	for (int i = 0; i < mNumJellyfish; i++) {
		if (mapcJellyfish[i] != nullptr && mapcJellyfish[i]->isOnScreen()) {
			bJellyfishDone = false;
		}
	}

	return bJellyfishDone;
}

//*****************************************************************************
// Method:	    isTrashDone
//
// Description:	Determines if all Trash in mapcTrash are done (off screen)
//
// Parameters:  none
//
// Returned:		A bool that is true if the Trash is done and false otherwise
//*****************************************************************************
bool StageTwo::isTrashDone() {
	bool bTrashDone = true;

	for (int i = 0; i < mNumTrash; i++) {
		if (mapcTrash[i] != nullptr && mapcTrash[i]->isOnScreen()) {
			bTrashDone = false;
		}
	}

	return bTrashDone;
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
User StageTwo::getUser() const {
	return mcUser;
}

//*****************************************************************************
// Method:	    playJellySound
//
// Description: Plays a jellicent sound.
//
// Parameters:  rcManager - object of class SDLManager
//
// Returned:	  none
//*****************************************************************************
void StageTwo::playJellySound(SDLManager &rcManager) const
{
	const string SOUND = "Jellicent.wav";
	bool bIsRepeated = false;

	rcManager.playSound(SOUND, bIsRepeated);

}

//*****************************************************************************
// Method:	    playTrashSound
//
// Description: Plays a garbodor sound.
//
// Parameters:  rcManager - object of class SDLManager
//
// Returned:	  none
//*****************************************************************************
void StageTwo::playTrashSound(SDLManager &rcManager) const {
	const string SOUND = "Garbodor.wav";
	bool bIsRepeated = false;

	rcManager.playSound(SOUND, bIsRepeated);
}

const int StageTwo::SIZE_WAVE = 5;