#include "vector.h"


void VecVector3D_init(VecVector3D &v)
{
    v.size = 0;
    v.capacity = 0;
    v.arr = nullptr;
}


void VecVector3D_free(VecVector3D &v)
{
    free(v.arr);
}


Error_t add_vector3D(VecVector3D &v, Vector3D p)
{
    if (v.size == v.capacity)
    {
        if (!v.capacity) v.capacity = 1;

        Vector3D *tmp = (Vector3D *)realloc(v.arr, v.capacity * 2 * sizeof(Vector3D));
        if (tmp)
        {
            v.capacity *= 2;
            v.arr = tmp;
        }
        else
        {
            return ERR_MEM;
        }
    }

    if (v.size < v.capacity)
        v.arr[v.size++] = p;

    return OK;
}


float vector4D_multiply(Vector4D &a, Vector4D &b)
{
    float sum = 0;
    sum += a.x * b.x;
    sum += a.y * b.y;
    sum += a.z * b.z;
    sum += a.s * b.s;
    return sum;
}
