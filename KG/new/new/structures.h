#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "QGraphicsView"


//model of human(пока не знаю)
//typedef struct{
//   head,
//   legs,
//   hands,
//   body
//}human;





//структура одной точки
typedef struct{
    double x;
    double y;
    double z;
}point;


//структура одной связи(узла)
typedef struct
{
    int start;
    int end;
}link;


//структура таблицы: состоит из массива точек(дин.) и их количества
typedef struct{
    point* arr;
    int count;
}data_points;


//структура массива связей(узлов)
typedef struct
{
    link *arr;   // массив связей
    int count;  // количество связей
}data_links;


// структура окна
typedef struct frame{
    data_points points;       // таблица точек.
    data_links links;        // таблица узлов.
}frame_model;



typedef struct{
    double dx;
    double dy;
    double dz;
}move;


typedef struct{
    double kx;
    double ky;
    double kz;
}scale;


typedef struct{
    double ox;
    double oy;
    double oz;
}rotate;


typedef struct{
    QGraphicsView *gV;
}graphics;


typedef struct{
    QGraphicsScene *scene;
}graphics_scene;



#endif // STRUCTURES_H
