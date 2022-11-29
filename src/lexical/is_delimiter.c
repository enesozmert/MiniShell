#include "../../include/header.h"

int is_delimiter(t_rdl *rdl, char c)
{
    int i;

    i = -1;
    while (rdl->delimiter_list[++i].sybl != NULL)
    {
        if (rdl->delimiter_list[i].sybl[0] == c)
            return (1);
    }
    return (0);
}