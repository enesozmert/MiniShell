#include "../../include/header.h"

int command_find(t_rdl *rdl, char *keyword)
{
    int i;
    char *find_path;

    i = -1;
    find_path = command_find_path(keyword);
    if ((find_path != NULL || access(keyword, 0) == 0) && is_keyword_builtin(rdl, keyword) == 0 && rdl->pipe_prop->count > 1)
    {
        rdl->command_list[8].keyword = ft_strdup(keyword);
        return (8);
    }
    else if ((find_path != NULL || access(keyword, 0) == 0) && is_keyword_builtin(rdl, keyword) == 0)
    {
        rdl->command_list[7].keyword = ft_strdup(keyword);
        return (7);
    }
    while (rdl->command_list[++i].keyword != NULL)
    {
        if (ft_strncmp(rdl->command_list[i].keyword, keyword, ft_strlen(keyword)) == 0)
            return (i);
    }
    return (0);
}