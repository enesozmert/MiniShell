/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:39:48 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/05 11:32:17 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

// static int type_size(t_command command)
// {
// 	int i;
// 	int size;
// 	int type_size;

// 	i = -1;
// 	type_size = 0;
// 	size = token_size(command.tokens);
// 	while (++i < size)
// 	{
// 		if (command.tokens->type_id == 12)
// 			type_size++;
// 		get_next_token(&command.tokens);
// 	}
// 	return (type_size);
// }

// static char **create_type(t_command command, char *path)
// {
// 	int i;
// 	int j;
// 	char *arg;
// 	char **type;

// 	i = -1;
// 	j = 1;
// 	arg = ft_strdup("");
// 	type = (char **)malloc(sizeof(char *) * ((type_size(command) + 1) + 2));
// 	type[0] = ft_strdup(path);
// 	while (++i < command.token_size)
// 	{
// 		if (command.tokens->type_id == 13 || command.tokens->type_id == 7)
// 			arg = ft_strjoin(arg, command.tokens->context);
// 		if (command.tokens->type_id == 12 || command.token_size - 1 == command.tokens->id)
// 		{
// 			type[j++] = ft_strdup(arg);
// 			arg = ft_strdup("");
// 		}
// 		get_next_token(&command.tokens);
// 	}
// 	type[j] = NULL;
// 	return (type);
// }

// static void redir_fork_process(t_command command, int *fd)
// {
// 	if (command.count != command.pipe_count + 1)
// 	{
// 		dup2(fd[0], command.tmp_fd);
// 		ft_closepipes(fd);
// 	}
// 	else
// 		dup2(0, command.tmp_fd);
// }

static void redir_in_exec(t_command command)
{
	int i;
	char *file_name;

	i = -1;
	file_name = NULL;
	if (command.count == 2)
	{
		file_name = ft_strdup("");
		printf("token size : %d\n", command.token_size);
		while (++i < command.token_size)
		{
			if (command.tokens->type_id == 12)
				file_name = ft_strjoin(file_name, command.tokens->context);
			get_next_token(&command.tokens);
		}
	}
	printf("file_name %s\n", file_name);
}

static void get_sub_type(t_command command)
{
	if (command.token_sub_types_id == 0)
	{
		redir_in_exec(command);
	}
}

int redir_exec(t_command command)
{
	printf("command_count %d\n", command.count);
	get_sub_type(command);
	return (0);
	// pid_t pid;
	// int fd[2];
	// int result;
	// char *path;
	// char **type;

	// result = 0;
	// path = command_find_path(command.keyword);
	// if (command.count == 1)
	//     type = create_type(command, path);
	// pipe(fd);
	// pid = fork();
	// signal(SIGINT, proc_signal_handler);
	// if (pid < 0)
	// 	return (-1);
	// if (pid == 0)
	// {
	// 	ft_openpipes(command, fd);
	// 	ft_closepipes(fd);
	// 	result = execve(path, type, g_env.env);
	// }
	// else
	// 	redir_fork_process(command, fd);
	// if (result == -1)
	// 	return (1);
	// wait(&pid);
	// ft_free_dbl_str(type);
	// free(path);
	// return (0);
}
