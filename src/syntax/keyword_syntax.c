/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:48:11 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/17 18:34:18 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	keyword_syntax(t_rdl *rdl)
{
	int		i;
	t_token	*token;
	char	*keyword;

	i = -1;
	if (rdl->token->id != 0)
		return (0);
	token = get_token_type_id(rdl->token, rdl->token->keyword_id);
	if (token == NULL)
	{
		token = get_token_id(rdl->token, 0);
		rdl->error_arg = ft_strdup(token->context);
		return (101);
	}
	while (token->context[++i])
		token->context[i] = ft_tolower(token->context[i]);
	keyword = keyword_trim(token->context);
	if (is_keyword(rdl->keyword_list, keyword) == 1)
	{
		free(keyword);
		return (0);
	}
	else
	{
		free(keyword);
		rdl->error_arg = ft_strdup(token->context);
		return (101);
	}
	return (0);
}
