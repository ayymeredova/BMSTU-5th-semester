#include "frame.h"

void  create_frame(char *points_filename, char *links_filename, frame_t *frame)
{
    int rc = OK;
    frame->init = false;
    rc = read_point_arr(points_filename, &frame->points);
    if (rc == OK)
    {
        rc = read_link_arr(links_filename, &frame->links);
        if (rc == OK)
            frame->init = true;
    }
}


void free_frame(frame_t *frame)
{
    free_table_points(&frame->points);
    free_links(&frame->links);
}



void move_frame(frame_t *frame, double dX, double dY, double dZ)
{
    if (frame->init)
    {
        move_points(&frame->points, dX, dY, dZ);
    }
}

void scale_frame(frame_t *frame, double centerX, double centerY, double centerZ, double kx, double ky, double kz)
{
    if (frame->init)
    {
        scale_points(&frame->points, centerX, centerY, centerZ, kx, ky, kz);
    }
}

void rotate_frame(frame_t *frame, double centerX, double centerY, double centerZ, double angleX, double angleY, double angleZ)
{
    if (frame->init)
    {
        rotate_points(&frame->points, centerX, centerY, centerZ, angleX, angleY, angleZ);
    }
}
