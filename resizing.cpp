#include "drawline.h"

/**
* By default when a window is resized the display gets distored. This is due to incomplete
* setting of the perspective. By default, the perspective assumes that ratio of width/height is 1 and then draws it
* 
* Therefore every time the window ratio of height to width is changed the perspective gets distorted and a calculation needs to be redone
* 
* GLUT provides a way to define which function to be called when window is resized
* 
* We can register a callback here for recomputing 
* 
* The resizingDisplay() fuction needs to be registered inside glutReshapeFunc() event listener
* 
*/
void resizingDisplay(int width, int height)
{
    std::cout << "Resizing width: " << width << ", height: " << height << "\n";

    if (height == 0)
    {
        /* prevent division by 0 when window is too short */
        height = 1;
    }

    float ratio = 1.0 * width / height;

    // set viewport to entire window
    glViewport(0, 0, width, height);

    // Use projection Matrix
    glMatrixMode(GL_PROJECTION);

    // reset matrix
    glLoadIdentity();

    if (width >= height){
        // means left and right are changing so adjust the measurement
        gluOrtho2D(-100 * ratio, 100 * ratio, -100, 100);
    }else {
        gluOrtho2D(100, 100, -100 * ratio, 100 * ratio);
    }

    // set correct perspective
    gluPerspective(45, ratio, 1, 1000);

    // get back to modelview
    glMatrixMode(GL_MODELVIEW);
    
}