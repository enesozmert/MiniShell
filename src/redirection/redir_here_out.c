/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_here_out.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:01:50 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 13:02:18 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	redir_here_out_exec(t_command *command)
{
	int		fd_file;
	char	*file_name;

	file_name = redir_file_name(command);
	fd_file = redir_file_create(command, file_name);
	return (fd_file);
}
