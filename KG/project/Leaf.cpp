#include "leaf.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include "model_handler.h"
#define SIZE 2426

using namespace std;

QVector<QVector3D> read_points(const char *filename)
{
    QVector<QVector3D> points;

    setlocale(LC_NUMERIC, "C");

//    string line = NULL;

    FILE *f = fopen(filename, "r");
    if (f)
    {
        float x, y, z;
        while(!feof(f))
        {
            if (fscanf(f, "%f %f %f", &x, &y, &z) == 3)
            {
                points.push_back({x, z, -y});
            }
        }

        fclose(f);
    }

    return points;
}

void getScreenCoords(double modelX, double modelY, double modelZ, double &screenX, double &screenY, double &screenZ)
{
    double screenOriginX = 0, screenOriginY = 600, screenOriginZ = 0;		/* Coordinates of origin of model in pixels */

                                                        // Conversion to transform model coordinates to pixel coordinates
    screenX = (modelX + screenOriginX);
    screenY = (-modelY + screenOriginY);
    screenZ = (modelZ + screenOriginZ);  //-------------//
}


// Draws filled circle at specified location with specified radius
void drawCircle(float centerX, float centerY, float centerZ, float radius)
{
    float screenX, screenY, screenZ;			// Variables for pixel coordinates

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);

    // Drawing an approximate circle using the below coordinates
    for (int i = 0; i < 60; i++) {
        float angle = float(i) * PI / 30.0;
        float x = float(centerX) + cos(angle)*float(radius);
        float y = float(centerY) + sin(angle)*float(radius);
        float z = float(centerZ) + cos(angle)*float(radius);  //------------//
        getScreenCoords(x, y, z, screenX, screenY, screenZ);
        glVertex3d(screenX, screenY, screenZ);
    }

    glEnd();
}


auto points = read_points("points.txt");

Leaf::Leaf() {
    winWidth = 800;
    winHeight = 600;
    int random = rand() % SIZE;
    x = points[random].x();
    y = points[random].y();
    z = points[random].z();
    radius = 2;
    reached = false;
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
