/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type_is_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:53:05 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 12:33:34 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	token_type_is_value(t_rdl *rdl)
{
	if (rdl->ttp->redir_f == 1)
		return (0);
	if (rdl->ttp->token->len == 1
		&& rdl->ttp->keyword_id == 3
		&& rdl->ttp->token->context[0] == ' ' && rdl->token->t_flag != -1)
			return (0);
	if (rdl->ttp->token->len > 0
		&& rdl->ttp->keyword_id == 3
		&& rdl->token->next
		&& rdl->token->next->context[0] == '=')
		return (0);
	if (rdl->ttp->token->len > 0
		&& ((rdl->ttp->keyword_id == 3
		&& rdl->ttp->opr_f == 2)))
		return (1);
	if (rdl->ttp->token->len > 0 &&
		(((rdl->ttp->keyword_id == 3
		&& rdl->ttp->opr_f == 2)
		&& (rdl->ttp->sq_f == 1 || rdl->ttp->dq_f == 1))))
		return (1);
	if (rdl->ttp->token->len > 0 && rdl->ttp->keyword_id == 3
		&& (rdl->ttp->sq_f == 1 || rdl->ttp->dq_f == 1))
		return (1);
	return (0);
}

int	token_type_is_key(t_rdl *rdl)
{
	if (rdl->ttp->redir_f == 1)
		return (0);
	if (is_identifier(rdl->identifier_list, rdl->ttp->token->context) == 0)
		if (rdl->ttp->redir_f == 1)
			return (0);
	if (is_identifier(rdl->identifier_list, rdl->ttp->token->context) == 0 && rdl->ttp->token->context[0] != '?')
	{
		rdl->ttp->dollar_f = 0;
		return (0);
	}
	if (rdl->ttp->token->len > 0 &&
		((rdl->ttp->dollar_f == 1 && rdl->ttp->keyword_id == 0) ||
		 (rdl->ttp->dollar_f == 1 && rdl->ttp->keyword_id == 3) ||
		 (rdl->ttp->dollar_f == 1 && rdl->ttp->keyword_id == 1) ||
		 (rdl->ttp->keyword_id == 4)))
	{
		rdl->ttp->opr_f = 0;
		return (1);
	}
	if ((rdl->ttp->keyword_id == 3 &&
		 (rdl->ttp->sq_f == 1 || rdl->ttp->dq_f == 1)))
		return (0);
	return (0);
}

int	token_type_is_arg(t_rdl *rdl)
{
	if (rdl->ttp->redir_f == 1)
		return (0);
	if (rdl->ttp->token->len > 0
		&& rdl->ttp->keyword_id != 0
		&& rdl->ttp->keyword_id != 3
		&& rdl->ttp->keyword_id != 4
		&& rdl->token->t_flag != 8)
		return (1);
	return (0);
}


int	token_type_is_string(t_rdl *rdl)
{
	if (rdl->ttp->redir_f == 1)
		return (1);
	if (rdl->ttp->token->context[0] == ' '
		&& rdl->token->t_flag == 8)
	{
		rdl->ttp->space_f = 1;
		rdl->ttp->dollar_f = 0;
		return (0);
	}
	if (rdl->ttp->token->len > 0
		&& (rdl->ttp->keyword_id == 0
		|| rdl->ttp->opr_f == 2)
		&& (rdl->ttp->opr_f != 1
		|| rdl->ttp->opr_f == 2)
		&&	(rdl->ttp->keyword_id != 3))
	{
		rdl->ttp->dollar_f = 0;
		return (1);
	}
	return (0);
}

int token_type_is_space(t_rdl *rdl)
{
	if (rdl->ttp->token->context[0] == ' ' 
		&& rdl->token->t_flag == 8)
	{
		rdl->ttp->space_f = 1;
		rdl->ttp->dollar_f = 0;
		return (1);
	}
	return (0);
}