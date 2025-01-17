#include "drawline.h"
#include "colors.h"
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
 * 
 * 
 * Also GLUT provides a function to process special keys, glutSpecialFunc(). special keys such as f1, f2 etc.
 * the function called processSpecialKeys implemented below will be passed to it in the main.cpp
 * 
 * 
 * GLUT SPECIAL KEYS PREDEFINED CONSTANTS
 * GLUT_KEY_F1		F1 function key
 * GLUT_KEY_F2		F2 function key
 * GLUT_KEY_F3		F3 function key
 * GLUT_KEY_F4		F4 function key
 * GLUT_KEY_F5		F5 function key
 * GLUT_KEY_F6		F6 function key
 * GLUT_KEY_F7		F7 function key
 * GLUT_KEY_F8		F8 function key
 * GLUT_KEY_F9		F9 function key
 * GLUT_KEY_F10		F10 function key
 * GLUT_KEY_F11		F11 function key
 * GLUT_KEY_F12		F12 function key
 * GLUT_KEY_LEFT	Left function key
 * GLUT_KEY_RIGHT	Right function key
 * GLUT_KEY_UP		Up function key
 * GLUT_KEY_DOWN	Down function key
 * GLUT_KEY_PAGE_UP	Page Up function key
 * GLUT_KEY_PAGE_DOWN	Page Down function key
 * GLUT_KEY_HOME	Home function key
 * GLUT_KEY_END		End function key
 * GLUT_KEY_INSERT	Insert function key
 */


void processNormalKeys(unsigned char key, int x, int y)
{
    if (key == 27) // escape key
    {
        // if escape key is pressed the program will exit the glutMainLoop
        exit(0);
    }

    switch (key)
    {
        case 82: // 'R'
        case 114: // 'r'
            red = red + 0.1f;
            green = 0.0f;
            blue = 0.0f;
            break;
        case 71: // 'G'
        case 103: // 'g'
            red = 0.0f;
            green = green + 0.1f;
            blue = 0.0f;
            break;
        case 66: // 'B'
        case 98: // 'b'
            red = 0.0f;
            green = 0.0f;
            blue = blue + 0.1f;
            break;
    }
}

void processSpecialKeys(int key, int x, int y)
{
    std::cout << "Special key pressed: " << key << "\n";
    switch (key)
    {
        case GLUT_KEY_F1:
            red = 1.0f;
            green = 0.0f;
            blue = 0.0f;
            break;
        case GLUT_KEY_F2:
            red = 0.0f;
            green = 1.0f;
            blue = 0.0f;
            break;
        case GLUT_KEY_F3:
            red = 0.0f;
            green = 0.0f;
            blue = 1.0f;
            break;
    }
}