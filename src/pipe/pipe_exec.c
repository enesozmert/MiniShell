#include "../../include/header.h"

int pipe_exec(t_command command)
{
	// printf("pipe_exec\n");
	// printf("pipe_exec command count %d\n", command.count);
	int i;
	int j;
	int in = 0;
	int out = 1;
	static int fd[2];
	int type_size;
	int size;
	int result;
	char *arg;
	char *path;
	char **type;
	pid_t pid;

	i = -1;
	j = 1;
	result = 0;
	size = token_size(command.tokens);
	type_size = 0;
	arg = ft_strdup("");
	if (pipe(command.fd) == -1)
		return -1;
	while (++i < size)
	{
		if (command.tokens->type_id == 12)
			type_size++;
		get_next_token(&command.tokens);
	}
	i = -1;
	path = command_find_path(command.keyword);
	type = (char **)malloc(sizeof(char *) * ((type_size + 1) + 2));
	type[0] = ft_strdup(path);
	while (++i < size)
	{
		if (command.tokens->type_id == 13 || command.tokens->type_id == 7)
		{
			arg = ft_strjoin(arg, command.tokens->context);
			printf("arg %s\n", arg);
		}
		if (command.tokens->type_id == 12 || size - 1 == command.tokens->id)
		{
			type[j++] = ft_strdup(arg);
			arg = ft_strdup("");
		}
		get_next_token(&command.tokens);
	}
	type[j] = NULL;
	j = -1;
	while (type[++j])
	{
		printf("type : %s\n", type[j]);
	}
	if (command.count % 2 == 1)
	{
		in = 1;
		out = 0;
	}
	if (command.count % 2 == 0 || command.count == 1)
	{
		in = 0;
		out = 1;
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[in], in);
		close(fd[out]);
		close(fd[in]);
		result = execve(path, type, g_env.env);
	}
	else if (pid < 0)
		return (-1);
	if (result == -1)
        return (1);
	close(fd[0]);
	close(fd[1]);
	wait(&pid);
	free(arg);
	ft_free_dbl_str(type);
	free(path);
	return (0);
}