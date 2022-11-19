#include "../../include/header.h"

int command_execv(t_command command)
{
    pid_t	pid;
	int 	i;
	int		size;
    int     result;
    char    *path;
    char    **type;


	i = -1;
	result = 0;
	size = token_size(command.tokens);
    path = command_find_path(command.keyword);
	type = (char**)malloc(sizeof(char *) * 3);
    type[0] = command_find_path(command.keyword);
	type[1] = ft_strdup("");
	type[2] = NULL;
	while (++i < size)
	{
		if (command.tokens->type_id == 9)
			type[1] = ft_strjoin(type[1], command.tokens->context);
		get_next_token(&command.tokens);
	}
	// printf("type0 : %s\n", type[0]);
	// printf("type1 : %s\n", type[1]);
	pid = fork();
	signal(SIGINT, proc_signal_handler);
	if (pid == 0)
		result = execve(path, type, g_env.env);
	else if (pid < 0)
		return (-1);
	if (result == -1)
        return (-1);
	wait(&pid);
    free(type[0]);
    free(path);
    return (0);
}