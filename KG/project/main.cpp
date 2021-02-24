#include "widget.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.setWindowTitle("CG project");
    w.resize(800, 500);
    w.show();

    return a.exec();
}
