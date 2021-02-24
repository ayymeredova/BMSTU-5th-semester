#include "panel.h"


QSlider *initSlider(int interval, int min, int max)
{
    auto s = new QSlider(Qt::Horizontal);
    s->setTickPosition(QSlider::TicksBothSides);
    s->setTickInterval(interval);
    s->setSingleStep(1);
    s->setRange(min, max);
    return s;
}


Panel::Panel()
{
    xSlider = initSlider(10, -10, 10);
    ySlider = initSlider(10, -17, 3);
    zSlider = initSlider(10, -10, 10);

    button = new QPushButton("Draw", this);

    auto *transLb = new QLabel("Translate");

    auto *vLayout = new QVBoxLayout(this);

    vLayout->addWidget(transLb);
    vLayout->addWidget(xSlider);
    vLayout->addWidget(ySlider);
    vLayout->addWidget(zSlider);
    vLayout->addSpacing(50);
    vLayout->addWidget(button);

    vLayout->setAlignment(Qt::AlignTop);

    reset();
}


void Panel::reset()
{
    this->blockSignals(true);
    xSlider->setValue(0);
    ySlider->setValue(-7);
    zSlider->setValue(0);
    this->blockSignals(false);
}
