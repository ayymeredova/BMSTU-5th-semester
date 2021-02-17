#ifndef MODEL_H
#define MODEL_H

#include "structures.h"
#include "errors.h"
#include "input_output.h"
#include "init_scene.h"
#include "draw.h"
#include "operations.h"

data_points& init_points(void);

data_links& init_links(void);

frame_model& init_model(void);

void copy_points(data_points& object, data_points& tmp_points);

void copy_links(data_links& object, data_links& tmp_links);

void copy_model(frame_model& model, frame_model& tmp_model);

int load_model(frame_model& model, const char* file_points, const char* file_links);

int draw_model(frame_model model, graphics arg);

int move_model(frame_model& model, move coeff);

int scale_model(frame_model& model, scale coeff);

int rotate_model(frame_model& model, rotate coeff);

#endif // MODEL_H
