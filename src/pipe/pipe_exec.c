#include "../../include/header.h"

#include "../../include/header.h"

static int pipe_exec_type_size(t_command command)
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

static char** pipe_exec_create_type(t_command command)
{
	int i;
	int j;
	int size;
	char *arg;
	char *path;
	char **type;
	int type_size;

	i = -1;
	j = 1;
	arg = ft_strdup("");
	size = token_size(command.tokens);
	type_size = pipe_exec_type_size(command);
	type = (char **)malloc(sizeof(char *) * ((type_size + 1) + 2));
	path = command_find_path(command.keyword);
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
	// i = -1;
	// while (type[++i])
	// {
	// 	printf("type : %s\n", type[i]);
	// }
	free(path);
	free(arg);
	return (type);
}

int pipe_exec(t_command command)
{
	pid_t pid;
	int fd[2];
	int result;
	char *path;
	char **type;

	result = 0;
	path = command_find_path(command.keyword);
	type = pipe_exec_create_type(command);
	pipe(fd);
	pid = fork();
	signal(SIGINT, proc_signal_handler);
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		ft_openpipes(command, fd);
		ft_closepipes(fd);
		result = execve(path, type, g_env.env);
	}
	else
	{
		if (command.count != command.pipe_count + 1)
		{
			dup2(fd[0], command.tmp_fd);
			ft_closepipes(fd);
		}
		else
			dup2(0, command.tmp_fd);
	}
	wait(&pid);
	ft_free_dbl_str(type);
	free(path);
	return (0);
}
