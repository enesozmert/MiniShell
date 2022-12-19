/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_add_keyword_id.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:40:26 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 10:13:05 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	token_add_keyword_id(t_rdl *rdl, t_token **token)
{
	int		i;
	int		keyword_id;
	t_token	*token_cpy;

	i = -1;
	keyword_id = 0;
	token_cpy = *token;
	while (++i < token_size(token_cpy))
	{
		if (token_cpy->type_id == 0)
			keyword_id++;
		token_cpy->keyword_id = rdl->keywords_id[keyword_id - 1];
		get_next_token(&token_cpy);
	}
	token_cpy = *token;
}
