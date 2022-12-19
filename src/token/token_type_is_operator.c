/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type_is_operator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:51:41 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 11:52:23 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	token_type_is_operator(t_rdl *rdl)
{
	if (rdl->ttp->redir_f == 1)
		return (0);
	if (rdl->ttp->token->len == 1
		&& is_operator(rdl->operator_list,
			rdl->ttp->token->context[0])
		&& keyword_in_operator(rdl, rdl->ttp->keyword_id,
			rdl->ttp->token->context[0]))
	{
		if (rdl->ttp->token->context[0] == '=')
			rdl->ttp->opr_f = 2;
		else
			rdl->ttp->opr_f = 0;
		return (1);
	}
	return (0);
}

int	token_type_is_redir(t_rdl *rdl)
{
	if (rdl->ttp->token->len < 3
		&& is_redir(rdl->redir_list, rdl->ttp->token->context)
		&& rdl->ttp->keyword_id != 3)
	{
		rdl->ttp->redir_f = 1;
		return (1);
	}
	return (0);
}

int	token_type_is_option(t_rdl *rdl)
{
	if (rdl->ttp->redir_f == 1)
		return (0);
	if (rdl->ttp->token->len == 1 &&
		is_option(rdl->ttp->token->context[0])
		&& rdl->ttp->keyword_id == 0)
		return (1);
	return (0);
}

int	token_type_is_pipe(t_rdl *rdl)
{
	if (rdl->ttp->token->len == 1
		&& is_pipe(rdl->ttp->token->context[0]))
	{
		rdl->ttp->redir_f = 0;
		return (1);
	}
	return (0);
}

int	token_type_is_dollar(t_rdl *rdl)
{
	if (rdl->ttp->redir_f == 1)
		return (0);
	if (is_dollar(rdl->ttp->token->context[0]))
	{
		rdl->ttp->dollar_f = 1;
		return (1);
	}
	return (0);
}
