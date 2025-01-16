#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void renderDisplay();
void resizingDisplay(int width, int height);