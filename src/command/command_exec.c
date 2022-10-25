#include "../../include/header.h"

int command_execv(t_command command)
{
    printf("ok\n");
    int     result;
    char    *path;
    char    *type[2];

    type[0] = ft_strdup(command.type);
    type[1] = NULL;
	result = execve(path, type, g_env.env);
    free(type);
    if (result == -1)
        return(-1);
    return (0);
}
