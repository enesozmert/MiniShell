#include "../../include/header.h"

int command_execv(t_command command)
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
		if (command.tokens->type_id == 10)
			type_size++;
		get_next_token(&command.tokens);
	}
	i = -1;
    path = command_find_path(command.keyword);
	type = (char**)malloc(sizeof(char *) * ((type_size + 1) + 2));
	type[0] = ft_strdup(path);
	while (++i < size)
	{
		if (command.tokens->type_id == 11)
		{
			arg = ft_strjoin(arg, command.tokens->context);
			printf("arg : %s\n", arg);
		}
		if (command.tokens->type_id == 10 || size - 1 == command.tokens->id)
		{
			type[j++] = ft_strdup(arg);
			arg = ft_strdup("");
		}
		get_next_token(&command.tokens);
	}
	type[j] = NULL;
	printf("type 0 : %s\n", type[0]);
	printf("type 1 : %s\n", type[1]);
	printf("type 2 : %s\n", type[2]);
	// printf("type 2 : %s\n", type[3]);
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