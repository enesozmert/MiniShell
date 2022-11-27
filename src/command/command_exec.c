#include "../../include/header.h"

int command_exec(t_command command)
{
	int 	i;
	int		j;
	int		type_size;
	int		size;
    int     result;
	char	*arg;
    char    *path;
    char    **type;
    pid_t	pid;


	i = -1;
	j = 1;
	result = 0;
	size = token_size(command.tokens);
	type_size = 0;
	arg = ft_strdup("");
	while (++i < size)
	{
		if (command.tokens->type_id == 12)
			type_size++;
		get_next_token(&command.tokens);
	}
	i = -1;
    path = command_find_path(command.keyword);
	type = (char**)malloc(sizeof(char *) * ((type_size + 1) + 2));
	type[0] = ft_strdup(path);
	while (++i < size)
	{
		if (command.tokens->type_id == 13 || command.tokens->type_id == 7)
			arg = ft_strjoin(arg, command.tokens->context);
		if (command.tokens->type_id == 12 || size - 1 == command.tokens->id)
		{
			type[j++] = ft_strdup(arg);
			arg = ft_strdup("");
		}
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