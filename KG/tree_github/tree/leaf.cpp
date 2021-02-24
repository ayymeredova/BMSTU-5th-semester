#include<iostream>
#include<stdlib.h>
#include"fssimplewindow.h"
#include"leaf.h"
#include <math.h>

using namespace std;

// Transforms model coordinates to screen coordinates s.t origin lies in bottom right corner of graphics window
void getScreenCoords(double modelX, double modelY, double modelZ,  double &screenX, double &screenY, double &screenZ)
{
    double screenOriginX = 0, screenOriginY = 600, screenOriginZ = 0;		/* Coordinates of origin of model in pixels */

                                                        // Conversion to transform model coordinates to pixel coordinates
    screenX = (modelX + screenOriginX);
    screenY = (-modelY + screenOriginY);
    screenZ = (modelZ + screenOriginZ);
}


// Draws filled circle at specified location with specified radius
void drawCircle(double centerX, double centerY, double centerZ, double radius)
{
    double screenX, screenY, screenZ;			// Variables for pixel coordinates

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);

    // Drawing an approximate circle using the below coordinates
    for (int i = 0; i < 60; i++) {
        double angle = double(i) * PI / 30.0;
        double x = double(centerX) + cos(angle)*double(radius);
        double y = double(centerY) + sin(angle)*double(radius);
        double z = double(centerZ) + cos(angle)*double(radius);

        getScreenCoords(x, y, z, screenX, screenY, screenZ);
        glVertex3d(screenX, screenY, screenZ);
    }

    glEnd();
}


Leaf::Leaf() {
    // Setting height & width of graphics window
    winWidth = 800;
    winHeight = 600;

    x = rand() % winWidth;				// range of x is full width of window
    // range of y is 60% of window height starting from top
    y = int(rand() % (winHeight*3/5) + (winHeight*0.4));
    z = int(rand() % (winHeight*1/2) + (winHeight*0.2));
    radius = 2;
    reached = false;

    //cout << "X " << x << " Y " << y << endl;
}

void Leaf::getPos(int &x_, int &y_, int &z_) {
    x_ = x;	y_ = y; z_ = z;
}

void Leaf::setLeafReached() {
    reached = true;
}

// Returns value of 'reached' attribute
bool Leaf::getLeafReached() {
    return reached;
}

void Leaf::draw() {
    drawCircle(x, y, z,radius);
}
