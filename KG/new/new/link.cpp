#include "link.h"

int read_link(FILE *f, link_t *one_link)
{
    int rc = OK;
    if (f)
    {
        if (fscanf(f, "%d%d", &(one_link->start), &(one_link->end)) == 2)
            rc = OK;
        else
            rc = ERR_IO;
    }
    else
        rc = ERR_FILE;
    return rc;
}


