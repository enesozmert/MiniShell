#include "../../include/header.h"

int command_execv(t_command command)
{
    int     result;
    char    *path;
    char    *type;

    type = ft_strdup(command.type);
    path = command_find_path(type);
	result = execve(path, &type, g_env.env);
    free(type);
    if (result == -1)
        return(-1);
    return (0);
}
