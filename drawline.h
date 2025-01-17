#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void renderDisplay();
void resizingDisplay(int width, int height);
void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);