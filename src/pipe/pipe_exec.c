#include "../../include/header.h"

#define READ 0
#define WRITE 1

int haspipe = 1;

static void ft_fatality(void)
{
	ft_putstr_fd("error: fatal\n", 2);
	exit(1);
}

// static void	ft_exec_error(char *str)
// {
// 	ft_putstr_fd("error: cannot execute ", 2);
// 	ft_putstr_fd(str, 2);
// 	ft_putstr_fd("\n", 2);
// 	exit(1);
// }

static void ft_openpipes(int fd[2])
{
	if (haspipe == 1)
	{
		if (close(fd[READ]) == -1)
			ft_fatality();
		if (dup2(fd[WRITE], STDOUT_FILENO) == -1)
			ft_fatality();
		if (close(fd[WRITE]) == -1)
			ft_fatality();
	}
}

static void ft_closepipes(int fd[2])
{
	if (haspipe == 1)
	{
		if (dup2(fd[READ], STDIN_FILENO) == -1)
			ft_fatality();
		if (close(fd[READ]) == -1)
			ft_fatality();
		if (close(fd[WRITE]) == -1)
			ft_fatality();
	}
}

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
	pid_t pid;

	i = -1;
	j = 1;
	result = 0;
	size = token_size(command.tokens);
	type_size = 0;
	arg = ft_strdup("");
	if (pipe(command.fd) == -1)
		ft_fatality();
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
	// signal(SIGINT, proc_signal_handler);
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		ft_openpipes(command.fd);
		result = execve(path, type, g_env.env);
	}
	else
		ft_closepipes(command.fd);
	// wait(&pid);

	if (result == -1)
		return (1);
	free(arg);
	ft_free_dbl_str(type);
	free(path);
	return (0);
}
