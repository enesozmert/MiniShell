/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:09:13 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 13:09:26 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	ft_openpipes(t_command command, int fd[2])
{
	dup2(command.tmp_fd, 0);
	if (command.count != command.pipe_count + 1)
	{
		close(command.tmp_fd);
		dup2(fd[1], STDOUT_FILENO);
	}
}
