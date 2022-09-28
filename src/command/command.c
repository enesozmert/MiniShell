#include "../../include/header.h"

int command_init()
{
    return (0);
}

int command_clear(t_rdl *rdl)
{
    int i;
    int j;

    i = -1;
    j = -1;
    while (++i < 8)
    {
        // if (rdl->command_list[i].arg[0] == NULL)
        //     return (0);
        while (++j < rdl->command_list[i].arg_count)
        {
            if (rdl->command_list[i].arg[j] != NULL)
                free(rdl->command_list[i].arg[j]);
        }
        rdl->command_list[i].count = 0;
        rdl->command_list[i].arg_count = 0;
    }
    return (0);
}