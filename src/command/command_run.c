/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:20:30 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/16 12:44:54 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	command_run(t_command *command_list)
{
	int	i;
	int	handle_code;

	i = 0;
	handle_code = 0;
	while (i < 11)
	{
		if (command_list[i].count > 0)
		{
			handle_code = command_list[i].f(&command_list[i]);
		}
		g_env.exit_status = handle_code;
		if (handle_code == -1)
			return (-1);
		i++;
	}
	command_clear(command_list);
	return (0);
}
