#include "SDLManager.h"
#include "Direction2D.h"
#include "Color.h"
#include "MovingCircle.h"
#include "ExpandingCircle.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
  const int MAX_ECIRCLES = 1;
  int windowXPosition = 100,
    windowYPosition = 100,
    windowSizeX = 640,
    windowSizeY = 640,
    xMouseVal = 0,
    yMouseVal = 0,
    numECircles = 0;
  ExpandingCircle acECircles[MAX_ECIRCLES];

  SDLManager &rcManager = SDLManager::instance();

  rcManager.initializeWorld(windowXPosition, windowYPosition,
    windowSizeX, windowSizeY);
  rcManager.setBackgroundColor(Color::TEAL);
  rcManager.setForegroundColor(Color::BLACK);

  SDL_Event uEvent;
  rcManager.animationStart();
  rcManager.clearBackground();

  MovingCircle cCircs[50];

  // Read in circle info from file
  int num = 0;
  ifstream myFile;
  myFile.open("circles.txt");
  if (!myFile.is_open()) {
    cout << "Could not open file" << endl;
    system("pause");
    return EXIT_FAILURE;
  }

  while (!myFile.eof() && num < 10) {
    cCircs[num].setMovementBoundingBox(0, 0,
      windowSizeX,
      windowSizeY);
    cCircs[num++].read(myFile);
  }

  // game loop
  while (rcManager.animationIsRunning()) {
    // update
    // move items, change position of objects.
    for (int i = 0; i < num; i++) {
      cCircs[i].move();
    }

    for (int i = 0; i < numECircles; i++) {
      acECircles[i].expand();
    }
    // end update code


    rcManager.clearBackground();

    // draw
    // draw items on the screen.
    for (int i = 0; i < num; i++) {
      cCircs[i].draw(rcManager);
    }
    for (int i = 0; i < numECircles; i++) {
      acECircles[i].draw(rcManager);
    }
    // end draw code

    if (rcManager.getSDLEvent(uEvent)) {
      if (SDL_QUIT == uEvent.type) {
        rcManager.animationStop();

        // customize QUIT event handling

        // end QUIT event handling
      }

      // handle event
      if (SDL_MOUSEBUTTONDOWN == uEvent.type && numECircles < MAX_ECIRCLES) {
        rcManager.mousePosition(xMouseVal, yMouseVal);
        ExpandingCircle cTempECircle(xMouseVal, yMouseVal);
        acECircles[numECircles++] = cTempECircle;
      }
      // end handle event code

    }

    rcManager.render();
  }

  return EXIT_SUCCESS;
}
