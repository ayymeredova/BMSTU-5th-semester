#include "model3d.h"


Model3D *model3d_init()
{
    Model3D *m = new Model3D();

    m->mesh = new Qt3DCore::QEntity(m);

    auto material = new Qt3DExtras::QPhongAlphaMaterial(m);
    material->setAmbient(Qt::lightGray);
    material->setShininess(40);
    material->setAlpha(0.5);

    m->transform = new Qt3DCore::QTransform;
    m->transform->setScale(0.075);
    m->transform->setTranslation(QVector3D(0,-7,0));

    Qt3DRender::QMesh * mesh = new Qt3DRender::QMesh();
    mesh->setSource(QUrl::fromLocalFile(OBJ_FULL_PATH));

    m->mesh->addComponent(mesh);
    m->mesh->addComponent(m->transform);
    m->mesh->addComponent(material);

    return m;
}


Error_t get_model(Model3D &m, GetRequest r)
{
    *(r.model3d) = &m;
    return OK;
}

