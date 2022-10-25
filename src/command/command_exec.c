#include "../../include/header.h"

int command_execv(t_command command)
{
    printf("ok\n");
    int     result;
    char    *path;

    // printf("command->type %s", command.type);
    path = command_find_path(command.type);
    // printf("path : %s\n", path);
	result = execve(path, &command.type, g_env.env);
    if (result == -1)
        return(-1);
    return (0);
}
