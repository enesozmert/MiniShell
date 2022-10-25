#include "../../include/header.h"

int command_execv(t_command command)
{
    pid_t	pid;
    int     result;
    char    *path;
    char    *type[2];

	result = 0;
    type[0] = ft_strdup(command.type);
    type[1] = NULL;
    path = command_find_path(type[0]);
	pid = fork();
	signal(SIGINT, proc_signal_handler);
	if (pid == 0)
		result = execve(path, type, g_env.env);
	else if (pid < 0)
		return (-1);
	if (result == -1)
        return(-1);
	wait(&pid);
    free(type[0]);
    free(path);
    return (0);
}
