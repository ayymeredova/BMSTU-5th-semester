#ifndef BRANCH_H
#define BRANCH_H

#include "leaf.h"
#include <stddef.h>
#include <string.h>
#include <windows.h>
#include <direct.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <qvector3d.h>
class Branch{
private:
    float x, y,z;				// x, y coordinates for starting of branch segment
    QVector3D origDir;		// Container for original growth direction of branch segment along (x,y) axes
    QVector3D growthDir;	// Container for growth direction influenced by nearest leaves
    Branch *parent;				// Pointer to parent of the branch
    int nearestLeafCount;		// No. of nearest leaves to avg. over their contribution to its growth direction


public:
    Branch() {};
    Branch(float x_, float y_, float z_, QVector3D growthDir_, Branch *parent_);


    void getBasePos(float& x_, float& y_, float& z_);
    void setDir(QVector3D dir_);
    QVector3D getDir();
    int getCount();
    void incrementCount();
    void reset();


    void draw();
    Branch* next();
    Branch* getParent(){ return this->parent;}
};



#endif // BRANCH_H
