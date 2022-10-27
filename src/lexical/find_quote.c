#include "../../include/header.h"

t_quote find_quote(t_rdl *rdl, char c)
{
    int i;

    i = -1;
    while (rdl->quote_list[++i].sybl != NULL)
    {
        if (rdl->quote_list[i].sybl[0] == c)
            return (rdl->quote_list[i]);
    }
    return (rdl->quote_list[2]);
}