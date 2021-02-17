#include "model.h"

data_points& init_points(void)
{
    static data_points tmp_points;
    tmp_points.count = 0;
    tmp_points.arr = NULL;
    return tmp_points;
}


data_links& init_links(void)
{
    static data_links tmp_links;
    tmp_links.count = 0;
    tmp_links.arr = NULL;
    return tmp_links;
}

frame_model& init_model(void)
{
    static frame_model model;

    model.points = init_points();
    model.links = init_links();

    return model;
}


void copy_points(data_points& object, data_points& tmp_points)
{
    object.count = tmp_points.count;
    object.arr = tmp_points.arr;
}


void copy_links(data_links& object, data_links& tmp_links)
{
    object.count = tmp_links.count;
    object.arr = tmp_links.arr;
}


void copy_model(frame_model& model, frame_model& tmp_model)
{
    copy_points(model.points, tmp_model.points);
    copy_links(model.links, tmp_model.links);
}


//zagruzka modeli
int load_model(frame_model& model, const char* file_points, const char* file_links)
{
    FILE *f_points = fopen(file_points, "r");
    if(!f_points)
        return ERR_FILE;

    FILE *f_links = fopen(file_links, "r");
    if (!f_links)
    {
        fclose(f_points);
        return ERR_FILE;
    }

    int rc = OK;
    frame_model tmp_model = init_model();
    rc = load_data_points(tmp_model.points, f_points);
    if(rc == OK)
    {
        rc = load_data_links(tmp_model.links, f_links);
        if(rc != OK)
        {
            free_data_points(tmp_model.points);
        }
    }
    fclose(f_points);
    fclose(f_links);


    if(rc == OK)
    {
        free_model(model); // osvobojdayem staroye;
        copy_model(model, tmp_model);
    }

    return rc;
}

//drawing_model
int draw_model(frame_model model, graphics arg)
{
    graphics_scene a;
    int error = init(a, arg.gV);
    if (error)
        return error;
    clear(a);
    draw_object(model, a);
    set(arg.gV, a);
    return error;
}


int move_model(frame_model& model, move coeff)
{
   return move_array_points(model, coeff);
}


int scale_model(frame_model& model, scale coeff)
{
    return scale_array_points(model, coeff);
}


int rotate_model(frame_model& model, rotate coeff)
{
    return rotate_array_points(model, coeff);
}


