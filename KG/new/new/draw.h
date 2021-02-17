#ifndef DRAW_H
#define DRAW_H

#include "init_scene.h"
#include "structures.h"

void my_addLine(graphics_scene frame, point cur_point1, point cur_point2);
link get_link(link *arr, int index);
point get_point(point *arr, int index);
void draw_object( frame_model& object, graphics_scene frame, point x, int len, double angle );

#endif // DRAW_H
