/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:48:11 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/01 09:49:27 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	keyword_syntax(t_rdl *rdl)
{
	int		i;
	t_token	*token;

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
	token->context = keyword_trim(token->context);
	if (is_keyword(rdl, token->context) == 1)
		return (0);
	else
	{
		rdl->error_arg = ft_strdup(token->context);
		return (101);
	}
	return (0);
}
