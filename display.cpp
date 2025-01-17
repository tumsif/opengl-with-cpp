#include "drawline.h"
#include "colors.h"

float red = 1.0f;
float green = 1.0f;
float blue = 1.0f;

void renderTriangle(void)
{
    glBegin(GL_TRIANGLES);
        glVertex3f(float(-2.0) , float(-2.0) , float(-5.0));
		glVertex3f(float(2.0) , float(0.0), float(-5.0));
		glVertex3f(float(0.0) , float(2.0) , float(-5.0));
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

void renderUsingInt(void){
    glBegin(GL_POLYGON);
        glVertex2i(10, 10);
        glVertex2i(20, 10);
        glVertex2i(20, 20);
        glVertex2i(10, 20);
    glEnd();
}

void renderDisplay(void)
{
    // clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // std::cout << "cleared color buffer" << std::endl;

    // render first shape rectangle
    // renderRectangle();
    // std::cout << "created a rectangle" << std::endl;

    glColor3f(red, green, blue);
    // render second shape triangle
    // renderTriangle();
    // std::cout << "created a triangle" << std::endl;

    // render using int
    /**
     * OpenGL uses normalized device coordinates ranging from −1 to 1 for both x and y axes, 
     * which might cause your integer coordinates to fall outside the visible range.
     * 
     * this can be done by adjusting the projection and viewport
     * these methods are 
     * glMatrixMode(GL_PROJECTION)
     * glLoadIdentity()
     * gluOrtho2D(0, 100, 0, 100) adjusts the viewport references to range from 0 to 100
     * 
     * Alternatively we can match the viewport configurations to match the window's dimensions
     * glViewPort(0, 0, 500, 500) where the windows size is 500x500 pixels.
     */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // gluOrtho2D(0, 100, 0, 100); // right and top set to 100, this means elements start being placed with 0, 0 at bottom left
    // alternatively to place at center 0, 0 ranging from -100 to 100 in x and y directions
    gluOrtho2D(-100, 100, -100, 100);
    renderUsingInt();

    // swap buffers to display the rendered shapes
    glutSwapBuffers();
    // std::cout << "swapped color buffers" << std::endl;
}

