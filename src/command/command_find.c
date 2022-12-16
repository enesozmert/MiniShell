/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:16:34 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/16 15:17:18 by eozmert          ###   ########.fr       */
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
				return (i);
	}
	return (10);
}

static int command_find_keyword(t_rdl *rdl, t_token *token, int i)
{
	char	*p;

	p = rdl->command_list[i].keyword;
	if (p)
		free(rdl->command_list[i].keyword);
	rdl->command_list[i].keyword = ft_strdup(token->context);
	return (i);
}

int command_find(t_rdl *rdl, int token_id)
{
	int result;
	t_token *token;

	result = 0;
	token = get_token_id(rdl->token, token_id);
	if (rdl->redir_prop->count > 0)
		result = command_find_keyword(rdl, token, 9);
	else if (rdl->pipe_prop->count > 0)
		result = command_find_keyword(rdl, token, 8);
	else if (is_keyword_exec(rdl->keyword_list, token->context)
		&& rdl->pipe_prop->count <= 0 && rdl->redir_prop->count <= 0)
		result = command_find_keyword(rdl, token, 7);
	else if (is_keyword_builtin(rdl->keyword_list, token->context))
		result = keyword_not_null(rdl, token);
	return (result);
}
