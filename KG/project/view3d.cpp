#include "view3d.h"


View3d::View3d(Qt3DCore::QEntity *rootEntity)
{
    Qt3DRender::QCamera *cameraEntity = this->camera();


    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0, 0, 20.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));


    // Camera controls
    auto *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setCamera(cameraEntity);


    // Set root object of the scene
    this->setRootEntity(rootEntity);
}
