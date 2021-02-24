#ifndef PANEL_H
#define PANEL_H

#include <QObject>
#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

class Panel : public QWidget
{
    Q_OBJECT

public:
    Panel();
    void reset();
    QSlider *xSlider, *ySlider, *zSlider;
    QPushButton *button;
};


#endif // PANEL_H
