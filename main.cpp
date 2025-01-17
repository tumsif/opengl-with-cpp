#include "drawline.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // initialize the toolkit
    // glutInitWindowPosition(500, 300); // set the window position on the screen
    glutInitWindowPosition(-1, -1); // set the window position on the screen

    glutInitWindowSize(1800, 1800); // set the window size

    /*
    GLUT_RGB - sets the rgba window for allowing coloring
    GLUT_SINGLE - creates single buffer window, use glFlush() in rendering callback
    GLUT_DOUBLE - creates double buffer window, required for smooth transition, use glutSwapBuffers(); in rendering callback
    */
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA | GLUT_DOUBLE); // set the display mode

    glutCreateWindow("Hello IS236"); // adds the title to the window
    /*
      The return value of glutCreateWindow is the window identifier. 
      You can use this identifier later within GLUT 
    */

    /*
        If you run the above code, you’ll obtain an empty black console window but no OpenGL window. 
        There are two things left to do before we are ready to render something. 
        The first is to tell GLUT what is the function responsible for the rendering. 
        This function will be called by GLUT everytime the window needs to be painted.
    */

    glutDisplayFunc(renderDisplay); // the renderDisplay function is the rendering function imported from the display.cpp

    glutReshapeFunc(resizingDisplay);

    glutIdleFunc(renderDisplay);

    glutKeyboardFunc(processNormalKeys);

    glutSpecialFunc(processSpecialKeys);

    glutMainLoop();

    return 1;
}