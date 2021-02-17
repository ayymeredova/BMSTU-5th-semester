#include "arr_point.h"

int read_count(FILE *f, int *count)
{
    int rc = NOT_CHANGE;
    if (f)
    {
        if (fscanf(f, "%d", count) == 1)
            rc = OK;
        else
            rc = ERR_IO;
    }
    else
        rc = ERR_FILE;
    return rc;
}


point_t* alloc_table_points(FILE *f, table_t *coor)
{
    point_t* arr = nullptr;
    int rc = read_count(f, &(coor->count));
    if (rc == OK)
        arr = new point_t[coor->count];
    return arr;

}


int read_point_arr(char *filename, table_t *coor)
{
    int rc = OK;
    FILE *f;
    f = fopen(filename, "r");
    if (f)
    {
        coor->arr = alloc_table_points(f, coor);
        if (coor->arr)
        {
            for(int i = 0; i < coor->count && rc == OK; i++)
                rc = read_one_point(f, &(coor->arr[i]));
        }
        else
            rc = ERR_MEM;

        fclose(f);
    }
    return rc;

}



void move_points(table_t *coor, double dx, double dy, double dz)
{
    for (int i = 0; i < coor->count; i++)
        move(&(coor->arr[i]), dx, dy, dz);
}




void scale_points(table_t *coor, double centerX, double centerY, double centerZ, double kx, double ky, double kz)
{
    for (int i = 0; i < coor->count; i++)
        scale(&(coor->arr[i]), centerX, centerY, centerZ, kx, ky, kz);

}



void rotate_points(table_t *coor, double centerX, double centerY, double centerZ, double angleX, double angleY, double angleZ)
{
    for(int i = 0; i < coor->count; i++)
        rotate(&(coor->arr[i]), centerX, centerY, centerZ, angleX, angleY, angleZ);

}


//osvobojedniye pamyati
void free_table_points(table_t *coor)
{
    if (coor->count != 0)
    {
        delete [] coor->arr;
        coor->count = 0;
    }

}





