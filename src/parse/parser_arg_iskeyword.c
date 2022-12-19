/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_arg_iskeyword.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:48:02 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 14:49:14 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	parser_arg_iskeyword(int *k, t_rdl *rdl)
{
	int	i;

	i = *k;
	parser_arg_keyword(&i, rdl);
	if (is_keyword(rdl->keyword_list, rdl->buffer))
		parser_add_keyword(rdl, rdl->buffer);
	else if (is_keyword(rdl->keyword_list, rdl->buffer) == 0)
	{
		parser_add_buffer(rdl, rdl->buffer, &i);
		i--;
		*k = i;
		return ;
	}
	i--;
	*k = i;
}
