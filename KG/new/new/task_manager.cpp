#include "task_manager.h"


int task_manager(request req)
{
    int error = OK;
    static frame_model model = init_model();
    switch(req.t)
    {
    case LOAD_FILE:
        error = load_model(model, req.filename_points, req.filename_links);
        break;
    case DRAW_MODEL:
        error = draw_model(model, req.drawing);
        break;
    case MOVE_MODEL:
        error = move_model(model, req.moving);
        break;
    case SCALE_MODEL:
        error = scale_model(model, req.scaling);
        break;
    case ROTATE_MODEL:
        error = rotate_model(model, req.rotating);
        break;
    case FREE_MODEL:
        free_model(model);
        break;
    default:
        error = UNKNOWN_COMMAND;
    }
    return error;
}
