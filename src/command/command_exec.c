#include "../../include/header.h"

static int command_exec_type_size(t_command command)
{
	int i;
	int size;
	int type_size;

	i = -1;
	type_size = 0;
	size = token_size(command.tokens);
	while (++i < size)
	{
		if (command.tokens->type_id == 12)
			type_size++;
		get_next_token(&command.tokens);
	}
	return (type_size);
}

static char** command_exec_create_type(t_command command)
{
	int i;
	int j;
	int size;
	char *arg;
	char *path;
	char **type;
	int type_size;

	i = -1;
	j = 0;
	arg = ft_strdup("");
	size = token_size(command.tokens);
	type_size = command_exec_type_size(command);
	type = (char **)malloc(sizeof(char *) * ((type_size + 1) + 2));
	path = command_find_path(command.keyword);
	type[0] = ft_strdup(path);
	while (++i < size)
	{
		if (command.tokens->type_id == 13 || command.tokens->type_id == 7)
			arg = ft_strjoin(arg, command.tokens->context);
		if (command.tokens->type_id == 12 && command.tokens->next->type_id == 7)
		{
			type[j++] = ft_strdup(arg);
			arg = ft_strdup("");
		}
		get_next_token(&command.tokens);
	}
	type[j] = NULL;
	i = -1;
	while (type[++i])
	{
		printf("type : %s\n", type[i]);
	}
	
	return (type);
}

int command_exec(t_command command)
{
	pid_t pid;
	int result;
	char *path;
	char **type;

	result = 0;
	path = command_find_path(command.keyword);
	type = command_exec_create_type(command);
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