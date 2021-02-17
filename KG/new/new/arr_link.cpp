#include "arr_link.h"

int read_link_arr(char *filename, link_arr_t *links)
{
    int rc = OK;
    FILE *f;
    f = fopen(filename, "r");
    if (f)
    {
        if (fscanf(f, "%d", &(links->count)) == 1)
        {
            rc = OK;
            links->arr = new link_t [links->count];
            if (links->arr)
            {
                for (int i = 0; i < links->count && rc == OK; i++)
                    rc = read_link(f, &(links->arr[i]));
            }
            else
                rc = ERR_MEM;
        }
        else
            rc = ERR_IO;
    }
    else
        rc = ERR_FILE;

    fclose(f);
    return rc;
}


void print_links(link_arr_t *links)
{
    for (int i = 0; i < links->count; i++)
        print_link(links->arr[i]);

}

void free_links(link_arr_t *links)
{
    if (links->count != 0)
    {
        delete [] links->arr;
        links->count = 0;
    }

}


