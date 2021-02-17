#ifndef LINK_H
#define LINK_H



#include "err.h"
#include <stdio.h>
#include <stdlib.h>




/*
Функция чтения связи из файла. Возвращает целочисленный код ошибки.
Параметры:
    FILE *f - файловый указатель
    link_t *one_link - один узел
*/
int read_link(FILE *f, link_t *one_link);



#endif // LINK_H
