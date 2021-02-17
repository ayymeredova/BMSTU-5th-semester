#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "structures.h"
#include "input_output.h"
#include "model.h"
#include "operations.h"

enum task
{
    LOAD_FILE,
    DRAW_MODEL,
    MOVE_MODEL,
    SCALE_MODEL,
    ROTATE_MODEL,
    FREE_MODEL,
    UNKNOWN_COMMAND
};



typedef struct{
    task t;
        const char* filename_points;
        const char* filename_links;
        graphics drawing;
        move moving;
        scale scaling;
        rotate rotating;

}request;


int task_manager(request req);



#endif // TASK_MANAGER_H
