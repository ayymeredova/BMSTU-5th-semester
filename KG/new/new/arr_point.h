#ifndef ARR_POINT_H
#define ARR_POINT_H


#include "one_point.h"
#include <stdlib.h>
#include <stdio.h>
#include "err.h"





/*
Функция считывания количества точек. Возвращает целочисленый код ошибки
параметры:
FILE *f - файловый указатель
int *count - количество точек
*/
int read_count(FILE *f, int *count);

/*
Функция считывания таблицы точек. Возвращает целочисленный код ошибки.
Параметры:
char *filename - строка, содержащая название файла
table_t *coor - таблица точек
*/
int read_point_arr(char *filename, table_t *coor);

/*
 Функция выделения динамической памяти под таблицу точек. Возвращает указатель на массив точек
 Параметры:
 FILE *f - файловый указатель.
 table_t* coor - таблица точек.

*/
point_t* alloc_table_points(FILE *f, table_t* coor);


/*
Функция переноса точек.
Параметры:
table_t *coor - таблица точек
double dX - смещение  точки по Х
double dY - смещение  точки по Y
double dZ - смещение  точки по Z

*/
void move_points(table_t *coor, double dx, double dy, double dz);


/*
Функция масштабирования точек.
Параметры:
table_t *coor -  таблица точек
double centerX - центр масштабирования Х
double centerY - центр масштабирования Y
double centerZ - центр масштабирования Z
double kx - коэффициент масштабирования по Х
double ky - коэффициент масштабирования по Y
double kz - коэффициент масштабирования по Z
*/
void scale_points(table_t *coor, double centerX, double centerY, double centerZ, double kx, double ky, double kz);


/*
Функция поворота точек.
Параметры:
table_t *coor - таблица точек
double centerX - центр поворота Х
double centerY - центр поворота Y
double centerZ - центр поворота Z
double angleX - угол поворота по Х
double angleY - угол поворота по Y
double angleZ - угол поворота по Z
*/
void rotate_points(table_t *coor, double centerX, double centerY, double centerZ, double angleX, double angleY, double angleZ);


/*
Функция освобождения памяти из-под таблицы точек.
Параметры:
    table_t *coor - таблица точек
*/
void free_table_points(table_t* coor);


#endif // ARR_POINT_H
