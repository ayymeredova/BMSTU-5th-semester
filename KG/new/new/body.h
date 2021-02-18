#ifndef BODY_H
#define BODY_H

#pragma once

#include<vector>


const double PI = 3.14159265359;

using namespace std;

// Transforms model coordinates to screen coordinates s.t origin lies in bottom right corner of graphics window
void getScreenCoords(double modelX, double modelY, double &screenX, double &screenY);

class Leaf {
private:
    int x, y, radius;			// x, y coordinates & radius of a leaf (represented as a point)
    int winWidth, winHeight;	// Width, height of graphics window
    bool reached;				// Flag indicated whether branch has reached close enough to leaf

public:
    Leaf();						// Default constructor
    void getPos(int &x_, int &y_);		// Function to get values of x, y coordinates of the leaf
    void setLeafReached();		// Sets flag indicator to true when branch reaching close enough to leaf
    bool getLeafReached();		// Returns value of 'reached' attribute
    void draw();				// Draws a leaf point on the graphics window
};



class Branch {
private:
    double x, y;				// x, y coordinates for starting of branch segment
    vector<double> origDir;		// Container for original growth direction of branch segment along (x,y) axes
    vector<double> growthDir;	// Container for growth direction influenced by nearest leaves
    Branch *parent;				// Pointer to parent of the branch
    int nearestLeafCount;		// No. of nearest leaves to avg. over their contribution to its growth direction

public:
    Branch() {};				// Default constructor
    Branch(double x, double y, vector<double> growthDir_, Branch *parent_);		// Parameterized constructor
    //Branch(const Branch &theBranch);				// Copy constructor

    void getBasePos(double &x_, double &y_);	// Function to get values of x, y coords of base of branch
    void setDir(vector<double> dir_);
    vector<double> getDir();
    int getCount();
    void incrementCount();
    void reset();

    void draw();
    Branch* next();		// Function which sets the next branch
    Branch* getParent() { return this->parent;}
};







class Tree {
private:
    double winWidth, winHeight;	// Specifies width & height of graphics window
    int minDist, maxDist;		// Distance bounds for a leaf to influence growth direction of branch
    int numLeaves;				// Specified number of leaf points for the branch to "colonize"
    vector<Leaf> allLeaves;		// Container for all leaf objects
    Branch *root;				// Specifies root branch for the tree
    vector<Branch*> branches;	// Container for all branch objects

public:
    Tree(int minDist_, int maxDist_, double width = 800., double height = 600.);	// default constructor
    void grow();
    void draw();		// Draws the leaf points & branch segments on the graphics window
};

#endif // BODY_H
