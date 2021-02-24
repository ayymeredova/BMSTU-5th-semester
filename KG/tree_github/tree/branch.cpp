#include<iostream>
//#include"fssimplewindow.h"
#include"branch.h"
#include"leaf.h"

using namespace std;

// Default constructor for setting parameters of branch
Branch::Branch(double x_, double y_, double z_, vector<double> growthDir_, Branch *parent_)
{
    x = x_;
    y = y_;
    z = z_;
    //cout << "New Branch X" << x_ << " Y " << y_ << endl;
    growthDir = growthDir_;
    origDir = growthDir_;
    parent = parent_;
    nearestLeafCount = 0;
    //if (parent != nullptr)
    //	cout << "Parent X" << parent_->x << " Y " << parent_->y << endl;
}


// Function for extracting coords of base of the branch
void Branch::getBasePos(double & x_, double & y_, double& z_) {
    x_ = x; y_ = y; z_ = z;
}

void Branch::setDir(vector<double> dir_) {
    growthDir = dir_;
}

vector<double> Branch::getDir() {
    return growthDir;
}


int Branch::getCount() {
    return nearestLeafCount;
}

void Branch::incrementCount() {
    nearestLeafCount++;
}

void Branch::reset() {
    growthDir = origDir;
    nearestLeafCount = 0;
}


void Branch::draw()
{
    double sCurrentX, sCurrentY, sCurrentZ;					// Store screen coords for current branch
    double parentX, parentY, parentZ, sParentX, sParentY, sParentZ;	// Store physical & screen coords for parent branch
    if (parent != nullptr) {
        parent->getBasePos(parentX, parentY, parentZ);

        // Obtaining screen coords using model coords for drawing branch
        getScreenCoords(x, y, z, sCurrentX, sCurrentY, sCurrentZ);
        getScreenCoords(parentX, parentY, parentZ, sParentX, sParentY, sParentZ);

        glColor3f(1.0, 1.0, 1.0);	// Setting line color to white

        // Drawing the line from current to parent base point
        glBegin(GL_LINES);
        glVertex3d(sCurrentX, sCurrentY, sCurrentZ);
        glVertex3d(sParentX, sParentY, sParentZ);
        glEnd();
    }
}


// Function for creating the next branch using the attributes of the current branch
Branch* Branch::next()
{
    // Computing position of base for the next branch
    double nextPosX = x + growthDir[0]*2;
    double nextPosY = y + growthDir[1]*2;
    double nextPosZ = z + growthDir[2]*2;

    // Creating the next branch
    return new Branch(nextPosX, nextPosY, nextPosZ, growthDir, this);
}
