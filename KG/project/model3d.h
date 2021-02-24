#ifndef MODEL3D_H
#define MODEL3D_H

#include <QObject>
#include <Qt3DRender>
#include <Qt3DExtras>
#include <QVector3D>
#include "line3d.h"
#include "error.h"
#include "request.h"
#include "custom_struct.h"

#define OBJ_FULL_PATH "C:/Users/Owadan/Desktop/2/man.obj"


class Model3D : public Qt3DCore::QEntity
{
public:
    Qt3DCore::QTransform *transform;
    Qt3DCore::QEntity *mesh;
};


Model3D *model3d_init();

Error_t get_model(Model3D &m, GetRequest r);

#endif // MODEL3D_H
