#include "../../include/header.h"

char *command_find_path(char *keyword)
{
    int i;
    char *path;
    char **paths;
    char *new_path;
    struct stat s;

    i = -1;
    paths = NULL;
    path = env_find_value("PATH");
    if (path != NULL)
        paths = ft_split(path, ':');
    while (paths[++i])
    {
        path = ft_strjoin("/", keyword);
        new_path = ft_strjoin(paths[i], path);
        free(path);
        if (stat(new_path, &s) == 0)
        {
            ft_free_dbl_str(paths);
            return (new_path);
        }
        free(new_path);
    }
    ft_free_dbl_str(paths);
    return (NULL);
}
