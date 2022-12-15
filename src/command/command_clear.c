/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:42:09 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/15 17:38:35 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	command_clear(t_command *command_list)
{
	int	i;

	i = -1;
	while (++i < 8)
		command_list[i].count = 0;
	command_list[7].keyword = "none";
	command_list[8].keyword = "none";
	command_list[9].keyword = "none";
	if (token_size(command_list[8].tokens) > 0)
		token_clear(&command_list[8].tokens);
	if (token_size(command_list[9].tokens) > 0)
		token_clear(&command_list[9].tokens);
	return (0);
}
