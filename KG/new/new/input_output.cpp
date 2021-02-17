#include "input_output.h"

int read_count(int *count, FILE *f)
{
    int rc = OK;
    int tmp_count = 0;
    if(fscanf(f, "%d", &tmp_count) != 1)
        rc = ERR_IO;
    if(tmp_count <= 0)
        rc = ERR_RANGE;
    if(rc == OK)
        *count = tmp_count;
    return rc;
}




int read_arr_points(point *arr, int count, FILE *f)
{
    int rc = OK;
    for (int i = 0; i < count && rc == OK; i++)
    {

        if (fscanf(f, "%lf%lf%lf", &arr[i].x, &arr[i].y, &arr[i].z) != 3)
            rc = ERR_IO;
    }
    return rc;
}



int read_arr_links(link *arr, int count, FILE *f)
{
    int rc = OK;
    for(int i = 0; i < count && rc == OK; i++)
    {
        if(fscanf(f, "%d%d", &arr[i].start, &arr[i].end) != 2)
            rc = ERR_IO;
    }
    return rc;
}



int alloc_data_points(data_points& tmp_points, int count)
{
    tmp_points.count = count;
    tmp_points.arr = new point[count];
    if(!tmp_points.arr)
        return ERR_MEM;
    return OK;
}



void free_data_points(data_points& tmp_points)
{
    tmp_points.count= 0;
    if(tmp_points.arr)
        delete []tmp_points.arr;
}



int alloc_data_links(data_links& tmp_links, int count)
{
    tmp_links.count = count;
    tmp_links.arr = new link[count];
    if (!tmp_links.arr)
        return ERR_MEM;
    return OK;
}





void free_data_links(data_links& tmp_links)
{
    tmp_links.count = 0;
    if(tmp_links.arr)
        delete [] tmp_links.arr;
}





void free_model(frame_model& model)
{
    free_data_points(model.points);
    free_data_links(model.links);
}


int load_data_points(data_points& tmp_points, FILE *f)
{
    int tmp_count = 0;
    int rc = OK;
    rc = read_count(&tmp_count, f);
    if(rc == OK)
    {
        rc = alloc_data_points(tmp_points, tmp_count);
        if(rc == OK)
        {
            rc = read_arr_points(tmp_points.arr, tmp_points.count, f);
            if(rc != OK)
            {
                free_data_points(tmp_points);
            }
        }
    }
    return rc;
}




int load_data_links(data_links& tmp_links, FILE *f)
{
    int tmp_count = 0;
    int rc = OK;

    rc = read_count(&tmp_count, f);

    if(rc == OK)
    {
        rc = alloc_data_links(tmp_links, tmp_count);
        if(rc == OK)
        {
            rc = read_arr_links(tmp_links.arr, tmp_links.count, f);
            if(rc != OK)
            {
                free_data_links(tmp_links);
            }
        }
    }
    return rc;
}


