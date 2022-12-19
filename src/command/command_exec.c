/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:18:17 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 12:21:11 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int	type_size(t_command command)
{
	int	i;
	int	size;
	int	type_size;

	i = -1;
	type_size = 0;
	size = token_size(command.tokens);
	while (++i < size)
	{
		if (command.tokens->type_id == 14)
			type_size++;
		get_next_token(&command.tokens);
	}
	return (type_size);
}

static char	*create_type_arg(t_command command, char *arg)
{
	if (command.tokens->type_id == 13)
		arg = s1free_join(arg, command.tokens->context);
	return (arg);
}

static char	**create_type(t_command command, char *path)
{
	int		i;
	int		j;
	char	*arg;
	char	**type;

	i = -1;
	j = 1;
	arg = NULL;
	type = (char **)malloc(sizeof(char *) * (type_size(command) + 3));
	type[0] = ft_strdup(path);
	while (++i < command.token_size)
	{
		arg = create_type_arg(command, arg);
		if (command.tokens->type_id == 14
			|| command.token_size - 1 == command.tokens->id)
		{
			type[j++] = ft_strdup(arg);
			free(arg);
			arg = ft_strdup("");
		}
		get_next_token(&command.tokens);
	}
	type[j] = NULL;
	free(arg);
	return (type);
}

static void	command_redir(t_command command)
{
	if (command.redir_count == -1)
	{
		if (command.token_sub_type_id == 0 || command.token_sub_type_id == 1)
		{
			dup2(command.file_fd, STDOUT_FILENO);
			close(command.file_fd);
		}
		else if (command.token_sub_type_id == 2
			|| command.token_sub_type_id == 3)
		{
			dup2(command.file_fd, 0);
			close(command.file_fd);
		}
	}
}

int	command_exec(t_command *command)
{
	pid_t	pid;
	char	*path;
	char	**type;

	path = command_find_path(command->keyword);
	type = create_type(*command, path);
	pid = fork();
	signal(SIGINT, proc_signal_handler);
	if (pid == 0)
	{
		command_redir(*command);
		if (execve(path, type, g_env.env) == -1)
			return (1);
	}
	else if (pid < 0)
		return (-1);
	wait(&pid);
	free(path);
	ft_free_dbl_str(type);
	return (0);
}
