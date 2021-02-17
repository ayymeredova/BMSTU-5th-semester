#ifndef FRAME_H
#define FRAME_H


#include <stdbool.h>
#include "arr_point.h"
#include "arr_link.h"



/*
Функция создаёт окно.
Параметры:
    char *points_filename - строка, содержащая название файла с координатами точек.
    char *links_filename - строка, содержащая название файла со значениями узлов.
    frame_t *frame - структура окна.
*/
void create_frame(char *points_filename, char *links_filename, frame_t *frame);

/*
Функция освобождает память из-под структуры окна.
Параметры:
    frame_t *frame - структура окна.
*/
void free_frame(frame_t *frame);


/*
Функция переноса точек окна.
Параметры:
    frame_t *frame - структура окна.
    double dX - смещение  точки по Х
    double dY - смещение  точки по Y
    double dZ - смещение  точки по Z
*/
void move_frame(frame_t *frame, double dX, double dY, double dZ);

/*
Функция масштабирования точек окна.
Параметры:
    frame_t *frame - структура окна.
    double centerX - центр масштабирования Х
    double centerY - центр масштабирования Y
    double centerZ - центр масштабирования Z
    double kx - коэффициент масштабирования по Х
    double ky - коэффициент масштабирования по Y
    double kz - коэффициент масштабирования по Z

*/
void scale_frame(frame_t *frame, double centerX, double centerY, double centerZ, double kx, double ky, double kz);

/*
Функция поворота точек окна.
Параметры:
table_t *coor - таблица точек
double centerX - центр поворота Х
double centerY - центр поворота Y
double centerZ - центр поворота Z
double angleX - угол поворота по Х
double angleY - угол поворота по Y
double angleZ - угол поворота по Z
*/
void rotate_frame(frame_t *frame, double centerX, double centerY, double centerZ, double angleX, double angleY, double angleZ);

#endif // FRAME_H
