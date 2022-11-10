#include "../../include/header.h"

int is_keyword_builtin(t_rdl *rdl, char *str)
{
    int i;

    i = -1;
    while (rdl->keyword_list[++i].type != NULL)
    {
        if (ft_strncmp(rdl->keyword_list[i].type, str,
                       ft_strlen(rdl->keyword_list[i].type)) == 0)
            return (1);
    }
    return (0);
}

int is_keyword_exec(t_rdl *rdl, char *str)
{
    char *find_path;

    find_path = command_find_path(str);
    if (find_path != NULL && is_keyword_builtin(rdl, str) == 0)
    {
        free(find_path);
        return (1);
    }
    free(find_path);
    return (0);
}

int is_keyword(t_rdl *rdl, char *str)
{
    if (is_keyword_builtin(rdl, str) == 1 || is_keyword_exec(rdl, str))
        return (1);
    return (0);
}