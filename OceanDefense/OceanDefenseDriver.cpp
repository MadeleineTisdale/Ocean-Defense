//****************************************************************************
// File name:	 OceanDefenseDriver.cpp
// Author:		 Kaylie Yamaguchi, Madeleine Tisdale, and Zach Rodriguez
// Date:		   4/26/2017
// Class:		   CS250-02
// Purpose:		 To create an application, Ocean Defense, that uses sprites, 
//             object-oriented code, animation, user interaction, dynamic 
//             memory allocation, and proper object-oriented design 
//             principals.
//****************************************************************************

//****************************************************************************
// LOG OF ACTIVITY:
// 4/26/19 (4:15pm - 5:57pm) - Madeleine: Created the projects (Graphics2D and
//                                        OceanDefense) and fixed all the
//                                        linking and inheritance.
// 4/30/19 (12:10am - 1:15am) - Madeleine: Wrote the interfaces for 
//                                         MovingObject, Jellyfish, Shark, 
//                                         ShootingElement, Trash, 
//                                         TrashMonster, and User.
// 4/30/19 (6:30pm - 9:00pm) - Kaylie: Implementing TrashMonster, adding all 
//                                     cpp files and commenting all of the 
//                                     functions.
// 5/1/19 (8:45pm - 9:56pm) - Madeleine: Implementing MovingObject, Shark, and
//                                       User. Also fixed some of the .h files
//
//****************************************************************************

#include "SDLManager.h"
#include "SDLMovingSprite.h"
#include "MovingObject.h"
#include "Shark.h"

//****************************************************************************
// Function:    main
//
// Description: draw one moving sprite and rotate one sprite on the screen
//
// Parameters:  argc, argv: command line arguments
//
// Returned:    EXIT_SUCCESS on success
//****************************************************************************
int main (int argc, char *argv[])
{
  int windowXPosition = 100,
    windowYPosition = 100,
    windowSizeX = 600,
    windowSizeY = 640;
  int radius = 20;
  int i = 0;
  double rotate = 1.0;

  SDLManager &rcManager = SDLManager::instance ();
  SDL_Event uEvent;
  
	SDLSprite *pcSpaceship;
  SDLMovingSprite *pcMovingShip;
  Shark *pcMovingShark;
  

  int verdana30 = rcManager.loadFont ("C:/Windows/Fonts/verdana.ttf", 30);
   
  
  rcManager.initializeWorld (windowXPosition, windowYPosition,
    windowSizeX, windowSizeY);


  // Sprite creation MUST happen AFTER 
  // the call to  rcManager.initializeWorld ()
  // 
  // Put spaceship bitmap close to center of screen
  pcSpaceship = new SDLSprite ("Images\\ball_green.png", 280, 300);
  pcMovingShip = new SDLMovingSprite ("Images\\ufo.png", 180, 300,
                                      Direction2D::SE);
  pcMovingShark = new Shark();

  rcManager.setBackgroundColor (Color::BLACK);
  rcManager.setForegroundColor (Color::WHITE);
    

  rcManager.animationStart ();
  rcManager.clearBackground ();
  
  // game loop
  while (rcManager.animationIsRunning ())
  {
    // update
    // move items, change position of objects.

    pcMovingShip->update ();
    pcMovingShark->move();

    // Start animating spaceship after 2 seconds
    ++i;
    if (i > 2 * SDLManager::DEFAULT_FPS)
    {
      if (360 == rotate) {
        rotate = 0.0;
      }
      else {
        rotate += 1.0;
      }

      pcSpaceship->setRotation(rotate);
    }
    // end update code

    rcManager.clearBackground ();

    // draw
    // draw items on the screen.
    pcMovingShip->draw();
    pcSpaceship->draw();
    pcMovingShark->draw();

    // Shows correct use of fonts
    rcManager.displayText(100, 0, "Space ... The Final Frontier",
                          Color::WHITE, verdana30);
    // end draw code


    if (rcManager.getSDLEvent (uEvent))
    {
      if (uEvent.type == SDL_QUIT)
      {
        rcManager.animationStop ();

        // customize QUIT event handling

        // end QUIT event handling
      }

      // handle event

      // end handle event code
    }    

    rcManager.render ();
  }

  delete pcSpaceship;
  delete pcMovingShip;

  return EXIT_SUCCESS;
}
