#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <Qt3DCore/QEntity>
#include <QtWidgets/QHBoxLayout>
#include "panel.h"
#include "view3d.h"
#include "event_handler.h"


class Widget : public QWidget
{
    EventHandler event;
public:
    Widget();
    ~Widget();
};


#endif // WIDGET_H
