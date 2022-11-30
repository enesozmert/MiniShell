/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_arg_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:09:48 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 13:11:26 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	token_arg_count(t_token *token)
{
	int		i;
	int		count;
	t_token	*tkn_cpy;

	i = -1;
	count = 0;
	tkn_cpy = (t_token *)token;
	while (++i < token_size(token))
	{
		if (tkn_cpy->type
			&& ft_strncmp(tkn_cpy->type, "arg", ft_strlen(tkn_cpy->type)) == 0)
			count++;
		tkn_cpy = tkn_cpy->next;
	}
	tkn_cpy = token;
	return (count);
}
