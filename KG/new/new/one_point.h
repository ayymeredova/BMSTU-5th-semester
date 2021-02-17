#ifndef ONE_POINT_H
#define ONE_POINT_H


#include <stdlib.h>
#include <math.h>
#include "err.h"
#include <stdlib.h>
#include <stdio.h>


/*
Функция считывает одну точку.
Параметры:
    FILE *f - файловый указатель(не меняется)
    point_t *point - одна точка(меняется)
Возвращает целочисленный код ошибки.
*/
int read_one_point(FILE *f, point_t *point);

/*
Функция умножения матрицы преобразования на точку.
Параметры:
    double matrix[N][N] - матрица преобразования(не менется)
    point_t *point - точка(меняется)
*/
void configure_point(double matrix[N][N], point_t *point);

/*
Функция переноса одной точки.
Параметры:
point_t *point - точка(меняется)
double dx - коодината переноса по Х(не меняется)
double dy - коодината переноса по Y(не меняется)
double dz - коодината переноса по Z(не меняется)
*/
void move(point_t *point, double dx, double dy, double dz);

/*
Функция масштабирования точки
Параметры:
point_t *point - точка(не меняется)
double centerX - координата центра масштабирования по Х(не меняется)
double centerY - координата центра масштабирования по Y(не меняется)
double centerZ - координата центра масштабирования по Z(не меняется)
double kx - коэффициент масштабирования по Х(не меняется)
double ky - коэффициент масштабирования по Y(не меняется)
double kz - коэффициент масштабирования по Z(не меняется)
*/
void scale(point_t *point, double centerX, double centerY, double centerZ, double kx, double ky, double kz);

/*
Функция поворота точки.
Параметры:
point_t *point - точка(не меняется)
double centerX - координата центра поворота по Х(не меняется)
double centerY - координата центра поворота по Y(не меняется)
double centerZ - координата центра поворота по Z(не меняется)
double angleX - угол поворота по Х(не меняется)
double angleY - угол поворота по Y(не меняется)
double angleZ - угол поворота по Z(не меняется)
*/
void rotate(point_t *point, double centerX, double centerY, double centerZ, double angleX, double angleY, double angleZ);

/*
Функция печати одной точки.
Параметры:
point_t point - точка(не меняется)
*/
void print_point(point_t point);

#endif // ONE_POINT_H
