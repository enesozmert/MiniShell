#include "../../include/header.h"

int command_clear(t_rdl *rdl)
{
    int i;

    i = -1;
    while (++i < 8)
    {
        rdl->command_list[i].count = 0;
    }
    rdl->command_list[7].keyword = ft_strdup("none");
    return (0);
}