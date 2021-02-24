#ifndef MODEL_HANDLER_H
#define MODEL_HANDLER_H

#include "model3d.h"
#include <string.h>
#include "custom_struct.h"
#include <stddef.h>
#include <string.h>
#include <windows.h>
#include <direct.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "branch.h"
using namespace std;

enum Action
{
//    LOAD,
    GET,
    TRANSLATE,
    DRAW,
    ROTATE,
    SCALE,
//    APPLY,
//    FREE
};


Error_t model_handler(Action action, Request r);

QVector<QVector3D> read_points(const char *filename);


#endif // MODEL_HANDLER_H
