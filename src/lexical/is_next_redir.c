/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_next_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:08:55 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/14 14:33:58 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int is_next_redir(int k, char *str)
{
	while (str[k])
	{
		if (str[k] == '>' || str[k] == '<')
			return (1);
		else if (str[k] <= 32)
			k++;
		else 
			return (0);
	}
	return (0);
}

int	is_next_pipe(int k, char *str)
{
	while (str[k])
	{
		if (is_pipe(str[k]))
			return (1);
		else if (str[k] <= 32)
			k++;
		else
			return (0);
	}
	return (0);
}