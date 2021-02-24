#include "widget.h"


Widget::Widget()
{
    auto *rootEntity = new Qt3DCore::QEntity();

    auto *hLayout = new QHBoxLayout(this);

    auto *panel = new Panel();

    auto *view = new View3d(rootEntity);

    auto *container = QWidget::createWindowContainer(view);
    container->setMinimumSize(QSize(800, 600));

    hLayout->addWidget(panel);
    hLayout->addWidget(container, 1);

    // Scenemodifier
    Qt3DCore::QEntity *obj;
    model_handler(GET, (Request){ .get = {(void **)&obj} });
    obj->setParent(rootEntity);

    // Create control widgets
    QObject::connect(panel->xSlider, &QSlider::valueChanged, &event, &EventHandler::transX);
    QObject::connect(panel->ySlider, &QSlider::valueChanged, &event, &EventHandler::transY);
    QObject::connect(panel->zSlider, &QSlider::valueChanged, &event, &EventHandler::transZ);

    QObject::connect(panel->button, &QPushButton::clicked, &event, &EventHandler::draw);
}

Widget::~Widget()
{
//    QWidget::~QWidget();
}
