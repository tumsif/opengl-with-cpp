#include <GL/glut.h>
#include <iostream>

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(0.0, 0.0, 0.5);
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv); // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode
    glutInitWindowSize(1000, 600); // set the window size
    glutInitWindowPosition(500, 300); // set the window position on the screen
    glutCreateWindow("Hello IS236"); // opens the screen window
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}