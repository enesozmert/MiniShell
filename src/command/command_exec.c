#include "../../include/header.h"

int command_execv(t_command command)
{
    int     result;
    char    *path;
    char    *type[2];

    type[0] = ft_strdup(command.type);
    type[1] = NULL;
    path = command_find_path(type[0]);
	result = execve(path, type, g_env.env);
    free(type[0]);
    free(path);
    if (result == -1)
        return(-1);
    return (0);
}
