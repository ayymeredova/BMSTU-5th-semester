#ifndef ARR_LINK_H
#define ARR_LINK_H

#include <stdio.h>
#include "link.h"
#include "err.h"



/*
Функция чтения массива связей. Возвращает код ошибки.
Параметры:
    char *filename - строка, содержащая название файла.
    link_arr_t *links - массив связей
*/
int read_link_arr(char *filename, link_arr_t *links);



/*
Функция освобождает память из-под массива узлов.
Параметры:
    link_arr_t *links - структура массива узлов.
*/
void free_links(link_arr_t *links);
#endif // ARR_LINK_H
