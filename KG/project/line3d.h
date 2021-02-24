#ifndef LINE3D_H
#define LINE3D_H

#include <Qt3DRender>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QPhongMaterial>
#include <QVector3D>

typedef QPair<QVector3D,QVector3D> Line;

void drawLines(const QVector<Line>& lines, Qt3DCore::QEntity *_rootEntity);
void drawLine(const QVector3D& start, const QVector3D& end, const QColor& color, Qt3DCore::QEntity *_rootEntity);


#endif // LINE3D_H
