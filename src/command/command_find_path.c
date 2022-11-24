#include "../../include/header.h"

char *command_find_path(char *keyword)
{
    int i;
    char *path;
    char **paths;
    char *new_path;
    struct stat s;

    i = -1;
    path = env_find_value("PATH");
    paths = NULL;
    if (access(keyword, 0) == 0)
        return (ft_strdup(keyword));
    if (path != NULL)
        paths = ft_split(path, ':');
    if (!paths)
        return (NULL);
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
