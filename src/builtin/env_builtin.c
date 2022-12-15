/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:10:05 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/15 15:48:15 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	env_start(t_command *command)
{
	int	i;

	i = -1;
	while (g_env.env[++i])
		ft_putendl_fd(g_env.env[i], command->file_fd);
	return (0);
}
