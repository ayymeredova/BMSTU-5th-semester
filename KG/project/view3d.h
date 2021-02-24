#ifndef VIEW3D_H
#define VIEW3D_H

#include "line3d.h"
#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3DExtras>


class View3d : public Qt3DExtras::Qt3DWindow
{
public:
    View3d(Qt3DCore::QEntity *rootEntity);
};

#endif // VIEW3D_H
