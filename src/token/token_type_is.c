#include "../../include/header.h"

int token_type_is_keyword(t_rdl *rdl)
{
	if (rdl->token_type_prop->redir_flag == 1)
		return (0);
	if (rdl->token_type_prop->token->t_flag == 0)
		rdl->token_type_prop->new_trim = keyword_trim(rdl->token_type_prop->token->context);
	if (rdl->token_type_prop->token->t_flag == 0 && is_keyword(rdl, rdl->token_type_prop->new_trim))
	{
		rdl->token_type_prop->new_trim = to_lower_str(rdl->token_type_prop->new_trim);
		rdl->token_type_prop->keyword_id = find_keyword_id(rdl, rdl->token_type_prop->new_trim);
		return (1);
	}
	return (0);
}

int token_type_is_operator(t_rdl *rdl)
{
	if (rdl->token_type_prop->redir_flag == 1)
		return (0);
	if (rdl->token_type_prop->token->len == 1 &&
		is_operator(rdl->operator_list, rdl->token_type_prop->token->context[0]) &&
		keyword_in_operator(rdl, rdl->token_type_prop->keyword_id, rdl->token_type_prop->token->context[0]))
	{
		if (rdl->token_type_prop->token->context[0] == '=')
			rdl->token_type_prop->opr_flag = 2;
		else
			rdl->token_type_prop->opr_flag = 0;
		return (1);
	}
	return (0);
}

int token_type_is_redir(t_rdl *rdl)
{
	if (rdl->token_type_prop->token->len < 3 &&
		is_redir(rdl, rdl->token_type_prop->token->context))
	{
		rdl->token_type_prop->redir_flag = 1;
		return (1);
	}
	return (0);
}

int token_type_is_option(t_rdl *rdl)
{
	if (rdl->token_type_prop->redir_flag == 1)
		return (0);
	if (rdl->token_type_prop->token->len == 1 &&
		is_option(rdl->token_type_prop->token->context[0]) &&
		rdl->token_type_prop->keyword_id > 7)
		return (1);
	return (0);
}

int token_type_is_pipe(t_rdl *rdl)
{
	if (rdl->token_type_prop->redir_flag == 1)
		rdl->token_type_prop->redir_flag = 0;
	if (rdl->token_type_prop->token->len == 1 &&
		is_pipe(rdl->token_type_prop->token->context[0]))
		return (1);
	return (0);
}

int token_type_is_single_quote(t_rdl *rdl)
{
	if (rdl->token_type_prop->redir_flag == 1)
		return (0);
	if (is_quote(rdl, rdl->token_type_prop->token->context[0]) &&
		(rdl->token_type_prop->token->len) == 1 &&
		rdl->token_type_prop->token->t_flag == 1)
	{
		rdl->token_type_prop->sq_flag = 1;
		rdl->token_type_prop->dollar_flag = 0;
		return (1);
	}
	return (0);
}

int token_type_is_double_quote(t_rdl *rdl)
{
	if (rdl->token_type_prop->redir_flag == 1)
		return (0);
	if (is_quote(rdl, rdl->token_type_prop->token->context[0]) &&
		(rdl->token_type_prop->token->len) == 1 &&
		rdl->token_type_prop->token->t_flag == 2)
	{
		rdl->token_type_prop->dq_flag = 1;
		rdl->token_type_prop->dollar_flag = 0;
		return (1);
	}
	return (0);
}

int token_type_is_dollar(t_rdl *rdl)
{
	if (rdl->token_type_prop->redir_flag == 1)
		return (0);
	if (is_dollar(rdl->token_type_prop->token->context[0]))
	{
		rdl->token_type_prop->dollar_flag = 1;
		return (1);
	}
	return (0);
}

int token_type_is_valid_identifier(t_rdl *rdl)
{
	if (rdl->token_type_prop->redir_flag == 1)
		return (0);
	if (rdl->token_type_prop->token->context[0] == ' ')
		return (0);
	if (rdl->token->next && rdl->token->next->context[0] != '=' &&
		rdl->token_type_prop->keyword_id == 3 &&
		token_find_count(rdl->token, "=") > 0)
		return (0);
	if ((rdl->token_type_prop->token->len) > 0 &&
		is_identifier(rdl, rdl->token_type_prop->token->context) &&
		rdl->token_type_prop->keyword_id == 3)
		return (1);
	return (0);
}

