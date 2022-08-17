#include "../../include/header.h"

int is_keyword(t_rdl *rdl, char *str)
{
    int i;

    i = -1;
    while (rdl->command_list[++i].type != NULL)
    {
        if (ft_strnstr(rdl->command_list[i].type, str,
        ft_strlen(rdl->command_list[i].type)))
            return (1);
    }
    return (0);
}