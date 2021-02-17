#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "task_manager.h"
#include "input_output.h"
#include "ui_mainwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;


private slots:
    void on_move_clicked();
    void on_scale_clicked();
    void on_rotate_clicked();
    void on_LoadFile_clicked();
};

int draw_action(Ui::MainWindow* ui);
int change_task(request req, Ui::MainWindow* ui);

#endif // MAINWINDOW_H
