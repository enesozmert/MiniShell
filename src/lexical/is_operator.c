#include "../../include/header.h"

int is_operator(t_rdl *rdl, char c)
{
    int i;

    i = -1;
    while (rdl->operator_list[++i].sybl != NULL)
    {
        if (rdl->operator_list[i].sybl[0] == c)
            return (1);
    }
    return (0);
}