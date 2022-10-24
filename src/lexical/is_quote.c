#include "../../include/header.h"

int is_quote(t_rdl *rdl, char c)
{
    int i;

    i = -1;
    while (rdl->quote_list[++i].sybl != NULL)
    {
        if (rdl->quote_list[i].sybl[0] == c)
            return (1);
    }
    return (0);
}