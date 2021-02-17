/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *DeltaX;
    QLineEdit *DeltaY;
    QLineEdit *DeltaZ;
    QLabel *label;
    QPushButton *move;
    QLabel *label_2;
    QLineEdit *ScaleX;
    QLineEdit *ScaleY;
    QLineEdit *ScaleZ;
    QPushButton *scale;
    QLabel *label_3;
    QLineEdit *RotAngleX;
    QLineEdit *RotAngleY;
    QLineEdit *RotAngleZ;
    QPushButton *rotate;
    QGraphicsView *graphicsView;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *LoadFile;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1305, 644);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        DeltaX = new QLineEdit(centralwidget);
        DeltaX->setObjectName(QString::fromUtf8("DeltaX"));
        DeltaX->setGeometry(QRect(20, 90, 113, 22));
        DeltaY = new QLineEdit(centralwidget);
        DeltaY->setObjectName(QString::fromUtf8("DeltaY"));
        DeltaY->setGeometry(QRect(150, 90, 113, 22));
        DeltaZ = new QLineEdit(centralwidget);
        DeltaZ->setObjectName(QString::fromUtf8("DeltaZ"));
        DeltaZ->setGeometry(QRect(280, 90, 113, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 101, 31));
        move = new QPushButton(centralwidget);
        move->setObjectName(QString::fromUtf8("move"));
        move->setGeometry(QRect(160, 140, 93, 28));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 160, 121, 21));
        ScaleX = new QLineEdit(centralwidget);
        ScaleX->setObjectName(QString::fromUtf8("ScaleX"));
        ScaleX->setGeometry(QRect(10, 240, 113, 22));
        ScaleY = new QLineEdit(centralwidget);
        ScaleY->setObjectName(QString::fromUtf8("ScaleY"));
        ScaleY->setGeometry(QRect(180, 240, 113, 22));
        ScaleZ = new QLineEdit(centralwidget);
        ScaleZ->setObjectName(QString::fromUtf8("ScaleZ"));
        ScaleZ->setGeometry(QRect(350, 240, 113, 22));
        scale = new QPushButton(centralwidget);
        scale->setObjectName(QString::fromUtf8("scale"));
        scale->setGeometry(QRect(130, 280, 161, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 330, 111, 21));
        RotAngleX = new QLineEdit(centralwidget);
        RotAngleX->setObjectName(QString::fromUtf8("RotAngleX"));
        RotAngleX->setGeometry(QRect(10, 390, 113, 22));
        RotAngleY = new QLineEdit(centralwidget);
        RotAngleY->setObjectName(QString::fromUtf8("RotAngleY"));
        RotAngleY->setGeometry(QRect(180, 390, 113, 22));
        RotAngleZ = new QLineEdit(centralwidget);
        RotAngleZ->setObjectName(QString::fromUtf8("RotAngleZ"));
        RotAngleZ->setGeometry(QRect(350, 390, 113, 22));
        rotate = new QPushButton(centralwidget);
        rotate->setObjectName(QString::fromUtf8("rotate"));
        rotate->setGeometry(QRect(160, 430, 93, 28));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(690, 50, 571, 501));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 60, 101, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 60, 101, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(290, 60, 101, 21));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 200, 141, 41));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(170, 210, 141, 31));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(340, 200, 141, 41));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 370, 121, 16));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(180, 370, 121, 16));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(350, 370, 121, 16));
        LoadFile = new QPushButton(centralwidget);
        LoadFile->setObjectName(QString::fromUtf8("LoadFile"));
        LoadFile->setGeometry(QRect(100, 510, 171, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1305, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        move->setText(QCoreApplication::translate("MainWindow", "\320\237\320\225\320\240\320\225\320\235\320\236\320\241", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        scale->setText(QCoreApplication::translate("MainWindow", "\320\234\320\220\320\241\320\250\320\242\320\220\320\221\320\230\320\240\320\236\320\222\320\220\320\235\320\230\320\225", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        rotate->setText(QCoreApplication::translate("MainWindow", "\320\237\320\236\320\222\320\236\320\240\320\236\320\242", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \320\277\320\276 \320\245:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \320\277\320\276 Y:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \320\277\320\276 Z:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204. \320\274\320\260\321\201\321\210\321\202-\320\275\320\270\321\217 \320\277\320\276 \320\245:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204. \320\274\320\260\321\201\321\210\321\202-\320\275\320\270\321\217 \320\277\320\276 Y:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204. \320\274\320\260\321\201\321\210\321\202-\320\275\320\270\321\217 \320\277\320\276 Z:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\321\202\320\260 \320\277\320\276 X:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\321\202\320\260 \320\277\320\276 Y:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\321\202\320\260 \320\277\320\276 Z:", nullptr));
        LoadFile->setText(QCoreApplication::translate("MainWindow", "\320\237\320\236\320\241\320\242\320\240\320\236\320\230\320\242\320\254 \320\234\320\236\320\224\320\225\320\233\320\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
