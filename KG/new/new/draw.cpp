#include "draw.h"

void my_addLine(graphics_scene frame, point cur_point1, point cur_point2)
{
    frame.scene -> addLine(cur_point1.x, cur_point1.y, cur_point2.x, cur_point2.y);
}

link get_link(link *arr, int index)
{
    link current;
    current.start = arr[index].start;
    current.end = arr[index].end;

    return current;
}

point get_point(point *arr, int index)
{
    point current;
    current.x = arr[index].x;
    current.y = arr[index].y;

    return current;
}

void draw_object(frame_model& object, graphics_scene frame)
{
    int start = 0, end = 0;
    data_points points = object.points;
    data_links links = object.links;

    for(int i = 0; i < links.count; i++)
    {
        link current_link;
        point cur_point1, cur_point2;

        current_link = get_link(links.arr, i);
        start = current_link.start;
        end = current_link.end;

        cur_point1 = get_point(points.arr, start);
        cur_point2 = get_point(points.arr, end);

        my_addLine(frame, cur_point1, cur_point2);
    }
//    int x, y, len;
//    double angle;

//    x = 400;
//    y = 400;
//    angle = 40;
//    point x1;
//    x1.x = x.x + len*sin(angle * M_PI*2 / 360.0);
//    x1.y = x.y + len*cos(angle + M_PI*2/360.0);
//    x1.x = int(x1.x);
//    x1.y = int(x1.y);
//    my_addLine(frame, x, x1);
//    if(len > 3)
//    {
//        draw_object(object, frame, x1, len/2, angle+30);
//        draw_object(object, frame, x1, len/2, angle-30);
//    }

}





