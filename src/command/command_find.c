#include "../../include/header.h"

int command_find(t_rdl *rdl, char *type)
{
    int i;
    char *find_path;

    i = -1;
    find_path = command_find_path(type);
    if (find_path != NULL && is_keyword_builtin(rdl, type) == 0)
    {
        rdl->command_list[7].keyword = ft_strdup(type);
        return (7);
    }
    while (rdl->command_list[++i].keyword != NULL)
    {
        if (ft_strncmp(rdl->command_list[i].keyword, type, ft_strlen(type)) == 0)
            return (i);
    }
    return (0);
}