int token_type_is_invalid_identifier(t_rdl *rdl)
{
	if (rdl->token_type_prop->redir_flag == 1)
		return (0);
	if (rdl->token_type_prop->token->context[0] == ' ')
		return (0);
	if (rdl->token->next && rdl->token->next->context[0] != '=' &&
		rdl->token_type_prop->keyword_id == 3 &&
		token_find_count(rdl->token, "=") > 0)
		return (0);
	if ((rdl->token_type_prop->token->len) > 0 &&
		is_identifier(rdl, rdl->token_type_prop->token->context) == 0 &&
		rdl->token_type_prop->keyword_id == 3)
		return (1);
	return (0);
}

int token_type_is_value1(t_rdl *rdl)
{
	if (rdl->token_type_prop->redir_flag == 1)
		return (0);
	if (rdl->token_type_prop->token->len == 1 &&
		rdl->token_type_prop->keyword_id == 3 &&
		rdl->token_type_prop->token->context[0] == ' ')
		return (0);
	if (rdl->token_type_prop->token->len > 0 &&
		rdl->token_type_prop->keyword_id == 3 &&
		rdl->token->next &&
		rdl->token->next->context[0] == '=')
		return (0);
	if (rdl->token_type_prop->token->len > 0 &&
		((rdl->token_type_prop->keyword_id == 3 && rdl->token_type_prop->opr_flag == 2)))
		return (1);
	if (rdl->token_type_prop->token->len > 0 &&
		(((rdl->token_type_prop->keyword_id == 3 && rdl->token_type_prop->opr_flag == 2) &&
		  (rdl->token_type_prop->sq_flag == 1 || rdl->token_type_prop->dq_flag == 1))))
		return (1);
	if (rdl->token_type_prop->token->len > 0 && rdl->token_type_prop->keyword_id == 3 &&
		(rdl->token_type_prop->sq_flag == 1 || rdl->token_type_prop->dq_flag == 1))
		return (1);
	return (0);
}

int token_type_is_value(t_rdl *rdl)
{
	if (token_type_is_value1(rdl))
		return (1);
	return (0);
}

int token_type_is_key(t_rdl *rdl)
{
	if (rdl->token_type_prop->redir_flag == 1)
		return (0);
	if (is_identifier(rdl, rdl->token_type_prop->token->context) == 0)
	{
		rdl->token_type_prop->dollar_flag = 0;
		return (0);
	}
	if (rdl->token_type_prop->token->len > 0 &&
		((rdl->token_type_prop->dollar_flag == 1 && rdl->token_type_prop->keyword_id == 0) ||
		 (rdl->token_type_prop->dollar_flag == 1 && rdl->token_type_prop->keyword_id == 3) ||
		 (rdl->token_type_prop->dollar_flag == 1 && rdl->token_type_prop->keyword_id == 1) ||
		 (rdl->token_type_prop->keyword_id == 4)))
	{
		rdl->token_type_prop->opr_flag = 0;
		return (1);
	}
	if ((rdl->token_type_prop->keyword_id == 3 &&
		 (rdl->token_type_prop->sq_flag == 1 || rdl->token_type_prop->dq_flag == 1)))
		return (0);
	return (0);
}

int token_type_is_arg(t_rdl *rdl)
{
	if (rdl->token_type_prop->redir_flag == 1)
		return (0);
	if (rdl->token_type_prop->token->len > 0 &&
		rdl->token_type_prop->keyword_id != 0 &&
		rdl->token_type_prop->keyword_id != 3 &&
		rdl->token_type_prop->keyword_id != 4)
		return (1);
	return (0);
}

int token_type_is_string(t_rdl *rdl)
{
	if (rdl->token_type_prop->redir_flag == 1)
		return (1);
	if (rdl->token_type_prop->token->len > 0 &&
		(rdl->token_type_prop->keyword_id == 0 || rdl->token_type_prop->opr_flag == 2) &&
		(rdl->token_type_prop->opr_flag != 1 || rdl->token_type_prop->opr_flag == 2) &&
		(rdl->token_type_prop->keyword_id != 3))
	{
		rdl->token_type_prop->dollar_flag = 0;
		return (1);
	}
	if (rdl->token_type_prop->token->context[0] == ' ')
	{
		rdl->token_type_prop->space_flag = 1;
		rdl->token_type_prop->dollar_flag = 0;
		return (1);
	}
	return (0);
}