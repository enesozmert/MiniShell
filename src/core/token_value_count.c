/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_value_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:56:50 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/13 12:26:33 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	token_value_count(t_token *token)
{
	int		i;
	int		count;
	t_token	*tkn_cpy;

	i = -1;
	count = 0;
	tkn_cpy = token;
	while (++i < token_size(token))
	{
		if (tkn_cpy->type_id == 11)
			count++;
		tkn_cpy = tkn_cpy->next;
	}
	tkn_cpy = token;
	return (count);
}
