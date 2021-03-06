// Code containing bodies of functions declared in the 'Tree.h' header file

#include<iostream>
#include<math.h>
//#include"fssimplewindow.h"
#include"leaf.h"
#include "tree.h"

using namespace std;

// Parameterized constructor for tree
Tree::Tree(int minDist_, int maxDist_, double width, double height)
{
    // Sets dimensions of graphics window
    winWidth = width; winHeight = height;

    // Sets values of distance bounds
    minDist = minDist_; maxDist = maxDist_;

// Specifies number of leaf objects (points) to be displayed & colonized
    numLeaves = 400;    //
    allLeaves.resize(numLeaves, Leaf());

    for (int i = 0; i < numLeaves; i++) {
        allLeaves[i] = Leaf();
    }

    // Sets 'parent' of 'root' branch to null since root has no 'parent'
    Branch *ptr = nullptr;
    QVector3D rootDir = {0, 1, 0};
    root = new Branch(winWidth/2, 0.,0., rootDir, ptr);

    // Add root to 'branches' vector
    branches.push_back(root);

    double dist;	// Variable for storing distance between a branch segment base & a leaf
    bool foundLeaf = false;		// Flag for indicating whether a leaf lies between the max & min dist. bounds
    Branch *current;		// Creates a branch object for keeping track of current branch of tree
    current = root;		// Sets current branch to root at the beginning

    //cout << "Copied root to current" << endl;

    // Coords for leaf & branch objects
    int leafX, leafY, leafZ;
    float branchX, branchY, branchZ;

    // Checking for distance of current branch with each leaf since the
    // branch continues to grow unaffected until gets close enough to a leaf
    while (!foundLeaf) {
        for (int i = 0; i < allLeaves.size(); i++) {
            allLeaves[i].getPos(leafX, leafY, leafZ);
            current->getBasePos(branchX, branchY, branchZ);

            dist = sqrt((branchX - leafX)*(branchX - leafX) + (branchY - leafY)*(branchY - leafY) + (branchZ - leafZ)*(branchZ - leafZ));
            if (dist < double(maxDist_))
                foundLeaf = true;
        }

        // If branch did not find any leaf within distance bounds
        if (!foundLeaf) {
            Branch *newBranch = current->next();
            branches.push_back(newBranch);	// Add branch to branches vector
            current = newBranch;			// Set the newBranch as the current branch
        }
    }
}


// Function defining how the tree will grow once a branch gets within a certain distance of a leaf
void Tree::grow()
{
    // TEMP
    Branch *nextBranch;
    float x, y, z;

    int leafX, leafY, leafZ;			// Coords for leaf
    float branchX, branchY, branchZ;	// Coords for base of branch
    float dist, closestDist;	// Store distance between leaf & branch, closest distance for a leaf
    Branch *closestBranch;
    // Iterating over all leaves
    for (int i = 0; i < allLeaves.size(); i++) {
        closestDist = 1000;					// Initial dummy value for closeset distance for a leaf
        closestBranch = nullptr;			// Initialize closest branch object to null
        allLeaves[i].getPos(leafX, leafY, leafZ);

        // Iterating over all branches to get the closest branch
        for (int j = 0; j < branches.size(); j++) {
            branches[j]->getBasePos(branchX, branchY, branchZ);
            dist = sqrt((branchX - leafX)*(branchX - leafX) + (branchY - leafY)*(branchY - leafY) + (branchZ - leafZ)*(branchZ - leafZ));

            // Sets flag for leaf to indicate that it's been reached by a branch & need not be displayed anymore
            if (dist < minDist) {
                allLeaves[i].setLeafReached();
                break;
            }
            // Ignores effect of leaf if it is too far away from a branch
            else if (dist > maxDist) { ; }
            // If leaf is within distance bounds of branch, it influences the growth direction of the branch
            else if (closestBranch == nullptr || dist < closestDist) {
                //cout << i << " " << dist << endl;
                QVector3D tempDir = branches[j]->getDir();
                //cout << branchX << " " << branchY << " " << tempDir[0] << " " << tempDir [1] << endl;
                closestBranch = branches[j];
                closestDist = dist;
            }
        }
        // If a closest branch to a leaf is found, its influence is added to direction of growth of branch
        if (closestBranch != nullptr) {
            closestBranch->getBasePos(branchX, branchY, branchZ);

            QVector3D closestDir = closestBranch->getDir();
            QVector3D newDir = {leafX - branchX, leafY - branchY, leafZ - branchZ};		// Vector from base of branch to leaf
            // Normalizing the direction to get unit vector for direction
            double newDirMag = sqrt(newDir[0] * newDir[0] + newDir[1] * newDir[1] + newDir[2] * newDir[2]);
            for (int j = 0; j < 3; j++) {
                newDir[j]/= newDirMag;
            }
            // Adding the vector influence by leaf to growth direction vector
            QVector3D resultantDir = {newDir[0] + closestDir[0], newDir[1] + closestDir[1], newDir[2] + closestDir[2]};
            closestBranch->setDir(resultantDir);
            closestBranch->incrementCount();
        }
    }
    // Deletes the leaves which are closer than lower distance bound to a branch
    for (int i = (int)allLeaves.size()-1; i >= 0; i--) {
        if(allLeaves[i].getLeafReached())
            allLeaves.erase(allLeaves.begin()+i);
    }

    // Adds new branch to existing branch if it has nearest leaves count > 0

    for (int j = (int)branches.size() - 1; j >= 0; j--) {
        if (branches[j]->getCount() > 0) {
            QVector3D nextDir = branches[j]->getDir();
            // Averaging contributions of various nearest leaves to growth direction of branch
            for (int k = 0; k < 3; k++) {
                nextDir[k]/= branches[j]->getCount();
            }
            branches[j]->setDir(nextDir);
            // Sets up new branch with direction influenced by leaves as obtained above
            nextBranch = branches[j]->next();
            branches.push_back(nextBranch);
            branches[j]->getParent()->getBasePos(x, y, z);
        }
        branches[j]->reset();
    }
}

void Tree::draw()
{
    for (int i = 0; i < allLeaves.size(); i++) {
        allLeaves[i].draw();
    }
    //cout << "Size of branches vector: " << branches.size() << endl;
    for (int j = 0; j < branches.size(); j++) {
        branches[j]->draw();
    }
}
