#ifndef REQUEST_H
#define REQUEST_H

#include "vector.h"
#include "line3d.h"


//struct LoadRequest
//{
//    const char *name;
//};


struct GetRequest
{
    void **model3d;
};


struct TranslateRequest
{
    Vector3D vec;
};


//struct RotateRequest
//{
//    Axis axis;
//    int angle;
//};


//struct ScaleRequest
//{
//    Point center;
//    Vector3D vec;
//};


struct DrawRequest
{
    QVector<Line> *lines;
};


union Request
{
    GetRequest get;
    TranslateRequest translate;
//    ScaleRequest scale;
//    RotateRequest rotate;
    DrawRequest draw;
};


#endif // REQUEST_H
