/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:02:14 by eozmert           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/19 13:05:28 by eozmert          ###   ########.fr       */
=======
/*   Updated: 2022/12/19 13:03:26 by cyalniz          ###   ########.fr       */
>>>>>>> 76b4fc7a9fb3992a4aaa432a191e1aa041b3a00e
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
