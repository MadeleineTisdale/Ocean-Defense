//*****************************************************************************
// File name:	 OceanDefense.cpp
// Author:		 Kaylie Yamaguchi and Madeleine Tisdale
// Date:		   4/30/2019
// Class:		   CS 250-02
// Assignment: 07 Ocean Defense
// Purpose:		 Implement OceanDefense
//*****************************************************************************

#include "OceanDefense.h"

//*****************************************************************************
// Constructor:	OceanDefense
//
// Description:	Initializes the member variables 
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
OceanDefense::OceanDefense() {
	const int X_VAL = 700;
	const int Y_VAL = 300;
	const int HEALTH = 5;
	User cTempUser(X_VAL, Y_VAL, HEALTH, 0);

	mcUser = cTempUser;
	mpcStageOne = nullptr;
	mpcStageTwo = nullptr;
	mpcStageThree = nullptr;
	mbIsStarted = false;
}

//*****************************************************************************
// Destructor:	~OceanDefense
//
// Description:	Deletes all the stages
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
OceanDefense::~OceanDefense() {
	if (mpcStageOne != nullptr) {
		delete mpcStageOne;
	}

	if (mpcStageTwo != nullptr) {
		delete mpcStageTwo;
	}

	if (mpcStageThree != nullptr) {
		delete mpcStageThree;
	}
}

//*****************************************************************************
// Method:	    drawStartInstructions
//
// Description:	Draws the starting instructions
//
// Parameters:  rcManager - an object of class SDLManager by reference
//
// Returned:		none
//*****************************************************************************
void OceanDefense::drawStartInstructions(SDLManager &rcManager) const {
	int roboto15 = rcManager.loadFont("Roboto-Light.ttf", 15);
	int juicy60 = rcManager.loadFont("CS Juicy Regular.otf", 60);

	if (!mbIsStarted) {
		rcManager.displayText(285, 150, "Ocean", Color::WHITE, juicy60);
		rcManager.displayText(240, 220, "Defense", Color::WHITE, juicy60);
		rcManager.displayText(240, 305, "Clean the ocean by collecting trash!"
													" Beware of predators!", Color::WHITE, roboto15);
	}
}

//*****************************************************************************
// Method:	    drawGameOver
//
// Description:	Draws game over.
//
// Parameters:  rcManager - an object of class SDLManager by reference
//
// Returned:		none
//*****************************************************************************
void OceanDefense::drawGameOver(SDLManager &rcManager) {
	int juicy60 = rcManager.loadFont("CS Juicy Regular.otf", 60);

	if (!(mcUser.isAlive())) {
		rcManager.displayText(315, 150, "Game", Color::WHITE, juicy60);
		rcManager.displayText(315, 220, "Over", Color::WHITE, juicy60);
		drawGameScore(rcManager);
	}
}

//*****************************************************************************
// Method:	    drawWin
//
// Description:	Draws a win message.
//
// Parameters:  rcManager - an object of class SDLManager by reference
//
// Returned:		none
//*****************************************************************************
void OceanDefense::drawWin(SDLManager &rcManager) {
	int juicy60 = rcManager.loadFont("CS Juicy Regular.otf", 60);

	if (isGameDone() && mcUser.isAlive()) {
		rcManager.displayText(335, 150, "You", Color::WHITE, juicy60);
		rcManager.displayText(330, 220, "Win!", Color::WHITE, juicy60);
		drawGameScore(rcManager);
	}
}

//*****************************************************************************
// Method:	    drawUser
//
// Description:	Draws the User if the stages haven't begun
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
void OceanDefense::drawUser() {
	mcUser.draw();
}

//*****************************************************************************
// Method:	    updateUser
//
// Description:	Update the user in the correct function
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
void OceanDefense::updateUser(int xVal, int yVal) {
	if (!mbIsStarted) {
		mcUser.move(xVal, yVal);
	}
	else if (mpcStageOne != nullptr && !isStageOneDone()) {
		mpcStageOne->updateUser(xVal, yVal);
	}
	else if (mpcStageTwo != nullptr && !isStageTwoDone()) {
		mpcStageTwo->updateUser(xVal, yVal);
	}
	else if (mpcStageThree != nullptr && !isStageThreeDone()) {
		mpcStageThree->updateUser(xVal, yVal);
	}
}

//*****************************************************************************
// Method:	    updateObjects
//
// Description:	Update the objects in the correct function
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
void OceanDefense::updateObjects() {
	if (mpcStageOne != nullptr && !isGameDone() && mbIsStarted && 
		!isStageOneDone()) {
		mpcStageOne->update();
		mpcStageOne->addSharks();
	}

	else if (mpcStageTwo != nullptr && !isGameDone() && mbIsStarted && 
		!isStageTwoDone()) {
		mpcStageTwo->update();
		mpcStageTwo->createJellyfishAndTrash();
	}

	else if (mpcStageThree != nullptr && !isGameDone() && mbIsStarted && 
		!isStageThreeDone()) {
		mpcStageThree->update();
		mpcStageThree->createPredators();
	}
}

//*****************************************************************************
// Method:	    drawObjects
//
// Description:	Draws the obstacles (sharks, jellyfish, trash, ect.) from the
//              correct stage.
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
void OceanDefense::drawObjects() {
	if (mpcStageOne != nullptr && !isGameDone() && !isStageOneDone()) {
		mpcStageOne->draw();
	}
	else if (mpcStageTwo != nullptr && !isGameDone() && !isStageTwoDone()) {
		mpcStageTwo->draw();
	}
	else if (mpcStageThree != nullptr && !isGameDone() && !isStageThreeDone()) {
		mpcStageThree->draw();
	}
}

