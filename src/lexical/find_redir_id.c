/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_redir_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:31:33 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/03 17:32:33 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/header.h"

int	find_redir_id(t_rdl *rdl, char *str)
{
	int	i;

	i = -1;
	while (rdl->redir_list[++i].sybl != NULL)
	{
		if (ft_strnstr(rdl->redir_list[i].sybl, str,
				ft_strlen(rdl->redir_list[i].sybl)))
			return (i);
	}
	return (-1);
}