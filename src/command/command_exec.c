#include "../../include/header.h"

int command_execv(t_command command)
{
	int 	i;
	int		j;
	int		size;
    int     result;
    char    *path;
    char    **type;
    pid_t	pid;


	i = -1;
	j = 1;
	result = 0;
	size = token_size(command.tokens);
    path = command_find_path(command.keyword);
	type = (char**)malloc(sizeof(char *) * ((size - 1) + 2));
	type[0] = ft_strdup(path);
	while (++i < size)
	{
		if (command.tokens->type_id == 10)
			type[j++] = ft_strdup(command.tokens->context);
		get_next_token(&command.tokens);
	}
	type[j] = NULL;
	pid = fork();
	signal(SIGINT, proc_signal_handler);
	if (pid == 0)
		result = execve(path, type, g_env.env);
	else if (pid < 0)
		return (-1);
	if (result == -1)
        return (1);
	wait(&pid);
    // free(type[0]);
    free(path);
    return (0);
}