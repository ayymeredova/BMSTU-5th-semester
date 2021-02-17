#include "operations.h"

void move_one_point(point& one_point, move coeff)
{
    one_point.x += coeff.dx;
    one_point.y += coeff.dy;
    one_point.z += coeff.dz;
}

int move_array_points(frame_model& object, move coeff)
{
    data_points points = object.points;
    if(!points.arr)
        return ERR_EMPTY;
    for(int i = 0; i < points.count; i++)
        move_one_point(points.arr[i], coeff);

    return OK;
}

void scale_one_point(point& one_point, scale coeff)
{
    one_point.x *= coeff.kx;
    one_point.y *= coeff.ky;
    one_point.z *= coeff.kz;
}

int scale_array_points(frame_model& object, scale coeff)
{
    data_points points = object.points;

    if(!points.arr)
        return ERR_EMPTY;

    for(int i = 0; i < points.count; i++)
        scale_one_point(points.arr[i], coeff);

    return OK;
}


double cosinus (double angle)
{
    return (cos(angle * M_PI/180));
}


double sinus (double angle)
{
    return (sin(angle * M_PI/180));
}


void rotate_ox(point& one_point, double angle)
{
    double cos_angle = cosinus(angle);
    double sin_angle = sinus(angle);

    one_point.y = one_point.y + cos_angle + one_point.z * sin_angle;
    one_point.z = -one_point.y * sin_angle + one_point.z * cos_angle;
}


void rotate_oy(point& one_point, double angle)
{
    double cos_angle = cosinus(angle);
    double sin_angle = sinus(angle);

    one_point.x = one_point.x + cos_angle + one_point.z * sin_angle;
    one_point.z = -one_point.x * sin_angle + one_point.z * cos_angle;

}


void rotate_oz(point& one_point, double angle)
{
    double cos_angle = cosinus(angle);
    double sin_angle = sinus(angle);

    one_point.x = one_point.x + cos_angle + one_point.y * sin_angle;
    one_point.y = -one_point.x * sin_angle + one_point.y * cos_angle;
}



int rotate_array_points(frame_model& object, rotate coeff)
{
    data_points tmp_points = object.points;
    if (!tmp_points.arr)
        return ERR_EMPTY;
    for(int i = 0; i < tmp_points.count; i++)
    {
        rotate_ox(tmp_points.arr[i], coeff.ox);
        rotate_oy(tmp_points.arr[i], coeff.oy);
        rotate_oz(tmp_points.arr[i], coeff.oz);
    }

    return OK;
}
