#include "init_scene.h"

int init(graphics_scene &a, QGraphicsView *gV)
{
    a.scene = new QGraphicsScene (gV);
    if (!a.scene)
        return ERR_MEM;
    return OK;
}


void clear(graphics_scene &a)
{
    a.scene -> clear();
}

void set(QGraphicsView *gv, graphics_scene &a)
{
    gv -> setScene(a.scene);
}


