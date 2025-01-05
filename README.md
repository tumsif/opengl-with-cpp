# OpenGl
Is an api for creating 2D and 3D graphic images

Opengl specifies a set of commands in which each command directs a drawing action or causes special effects

It is independent of windowing characteristics of each operating system. ie it is platform independent.

## Setup
- working with fedora when the `<GL/glut>` header is not found unless you download the package `freeglut-devel`. 
- for ubuntu versions install packages `mesa-utils` and `freeglut2-dev` packages.
- To compile the source file to excecutable it is very important to include the package that was used eg. `g++ main.cpp -o main -lGL -lGLU -lglut` then excecute by running `./main`
- I have also added a shell command run.sh that compiles and run the program.

## Concepts
### Fundamentals
OpenGl allows one to draw graphics primitives (i.e polyline, text, filled regions), primitives are specified and other OpenGL operations are described by issuing commands in the form of *function calls*.

Primitives are specified by a group of one or more vertices.

A vertex defines a point, an endpoint of a line, or a corner of a polygon where the two edges meet.

Data consisting of vertex coordinates, colours, texture coordinates, etc., is associated with a vertex, and each vertex and its associated data are processed independently, in order and in the same way.

Commands are always processed in order in which they are received, although there may be an intermediate delay before a command takes effect.

This means that each primitive is drawn completely before any subsequent command takes effect.

## Simple Drawings using OpenGL
Every graphics program begins with a main method in c++ 

The main method initializes the window for the graphics to be drawn.

The skeleton of our main function is going to start as:

```
int main(int argc, char **argv) {

	// init GLUT and create window

	// register callbacks

	// enter GLUT event processing cycle

}
```

A. During the initialization of GLUT and creating a window

The following are the series of methods that are to be used.

1. `glutInit(&argc, argv);`
- argc - A pointer to the unmodified argc variable from the main function.
- argv - A pointer to the unmodified argv variable from the main function.

2. `glutInitWindowPosition(int x, int y);`
- Specifies the position of the window that will go to be placed. Use the parameter -1 for the window manager to decide where to place the window which by default it is at the center

3. `glutInitWindowSize(int width, int height);`
- specifies the width and height of the window being created.

4. `glutInitDisplayMode(unsigned int mode);`
The predefined constants to specify the color model are:
```
    GLUT_RGBA or GLUT_RGB – selects a RGBA window. This is the default color mode.
    GLUT_INDEX – selects a color index mode.
```
The display mode also allows you to select either a single or double buffer window. The predefined constants for this are:
```
    GLUT_SINGLE – single buffer window
    GLUT_DOUBLE – double buffer window, required to have smooth animation.
```
There is more, you can specify if you want a window with a particular set of buffers. The most common are:
```
    GLUT_ACCUM – The accumulation buffer
    GLUT_STENCIL – The stencil buffer
    GLUT_DEPTH – The depth buffer
```
So, suppose you want a RGB window, with double buffering, and a depth buffer. All you have to do is to OR all the respective constants in order to create the required display mode.

```
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT DEPTH);
```

5. `glutCreateWindow(char *title);`
- creates the window and attach a title to it.

Following the above method implementation a window is created. But it results to displaying a blank screen

## Event Driven Programming
Most windows-based programs are event-driven; that is the program responds to various events, such as a mouse click, the press of a keyboard key, or the resizing of a screen window.

OpenGL comes with a Utility Toolkit which provides tools to assist with event management.

The programmer uses this callbacks and register a callback to this method for handling various events

This methods are:
1. `glutDisplayFunc` - register a drawing callback, functions that creates displays are passed here.
2. `glutReshapeFunc` - register reshaping callbacks
3. `glutMouseFunc` - register the mouse event
4. `glutkeyboardFunc` - register a keyboard event and passed callbacks to handle them.
5. `glutMainLoop` - **Important** creates an unending loop that ensures the display is shown until an event such as closing the window is called.
