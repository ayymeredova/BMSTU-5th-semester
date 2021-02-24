#ifndef ERROR_H
#define ERROR_H

#include <QDebug>

enum Error_t
{
    OK,
    ERR_INIT,
    ERR_CMD,
    ERR_MEM,
    ERR_FILE,
    ERR_FORMAT,
    ERR_EMPTY
};

#endif // ERROR_H
