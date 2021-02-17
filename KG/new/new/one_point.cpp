#include "one_point.h"

int read_one_point(FILE *f, point_t *point)//(изменяемые, неизменяемы)
{
    int rc = OK;
    if (f)
    {
        if (fscanf(f, "%lf%lf%lf", &(point->x), &(point->y), &(point->z)) == 3) //!
            rc = OK;

        else
            rc = ERR_IO;
    }
    else
        rc = ERR_FILE;
    return rc;
}


void configure_point(double matrix[N][N], point_t *point)//статика не надо!
{
    double *vektor = new double [N];
//    vektor = point;
    vektor[0] = point->x;
    vektor[1] = point->y;
    vektor[2] = point->z;
    vektor[3] = point->w;

    double new_point[N];
    for(int i = 0;  i < N; i++)
        new_point[i] = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            new_point[i] += matrix[j][i] * vektor[j];
    }

    for (int i = 0; i < N; i++)
        vektor[i] = round(new_point[i]);
    point->x = vektor[0];
    point->y = vektor[1];
    point->z = vektor[2];
    point->w = vektor[3];
}


void move(point_t *point, double dx, double dy, double dz)
{
    double matrix_transf[N][N] = {{1, 0, 0, 0},
                                  {0, 1, 0, 0},
                                  {0, 0, 1, 0},
                                  {dx, dy, dz, 1}};
    configure_point(matrix_transf, point);

}



void scale(point_t *point, double centerX, double centerY, double centerZ, double kx, double ky, double kz)
{
    double matrix_transf[N][N]  = {{kx, 0, 0, 0},
                                   {0, ky, 0, 0},
                                   {0, 0, kz, 0},
                                   {(1 - kx) * centerX, (1 - ky) * centerY, (1 - kz) * centerZ, 1}};

    configure_point(matrix_transf, point);
}


void rotate(point_t *point, double centerX, double centerY, double centerZ, double angleX, double angleY, double angleZ)
{
    double cosinus;
    double sinus;

    //ox
    sinus = (double)(sin(angleX * M_PI/180));
    cosinus = (double)(cos(angleX *M_PI/180));

    double matrix_trans_x[N][N] = {{1, 0, 0, 0},
                                 {0, cosinus, -sinus, 0},
                                 {0, sinus, cosinus, 0},
                                 {0, (1-cosinus) * centerY - centerZ * sinus, centerY * sinus + (1 - cosinus) * centerZ, 1}};
    configure_point(matrix_trans_x, point);


    //oy

    sinus = (double)(sin(angleY * M_PI/180));
    cosinus = (double)(cos(angleY * M_PI / 180));

    double matrix_trans_y[N][N] = {{cosinus, 0, -sinus, 0},
                                   {0, 1, 0, 0},
                                   {sinus, 0, cosinus, 0},
                                   {(1-cosinus) * centerZ - centerX * sinus, 0, centerZ * sinus + (1-cosinus) * centerX , 1}};
    configure_point(matrix_trans_y, point);

    //oz
    sinus = (double)(sin(angleZ * M_PI/180));
    cosinus = (double)(cos(angleZ * M_PI / 180));

    double matrix_trans_z[N][N] = {{cosinus, -sinus, 0, 0},
                                   {sinus, cosinus, 0, 0},
                                   {0, 0, 1, 0},
                                   {(1 - cosinus) * centerX - centerY * sinus, centerX * sinus + (1-cosinus) * centerY, 0, 1}};
    configure_point(matrix_trans_z, point);
}


