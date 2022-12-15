/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:16:34 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/15 23:33:31 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int keyword_not_null(t_rdl *rdl, t_token *token)
{
	int i;

	i = -1;
	while (rdl->command_list[++i].keyword != NULL)
	{
		if (ft_strncmp(rdl->command_list[i].keyword, token->context,
					   ft_strlen(token->context)) == 0 &&
			rdl->pipe_prop->count <= 0 && rdl->redir_prop->count <= 0)
		{
			return (i);
		}
	}
	return (10);
}

int command_find(t_rdl *rdl, int token_id)
{
	t_token *token;

	token = get_token_id(rdl->token, token_id);
	if (rdl->redir_prop->count > 0)
	{
		rdl->command_list[9].keyword = token->context;
		return (9);
	}
	else if (rdl->pipe_prop->count > 0)
	{
		rdl->command_list[8].keyword = token->context;
		return (8);
	}
	else if (is_keyword_exec(rdl->keyword_list, token->context) && rdl->pipe_prop->count <= 0 && rdl->redir_prop->count <= 0)
	{
		rdl->command_list[7].keyword = token->context;
		return (7);
	}
	return (keyword_not_null(rdl, token));
}
