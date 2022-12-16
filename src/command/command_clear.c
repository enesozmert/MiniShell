/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:42:09 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/16 16:11:08 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	command_clear(t_command *command_list)
{
	int	i;
	char *p;
	char *none;

	i = -1;
	none = ft_strdup("none");
	while (++i < 8)
		command_list[i].count = 0;

	i = 6;
	while(++i < 10)
	{
		p = command_list[i].keyword;
		if (p)
		{
			free(command_list[i].keyword);
		}
		command_list[i].keyword = ft_strdup(none);
	}
	free(none);

	i = -1;
	while (++i < 10)
	{
		if (token_size(command_list[i].tokens) > 0)
			token_clear(&command_list[i].tokens);
	}
	return (0);
}
