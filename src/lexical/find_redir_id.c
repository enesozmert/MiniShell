/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_redir_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:31:33 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/09 11:33:04 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/header.h"

int	find_redir_id(t_redir *redir_list, char *str)
{
	int	i;

	i = -1;
	while (redir_list[++i].sybl != NULL)
	{
		if (ft_strnstr(redir_list[i].sybl, str,
				ft_strlen(redir_list[i].sybl)))
			return (i);
	}
	return (-1);
}