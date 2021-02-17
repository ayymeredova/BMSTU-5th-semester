#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "structures.h"
#include "errors.h"
#include <math.h>

void move_one_point(point& one_point, move coeff);
int move_array_points(frame_model& object, move coeff);
void scale_one_point(point& one_point, scale coeff);
int scale_array_points(frame_model& object, scale coeff);
double cosinus (double angle);
double sinus (double angle);
void rotate_ox(point& one_point, double angle);
void rotate_oy(point& one_point, double angle);
void rotate_oz(point& one_point, double angle);
int rotate_array_points(frame_model& object, rotate coeff);

#endif // OPERATIONS_H
