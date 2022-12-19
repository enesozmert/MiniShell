/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:03:29 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 13:03:12 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	redir_in_exec(t_command *command)
{
	int		fd_file;
	char	*file_name;

	file_name = redir_file_name(command);
	fd_file = redir_file_create(command, file_name);
	free(file_name);
	return (fd_file);
}
