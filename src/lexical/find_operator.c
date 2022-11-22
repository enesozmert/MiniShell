#include "../../include/header.h"

t_operator find_operator(t_rdl *rdl, char c)
{
    int i;

    i = -1;
    while (rdl->operator_list[++i].sybl != NULL)
    {
        if (rdl->operator_list[i].sybl[0] == c)
            return (rdl->operator_list[i]);
    }
    return (rdl->operator_list[5]);
}