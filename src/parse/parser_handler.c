/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:03:16 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 14:04:15 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	parser_handler(t_rdl *rdl)
{
	int	j;
	int	result;

	j = -1;
	result = 0;
	while (rdl->i < rdl->len && rdl->main_str[rdl->i])
	{
		j = -1;
		while (++j < 11)
		{
			result = rdl->parser_list[j].f(rdl);
			if (result == 1)
				break ;
		}
		rdl->i++;
	}
}
