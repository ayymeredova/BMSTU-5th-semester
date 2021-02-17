#ifndef ERRORS_H
#define ERRORS_H

#include "task_manager.h"
#include <QMessageBox>
#include <QObject>

//целочисленный код возврата при успешном выполнении программы.
#define OK 0
//целочисленный код возврата при ошибке ввода - вывода.
#define ERR_IO 1
//целочисленный код возврата при выходе за границы допустимых значений.
#define ERR_RANGE 2
//целочисленный код возврата при ошибке выделения памяти.
#define ERR_MEM 3
//целочисленный код возврата при ошибке чтения из файла.
#define ERR_FILE 4
//целочисленный код возврата при пустых значениях.
#define ERR_EMPTY 5



void error_mess(int error);

#endif // ERRORS_H