//*****************************************************************************
// Method:	    calcGameScore
//
// Description:	Calculates the user's score.
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
int OceanDefense::calcGameScore() {
	const int FONT_SIZE = 15;
	const int CONGRATS_X_VAL = 300;
	const int DEAD_X_VAL = 350;
	const int Y_VAL = 50;
	const int HEALTH_MULTIPLIER = 5;
	const int TRASH_MULTIPLIER = 9;
	int gameScore = 0;

	if (isGameDone()) {
		gameScore = (mcUser.getHealth() * HEALTH_MULTIPLIER) + (mcUser.getTrash() * 
								 TRASH_MULTIPLIER);
	}
	if (gameScore < 0) {
		gameScore = 0;
	}

	return gameScore;
}

//*****************************************************************************
// Method:	    drawGameScore
//
// Description:	Calculates the user's score.
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
void OceanDefense::drawGameScore(SDLManager &rcManager) {
	int roboto15 = rcManager.loadFont("Roboto-Light.ttf", 30);

	rcManager.displayText(352, 300, "Score:", Color::WHITE, roboto15);
	rcManager.displayText(462, 300, to_string(calcGameScore()), Color::WHITE, 
												roboto15);
}

//*****************************************************************************
// Method:	    handleCollisions
//
// Description:	Handle collisions for the correct stage of the game
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
void OceanDefense::handleCollisions(SDLManager &rcManager) {
	if (mbIsStarted && !isGameDone() && !isStageOneDone()) {
		mpcStageOne->handleCollision(rcManager);
	}

	else if (mbIsStarted  && !isGameDone() && mpcStageTwo != nullptr 
		&& !isStageTwoDone()) {
		mpcStageTwo->handleCollision(rcManager);
	}

	else if (mbIsStarted && !isGameDone() && mpcStageThree != nullptr 
					 && !isStageThreeDone()) {
		mpcStageThree->handleCollision(rcManager);
	}
}

//*****************************************************************************
// Method:	    isGameStarted
//
// Description:	Returns if the game has started or not.
//
// Parameters:  none
//
// Returned:		bool - true if game started, false otherwise.
//*****************************************************************************
bool OceanDefense::isGameStarted() const {
	return mbIsStarted;
}
//*****************************************************************************
// Method:	    startGame
//
// Description:	Begin the game by creating a StageOne
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
void OceanDefense::startGame() {
	if (!mbIsStarted) {
		mpcStageOne = new StageOne(mcUser);
		mpcStageOne->addSharks();
		mbIsStarted = true;
	}
}

//*****************************************************************************
// Method:	    beginNewStage
//
// Description:	Begin the game by creating a StageOne
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
void OceanDefense::beginNewStage() {
	if (mbIsStarted && !isGameDone() && isStageOneDone() 
		&& mpcStageTwo == nullptr) {

		mpcStageTwo = new StageTwo(mpcStageOne->getUser());
		mpcStageTwo->createJellyfishAndTrash();
	}

	else if (mbIsStarted && !isGameDone() && isStageOneDone() && isStageTwoDone()
		&& mpcStageThree == nullptr) {

		mpcStageThree = new StageThree(mpcStageTwo->getUser());
		mpcStageThree->createPredators();
	}
}

//*****************************************************************************
// Method:	    isStageOneDone
//
// Description:	Checks to see if mpcStageOne is over
//
// Parameters:  none
//
// Returned:		A bool that is true if the stage is over and false otherwise
//*****************************************************************************
bool OceanDefense::isStageOneDone() const {
	bool bIsDone = false;

	if (mpcStageOne != nullptr && mpcStageOne->isDone()) {
		bIsDone = true;
	}
	return bIsDone;
}

//*****************************************************************************
// Method:	    isStageTwoDone
//
// Description:	Checks to see if mpcStageTwo is over
//
// Parameters:  none
//
// Returned:		A bool that is true if the stage is over and false otherwise
//*****************************************************************************
bool OceanDefense::isStageTwoDone() const {
	bool bIsDone = false;

	if (mpcStageTwo != nullptr && mpcStageTwo->isDone()) {
		bIsDone = true;
	}
	return bIsDone;
}

//*****************************************************************************
// Method:	    isStageThreeDone
//
// Description:	Checks to see if mpcStageThree is over
//
// Parameters:  none
//
// Returned:		A bool that is true if the stage is over and false otherwise
//*****************************************************************************
bool OceanDefense::isStageThreeDone() const {
	bool bIsDone = false;
	if (mpcStageThree != nullptr && mpcStageThree->isDone()) {
		bIsDone = true;
	}
	return bIsDone;
}

//*****************************************************************************
// Method:	    isGameDone
//
// Description:	Checks to see if the game is over
//
// Parameters:  none
//
// Returned:		A bool that is true if the stage is over and false otherwise
//*****************************************************************************
bool OceanDefense::isGameDone() {
	if (mbIsStarted && mpcStageOne != nullptr && !isStageOneDone()) {
		mcUser = mpcStageOne->getUser();
	}

	else if (mbIsStarted && mpcStageTwo != nullptr && !isStageTwoDone()) {
		mcUser = mpcStageTwo->getUser();
	}

	else if (mbIsStarted && mpcStageThree != nullptr) {
		mcUser = mpcStageThree->getUser();
	}
	return  (mbIsStarted && (!mcUser.isAlive() || isStageThreeDone()));
}

//*****************************************************************************
// Method:	    playAgain
//
// Description:	Start over the game of OceanDefense by setting the current 
//							object to a newly created object.
//
// Parameters:  none
//
// Returned:		none
//*****************************************************************************
void OceanDefense::playAgain() {
	OceanDefense cNewOceanDefense;

	*this = cNewOceanDefense;
}