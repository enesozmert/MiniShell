#include "../../include/header.h"

int command_find(t_rdl *rdl, char *type)
{
    int i;

    i = -1;
    while (rdl->command_list[++i].type != NULL)
    {
        if (ft_strncmp(rdl->command_list[i].type, type, ft_strlen(type)) == 0)
            return (i);
    }
    return (0);
}