#include "../../include/header.h"

int pipe_exec(t_command command)
{
	printf("pipe_exec\n");
	printf("pipe_exec command count %d\n", command.count);
	int i;
	int j;
	int type_size;
	int size;
	int result;
	char *arg;
	char *path;
	char **type;
	int fd[2];
	pid_t pid;

	i = -1;
	j = 1;
	result = 0;
	size = token_size(command.tokens);
	type_size = 0;
	arg = ft_strdup("");
	pipe(fd);
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
	pid = fork();
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
	waitpid(pid, 0, 0);
	free(arg);
	ft_free_dbl_str(type);
	free(path);
	return (0);
}
