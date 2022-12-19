/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_add_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:11:32 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 11:32:56 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	token_add_type_handler(t_rdl *rdl)
{
	int	i;
	int	handle_code;

	i = 0;
	handle_code = 0;
	while (rdl->token_type_list[i].name != NULL)
	{
		handle_code = rdl->token_type_list[i].f(rdl);
		if (handle_code == 1)
		{
			rdl->ttp->token->type_id = i;
			break ;
		}
		i++;
	}
	return (0);
}

void	token_add_type(t_rdl *rdl, t_token **token)
{
	int	i;

	i = -1;
	while (++i < token_size(*token))
	{
		rdl->ttp->token = *token;
		token_add_type_handler(rdl);
		*token = rdl->ttp->token;
		get_next_token(&rdl->token);
	}
}
