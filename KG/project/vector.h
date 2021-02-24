#ifndef VECTOR_H
#define VECTOR_H

#include "error.h"
#include <cstdio>
#include <cstdlib>


struct Vector3D
{
    float x, y, z;
};

struct Vector4D
{
    float x, y, z, s;
};

struct VecVector3D
{
    Vector3D *arr;  // = nullptr;
    int size;       // = 0;
    int capacity;
};


void VecVector3D_init(VecVector3D &v);

void VecVector3D_free(VecVector3D &v);

Error_t add_vector3D(VecVector3D &v, Vector3D p);

float vector4D_multiply(Vector4D &a, Vector4D &b);


#endif // VECTOR_H
