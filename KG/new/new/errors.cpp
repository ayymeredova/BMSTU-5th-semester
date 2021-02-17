#include "errors.h"


void error_mess(int error)
{
    if(error == ERR_FILE)
    {
        QMessageBox::warning(NULL, "Ошибка", "Ошибка при импортировании данных из файла.");
    }
    else if (error == ERR_IO)
    {
        QMessageBox::warning(NULL, "Ошибка", "Ошибка при вводе данных!");
    }
    else if (error == ERR_RANGE)
    {
        QMessageBox::warning(NULL, "Ошибка", "Выход за границы допустимых значений!");
    }
    else if (error == ERR_MEM)
    {
        QMessageBox::warning(NULL, "Ошибка", "Ошибка при выделении динамической памяти!");
    }
    else if (error == ERR_EMPTY)
    {
        QMessageBox::warning(NULL, "Ошибка", "Пустые значения!");
    }
    else if (error == UNKNOWN_COMMAND)
    {
        QMessageBox::warning(NULL, "Ошибка", "Неизвестная команда!");
    }
}
