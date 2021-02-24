#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "model_handler.h"
#include <QObject>


class EventHandler : public QObject
{
    Q_OBJECT

public slots:
    void transX(int);
    void transY(int);
    void transZ(int);
    void draw(bool);

private:
    const char *name;
    Request r;
    Vector3D vTranslate { 0, 0, 0 };
    void translate();
};

#endif // EVENTHANDLER_H
