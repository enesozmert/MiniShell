#include "../../include/header.h"

int command_find(t_rdl *rdl, char *type)
{
    int i;
    char *find_path;

    // printf("type: %s\n", type);
    find_path = command_find_path(type);
    i = -1;
    if (find_path != NULL)
    {
        rdl->command_list[7].type = ft_strdup(type);
        return (7);
    }
    while (rdl->command_list[++i].type != NULL)
    {
        if (ft_strncmp(rdl->command_list[i].type, type, ft_strlen(type)) == 0)
            return (i);
    }
    return (0);
}