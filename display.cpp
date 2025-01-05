#include "drawline.h"

void renderTriangle(void)
{
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.9, 0, 0);
        glVertex3f(-0.55, 0.5, 0);
        glVertex3f(-0.25, 0, 0);
	glEnd();
}

void renderRectangle(void)
{
    glBegin(GL_POLYGON);
        glVertex3f(0.9, 0.0, 0.0);
        glVertex3f(0.9, 0.5, 0.0);
        glVertex3f(0.5, 0.5, 0.0);
        glVertex3f(0.5, 0.0, 0.0);
    glEnd();
}

void renderDisplay(void)
{
    // clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);
    std::cout << "cleared color buffer" << std::endl;

    // render first shape rectangle
    renderRectangle();
    std::cout << "created a rectangle" << std::endl;

    // render second shape triangle
    renderTriangle();
    std::cout << "created a triangle" << std::endl;

    // swap buffers to display the rendered shapes
    glutSwapBuffers();
    std::cout << "swapped color buffers" << std::endl;
}

