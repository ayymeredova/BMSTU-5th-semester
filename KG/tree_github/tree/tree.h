#ifndef TREE_H
#define TREE_H


// Code for declaring functions for tree class to keep track of leaves
// and branches position, and grow as per space colonization algorithm
#pragma once

#include<vector>
#include"branch.h"
#include"leaf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <windows.h>
#include <direct.h>
#include <gl/gl.h>
#include <gl/glu.h>

using namespace std;

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


#endif // TREE_H
