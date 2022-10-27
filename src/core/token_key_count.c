/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_key_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:52:00 by cyalniz           #+#    #+#             */
/*   Updated: 2022/10/27 20:57:00 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int token_key_count(t_token *token)
{
    int		i;
    int		count;
    t_token	*token_cpy;

	i = -1;
	count = 0;
	token_cpy = token;
	while (++i < token_size(token))
	{
		if (token_cpy->type && ft_strncmp(token_cpy->type, "key", ft_strlen(token_cpy->type)) == 0)
			count++;
		token_cpy = token_cpy->next;
	}
	token_cpy = token;
	return (count);
}
