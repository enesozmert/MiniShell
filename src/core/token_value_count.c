/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_value_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:56:50 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 14:16:56 by cyalniz          ###   ########.fr       */
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
		if (tkn_cpy->type
			&& ft_strncmp(tkn_cpy->type, "value",
				ft_strlen(tkn_cpy->type)) == 0)
			count++;
		tkn_cpy = tkn_cpy->next;
	}
	tkn_cpy = token;
	return (count);
}
