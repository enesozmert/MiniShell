/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:32:46 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/08 11:23:04 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void ft_openredir(t_command command, int fd[2])
{
	dup2(command.tmp_fd, 0);
	if (command.count == 1)
	{
		close(command.tmp_fd);
		dup2(fd[1], STDOUT_FILENO);
	}
}
