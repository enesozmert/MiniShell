/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:32:46 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/07 13:20:30 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void ft_openredir(t_command command)
{
	if (command.count != command.redir_count + 1)
	{
		dup2(command.tmp_fd, STDOUT_FILENO);
	}
}
