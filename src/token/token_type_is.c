/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type_is.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:55:21 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 11:32:05 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	token_type_is_keyword(t_rdl *rdl)
{
	char	*keyword;

	keyword = NULL;
	if (rdl->ttp->redir_f == 1)
		return (0);
	if (rdl->ttp->token->t_flag == 0)
		keyword = keyword_trim(rdl->ttp->token->context);
	if (rdl->ttp->token->t_flag == 0
		&& is_keyword(rdl->keyword_list, keyword))
	{
		rdl->ttp->trim = to_lower_str(keyword);
		rdl->ttp->keyword_id
			= find_keyword_id(rdl->keyword_list,
				rdl->ttp->trim);
		free(keyword);
		return (1);
	}
	free(keyword);
	return (0);
}

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

int	token_type_is_single_quote(t_rdl *rdl)
{
	if (rdl->ttp->redir_f == 1)
		return (0);
	if (is_quote(rdl->quote_list, rdl->ttp->token->context[0])
		&& (rdl->ttp->token->len) == 1
		&& rdl->ttp->token->t_flag == 1)
	{
		rdl->ttp->sq_f = 1;
		rdl->ttp->dollar_f = 0;
		return (1);
	}
	return (0);
}

int	token_type_is_double_quote(t_rdl *rdl)
{
	if (rdl->ttp->redir_f == 1)
		return (0);
	if (is_quote(rdl->quote_list, rdl->ttp->token->context[0])
		&& (rdl->ttp->token->len) == 1
		&& rdl->ttp->token->t_flag == 2)
	{
		rdl->ttp->dq_f = 1;
		rdl->ttp->dollar_f = 0;
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

int	token_type_is_valid_identifier(t_rdl *rdl)
{
	if (rdl->ttp->redir_f == 1)
		return (0);
	if (rdl->ttp->token->context[0] == ' ')
		return (0);
	if (rdl->token->next && rdl->token->next->context[0] != '='
		&& rdl->ttp->keyword_id == 3
		&& token_find_count(rdl->token, "=") > 0)
		return (0);
	if ((rdl->ttp->token->len) > 0
		&& is_identifier(rdl->identifier_list,
			rdl->ttp->token->context)
		&& rdl->ttp->keyword_id == 3)
		return (1);
	return (0);
}

int	token_type_is_invalid_identifier(t_rdl *rdl)
{
	if (rdl->ttp->redir_f == 1)
		return (0);
	if (rdl->ttp->token->context[0] == ' ')
		return (0);
	if (rdl->token->next && rdl->token->next->context[0] != '='
		&& rdl->ttp->keyword_id == 3
		&& token_find_count(rdl->token, "=") > 0)
		return (0);
	if ((rdl->ttp->token->len) > 0
		&& is_identifier(rdl->identifier_list,
			rdl->ttp->token->context) == 0
		&& rdl->ttp->keyword_id == 3)
		return (1);
	return (0);
}

int	token_type_is_value1(t_rdl *r)
{
	if (r->ttp->redir_f == 1)
		return (0);
	if (r->ttp->token->len == 1
		&& r->ttp->keyword_id == 3
		&& r->ttp->token->context[0] == ' ')
		return (0);
	if (r->ttp->token->len > 0
		&& r->ttp->keyword_id == 3
		&& r->token->next
		&& r->token->next->context[0] == '=')
		return (0);
	if (r->ttp->token->len > 0
		&& ((r->ttp->keyword_id == 3
		&& r->ttp->opr_f == 2)))
		return (1);
	if (r->ttp->token->len > 0 &&
		(((r->ttp->keyword_id == 3
		&& r->ttp->opr_f == 2)
		&& (r->ttp->sq_f == 1 || r->ttp->dq_f == 1))))
		return (1);
	if (r->ttp->token->len > 0 && r->ttp->keyword_id == 3
		&& (r->ttp->sq_f == 1 || r->ttp->dq_f == 1))
		return (1);
	return (0);
}

int	token_type_is_value(t_rdl *rdl)
{
	if (token_type_is_value1(rdl))
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
	if (rdl->ttp->token->len > 0 &&
		rdl->ttp->keyword_id != 0 &&
		rdl->ttp->keyword_id != 3 &&
		rdl->ttp->keyword_id != 4)
		return (1);
	return (0);
}

int	token_type_is_string(t_rdl *rdl)
{
	if (rdl->ttp->redir_f == 1)
		return (1);
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
	if (rdl->ttp->token->context[0] == ' ')
	{
		rdl->ttp->space_f = 1;
		rdl->ttp->dollar_f = 0;
		return (1);
	}
	return (0);
}

int token_type_is_unknown(t_rdl *rdl)
{
	(void)rdl;
	// if (rdl->token->type_id == -1)
	// 	return (1);
	return (0);
}
