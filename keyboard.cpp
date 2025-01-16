/**
 * GLUT allows processing of keyboard events.
 * 
 * The callback created below is used to process keyboard events.
 * 
 * use glKeyboardFunc() to register the keyboard events.
 * 
 * The function passed through the glutKeyboardFunc needs to have three arguments
 * - The first provides the ASCII code of the key pressed
 * - the remaining provides the mouse coordinates on the screen
 * 
 * mouse position is relative to the top corner of the client window.
 */

#include "drawline.h"

void processNormalKeys(unsigned char key, int x, int y)
{
    if (key == 27) // escape key
    {
        // if escape key is pressed the program will exit the glutMainLoop
        exit(0);
    }
}