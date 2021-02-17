#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include "structures.h"
#include "errors.h"

int read_count(int *count, FILE *f);

int read_arr_points(point *arr, int count, FILE *f);

int read_arr_links(link *arr, int count, FILE *f);

int alloc_data_points(data_points& tmp_points, int count);

void free_data_points(data_points& tmp_points);

int alloc_data_links(data_links& tmp_links, int count);

void free_data_links(data_links& tmp_links);

void free_model(frame_model& model);

int load_data_points(data_points& tmp_points, FILE *f);

int load_data_links(data_links& tmp_links, FILE *f);

#endif // INPUT_OUTPUT_H
