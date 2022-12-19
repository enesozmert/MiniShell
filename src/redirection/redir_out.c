/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:02:14 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 13:30:42 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int redir_out_exec(t_command *command)
{
	int fd_file;
	int jump_token;
	int take_token;
	char *file_name;

	fd_file = 0;
	if (command->pipe_count > 0)
	{
		jump_token = command->pipe_count + 1;
		take_token = command->redir_count + command->pipe_count + 1;
	}
	else
	{
		jump_token = 1;
		take_token = command->redir_count + 1;
	}
	if (command->count < take_token && command->count > jump_token)
	{
		file_name = redir_file_name(command);
		fd_file = redir_file_create(command, file_name);
		free(file_name);
		close(fd_file);
	}
	else if (command->count == take_token && command->count > jump_token)
	{
		file_name = redir_file_name(command);
		fd_file = redir_file_create(command, file_name);
		free(file_name);
	}
	return (fd_file);
}
