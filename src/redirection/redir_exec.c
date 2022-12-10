/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:39:48 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/10 13:35:04 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int get_sub_type(t_command command)
{
	int fd_file;

	fd_file = 0;
	if (command.token_sub_type_id == 2)
		redir_in_exec(command);
	if (command.token_sub_type_id == 0)
		fd_file = redir_out_exec(command);
	if (command.token_sub_type_id == 1)
		fd_file = redir_here_out_exec(command);
	return (fd_file);
}

int redir_exec(t_command *command)
{
	printf("command_count %d\n", command->count);
	if (command->pipe_count > 0)
	{
		if (command->count < command->pipe_count + 2)
		{
			printf("atladı pipe\n");
			return (0);
		}
		if (command->count != command->redir_count + 2)
			command->file_fd = get_sub_type(*command);
	}
	else if (command->pipe_count == 0)
	{
		if (command->count == 1 && command->pipe_count == 0)
		{
			printf("pipe olmadan atladı\n");
			return (0);
		}
		if ((command->count > 1) && command->count != command->redir_count + 2)
			command->file_fd = get_sub_type(*command);
	}
	// if ((command->count > 1) && command->count != command->redir_count + 2)
	// 	command->file_fd = get_sub_type(*command);
	if (command->count == command->redir_count + 1)
		command->count = 0;
	return (0);
}