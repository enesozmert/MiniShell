/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:16:34 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 13:48:28 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int	keyword_not_null(t_rdl *rdl, t_token *token)
{
	int	i;

	i = -1;
	while (rdl->command_list[++i].keyword != NULL)
	{
		if (ft_strncmp(rdl->command_list[i].keyword, token->context,
				ft_strlen(token->context)) == 0
			&& rdl->pipe_prop->count <= 0 && rdl->redir_prop->count <= 0)
			return (i);
	}
	return (0);
}

static int	command_find_keyword(t_rdl *rdl, char *keyword, int i)
{
	char	*p;

	p = rdl->command_list[i].keyword;
	if (p)
		free(rdl->command_list[i].keyword);
	rdl->command_list[i].keyword = ft_strdup(keyword);
	return (i);
}

int	command_find(t_rdl *rdl, int token_id)
{
	int		result;
	char	*keyword;
	t_token	*token;

	result = 0;
	token = get_token_id(rdl->token, token_id);
	keyword = keyword_trim(token->context);
	if (rdl->redir_prop->count > 0)
		result = command_find_keyword(rdl, keyword, 9);
	else if (rdl->pipe_prop->count > 0)
		result = command_find_keyword(rdl, keyword, 8);
	else if (is_keyword_exec(rdl->keyword_list, keyword)
		&& rdl->pipe_prop->count <= 0 && rdl->redir_prop->count <= 0)
		result = command_find_keyword(rdl, keyword, 7);
	else if (is_keyword_builtin(rdl->keyword_list, keyword))
		result = keyword_not_null(rdl, token);
	free(keyword);
	return (result);
}
