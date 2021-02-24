#ifndef BRANCH_H
#define BRANCH_H


// Code for declaring functions for branch class to keep track of which leaves
// it is closest to and use average of values of resultant directions using
// the nearest laeves to dictate the direction of growth of branches & position for
// beginning of next branch
#pragma once

#include<vector>
#include"leaf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <windows.h>
#include <direct.h>
#include <gl/gl.h>
#include <gl/glu.h>

class Branch {
private:
    double x, y,z;				// x, y coordinates for starting of branch segment
    vector<double> origDir;		// Container for original growth direction of branch segment along (x,y) axes
    vector<double> growthDir;	// Container for growth direction influenced by nearest leaves
    Branch *parent;				// Pointer to parent of the branch
    int nearestLeafCount;		// No. of nearest leaves to avg. over their contribution to its growth direction

public:
    Branch() {};				// Default constructor
    Branch(double x, double y, double z, vector<double> growthDir_, Branch *parent_);		// Parameterized constructor
    //Branch(const Branch &theBranch);				// Copy constructor

    void getBasePos(double &x_, double &y_, double &z_);	// Function to get values of x, y coords of base of branch
    void setDir(vector<double> dir_);
    vector<double> getDir();
    int getCount();
    void incrementCount();
    void reset();

    void draw();
    Branch* next();		// Function which sets the next branch
    Branch* getParent() { return this->parent;}
};


#endif // BRANCH_H
