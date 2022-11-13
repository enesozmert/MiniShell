#include "../../include/header.h"

int token_type_is_keyword(t_rdl *rdl)
{
    if (rdl->token_type_prop->token->id == 0)
        rdl->token_type_prop->new_trim = keyword_trim(rdl->token_type_prop->token->context);
    if (rdl->token_type_prop->token->id == 0 && is_keyword(rdl, rdl->token_type_prop->new_trim))
	{
		rdl->token_type_prop->keyword = ft_strdup(rdl->token_type_prop->token->context);
		if (ft_strncmp(rdl->token_type_prop->keyword, "echo",
            ft_strlen(rdl->token_type_prop->keyword)) == 0)
			rdl->token_type_prop->key_flag = 1;
		if (ft_strncmp(rdl->token_type_prop->keyword, "export",
            ft_strlen(rdl->token_type_prop->keyword)) == 0)
			rdl->token_type_prop->key_flag = 2;
        return (1);
	}
    return (0);
}

int token_type_is_operator(t_rdl *rdl)
{
    if (rdl->token_type_prop->token->len == 1 &&
        is_operator(rdl, rdl->token_type_prop->token->context[0]) &&
        keyword_in_operator(rdl, rdl->token_type_prop->keyword, rdl->token_type_prop->token->context[0]))
        {
            if (rdl->token_type_prop->token->context[0] == '$')
                rdl->token_type_prop->opr_flag = 1;
            if (rdl->token_type_prop->token->context[0] == '=')
                rdl->token_type_prop->opr_flag = 2;
            return (1);
        }
        return (0);
}

int token_type_is_single_quote(t_rdl *rdl)
{
    if(is_quote(rdl, rdl->token_type_prop->token->context[0]) &&
     (rdl->token_type_prop->token->len) == 1 &&
     rdl->token_type_prop->token->t_flag == 2)
        return (1);
    return (0);
}

int token_type_is_double_quote(t_rdl *rdl)
{
    if(is_quote(rdl, rdl->token_type_prop->token->context[0]) &&
        (rdl->token_type_prop->token->len) == 1 &&
        rdl->token_type_prop->token->t_flag == 3)
        return (1);
    return (0);
}

int token_type_is_valid_identifier(t_rdl *rdl)
{
    if ((rdl->token_type_prop->token->len) > 0 &&
        is_identifier(rdl, rdl->token_type_prop->token->context) &&
        is_delimiter(rdl, rdl->token_type_prop->token->context[rdl->token_type_prop->token->len - 1]) == 0 &&
        rdl->token_type_prop->key_flag == 2 &&
        rdl->token_type_prop->opr_flag != 2 && rdl->token_type_prop->opr_flag != 1)
        return (1);
    return (0); 
}

int token_type_is_invalid_identifier(t_rdl *rdl)
{
    if ((rdl->token_type_prop->token->len) > 0 &&
        is_identifier(rdl, rdl->token_type_prop->token->context) == 0 &&
        is_delimiter(rdl, rdl->token_type_prop->token->context[rdl->token_type_prop->token->len - 1]) == 0 &&
        rdl->token_type_prop->key_flag == 2 &&
        rdl->token_type_prop->opr_flag != 2 && rdl->token_type_prop->opr_flag != 1)
            return (1);
    return (0);
}

int token_type_is_value1(t_rdl *rdl)
{
    if (rdl->token_type_prop->token->len > 0 &&
        (rdl->token_type_prop->key_flag == 2 || rdl->token_type_prop->opr_flag == 2))
        return (1);
    return (0);
}

int token_type_is_value2(t_rdl *rdl)
{
    if (rdl->token_type_prop->token->len == 1 &&
        is_operator(rdl, rdl->token_type_prop->token->context[0]) &&
        keyword_in_operator(rdl, rdl->token_type_prop->keyword, rdl->token_type_prop->token->context[0]))
        {
            if (rdl->token_type_prop->token->context[0] == '$')
                rdl->token_type_prop->opr_flag = 1;
            if (rdl->token_type_prop->token->context[0] == '=')
                rdl->token_type_prop->opr_flag = 2;
            return (1);
        }
        return (0);
}

int token_type_is_value(t_rdl *rdl)
{
    if (token_type_is_value1(rdl) || token_type_is_value2(rdl))
        return (1);
    return (0);
}

int token_type_is_key(t_rdl *rdl) 
{
    if (rdl->token_type_prop->token->len > 0 &&
        ((rdl->token_type_prop->opr_flag == 1 && rdl->token_type_prop->key_flag == 1) ||
        (rdl->token_type_prop->opr_flag == 1 && rdl->token_type_prop->key_flag == 2)))
        return (1);
    return (0);
}

int token_type_is_arg(t_rdl *rdl)
{
    if (rdl->token_type_prop->token->len > 0 &&
            (rdl->token_type_prop->key_flag != 1 && rdl->token_type_prop->key_flag != 2))
        return (1);
    return (0);
}

int token_type_is_string(t_rdl *rdl)
{
        if (rdl->token_type_prop->token->len > 0 &&
            (rdl->token_type_prop->key_flag == 1 || rdl->token_type_prop->opr_flag == 2) &&
            (rdl->token_type_prop->opr_flag != 1 || rdl->token_type_prop->opr_flag == 2))
        return (1);
    return (0);
}
