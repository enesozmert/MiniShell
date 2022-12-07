/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:39:48 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/07 16:03:22 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int type_size(t_command command)
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

static char **create_type(t_command command, char *path)
{
	int i;
	int j;
	char *arg;
	char **type;

	i = -1;
	j = 1;
	arg = ft_strdup("");
	type = (char **)malloc(sizeof(char *) * ((type_size(command) + 1) + 2));
	type[0] = ft_strdup(path);
	while (++i < command.token_size)
	{
		if (command.tokens->type_id == 12 || command.tokens->type_id == 13 || command.tokens->type_id == 7)
			arg = ft_strjoin(arg, command.tokens->context);
		if (command.tokens->type_id == 12 || command.token_size - 1 == command.tokens->id)
		{
			type[j++] = ft_strdup(arg);
			arg = ft_strdup("");
		}
		get_next_token(&command.tokens);
	}
	type[j] = NULL;
	return (type);
}

static int redir_out_exec(t_command command)
{
	int fd_file;
	char *file_name;

	printf("redir out create\n");
	fd_file = 0;
	if (command.count < command.redir_count + 1 && command.count > 1)
	{
		file_name = redir_file_name(command);
		printf("file name : %s\n", file_name);
		fd_file = redir_file_create(command, file_name);
		close(fd_file);
	}
	else if (command.count == command.redir_count + 1)
	{
		file_name = redir_file_name(command);
		printf("file name : %s\n", file_name);
		fd_file = redir_file_create(command, file_name);
	}
	return (fd_file);
}

static int redir_in_exec(t_command command)
{
	printf("redir in create\n");
	printf("file_name %s\n", redir_file_name(command));
	return (0);
}

static int get_sub_type(t_command command)
{
	int fd;

	fd = 0;
	if (command.token_sub_type_id == 2)
		fd = redir_in_exec(command);
	if (command.token_sub_type_id == 0)
		fd = redir_out_exec(command);
	return (fd);
}

int redir_exec(t_command command)
{
	printf("command_count %d\n", command.count);
	pid_t pid;
	int result;
	char *path;
	char **type;

	result = 0;
	path = command_find_path(command.keyword);
	if (command.count == 1)
		type = create_type(command, path);
	signal(SIGINT, proc_signal_handler);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{

			dup2(command.tmp_fd, STDOUT_FILENO);
			close(command.tmp_fd);
			result = execve(path, type, g_env.env);
			int fd = 0;
			dup2(fd, command.tmp_fd);
			fd = get_sub_type(command);
			close(fd);
	}
	if (result == -1)
		perror("error\n");
	wait(&pid);
	free(path);
	return (0);
}
