#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->DeltaX->setText("10");
    ui->DeltaY->setText("20");
    ui->DeltaZ->setText("0");
    ui->ScaleX->setText("2");
    ui->ScaleY->setText("2");
    ui->ScaleZ->setText("2");
    ui->RotAngleX->setText("10");
    ui->RotAngleY->setText("20");
    ui->RotAngleZ->setText("5");


}


MainWindow::~MainWindow()
{
    delete ui;
}


int draw_action(Ui::MainWindow* ui)
{
    request req;
    req.t = DRAW_MODEL;
    graphics dr;
    dr.gV = ui->graphicsView;
    req.drawing = dr;

    int error = (int) task_manager(req);
    return error;
}



int change_task(request req, Ui::MainWindow* ui)
{
    int error = (int) task_manager(req);
    if(error)
        return error;
    else
        error = draw_action(ui);
    return error;
}


void MainWindow::on_move_clicked()
{
    request req;
    req.t = MOVE_MODEL;
    req.moving.dx = ui->DeltaX->text().toFloat();
    req.moving.dy = ui->DeltaY->text().toFloat();
    req.moving.dz = ui->DeltaZ->text().toFloat();

    int error = change_task(req, ui);
    if(error)
        error_mess(error);

}


void MainWindow::on_scale_clicked()
{
    request req;
    req.t = SCALE_MODEL;
    req.scaling.kx = ui->ScaleX->text().toFloat();
    req.scaling.ky = ui->ScaleY->text().toFloat();
    req.scaling.kz = ui->ScaleZ->text().toFloat();

    int error = change_task(req, ui);
    if(error)
        error_mess(error);
}


void MainWindow::on_rotate_clicked()
{
    request req;
    req.t = ROTATE_MODEL;
    req.rotating.ox = ui->RotAngleX->text().toFloat();
    req.rotating.oy = ui->RotAngleY->text().toFloat();
    req.rotating.oz = ui->RotAngleZ->text().toFloat();

    int error = change_task(req, ui);
    if(error)
        error_mess(error);

}

void MainWindow::on_LoadFile_clicked()
{
    request req;
    req.t = LOAD_FILE;
    req.filename_points = "coord.txt";
    req.filename_links = "link.txt";

    int error = change_task(req, ui);
    if(error)
        error_mess(error);

}
