#include "../../include/header.h"

int is_operator(t_rdl *rdl, char *str)
{
    int i;

    i = -1;
    while (rdl->operator_list[++i].sybl != NULL)
    {
        if (ft_strncmp(rdl->operator_list[i].sybl, str,
        ft_strlen(rdl->operator_list[i].sybl)))
            return (1);
    }
    return (0);
}