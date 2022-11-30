/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_key_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:52:00 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 13:12:13 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	token_key_count(t_token *token)
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
			&& ft_strncmp(tkn_cpy->type, "key", ft_strlen(tkn_cpy->type)) == 0)
			count++;
		tkn_cpy = tkn_cpy->next;
	}
	tkn_cpy = token;
	return (count);
}
