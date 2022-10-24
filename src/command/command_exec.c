#include "../../include/header.h"

int command_execv(t_command command)
{
    int     result;
    char    *path;

    path = command_find_path(command.type);
	result = execve(path, &command.type, g_env.env);
    if (result == -1)
        return(-1);
    return (0);
}
