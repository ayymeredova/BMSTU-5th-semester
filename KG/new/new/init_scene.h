#ifndef INIT_SCENE_H
#define INIT_SCENE_H

#include "structures.h"
#include "errors.h"

int init(graphics_scene &a, QGraphicsView *gV);
void clear(graphics_scene &a);
void set(QGraphicsView *gv, graphics_scene &a);

#endif // INIT_SCENE_H
