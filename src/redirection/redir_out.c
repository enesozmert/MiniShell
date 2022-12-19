/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:02:14 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 15:25:33 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static void	jump_take(t_command *command, int *jump, int *take)
{
	int	jump_token;
	int	take_token;

	jump_token = *jump;
	take_token = *take;
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
	*jump = jump_token;
	*take = take_token;
}

int	redir_out_exec(t_command *command)
{
	int		fd_file;
	int		jump_token;
	int		take_token;
	char	*file_name;

	fd_file = 0;
	jump_token = 0;
	take_token = 0;
	jump_take(command, &jump_token, &take_token);
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
