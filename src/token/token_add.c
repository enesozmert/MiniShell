#include "../../include/header.h"

t_token *token_last(t_token *token)
{
	if (!token)
		return (token);
	while (token->next)
		token = token->next;
	return (token);
}

void token_append(t_token **token, t_token *new)
{
	t_token *tmp;

	if (!*token)
		*token = new;
	else
	{
		tmp = token_last(*token);
		tmp->next = new;
	}
}

t_token *token_add(t_token *token, char *ptr, int flag)
{
	token_append(&token, token_new(ptr, flag));
	token_add_index(&token);
	// token_add_type(&token);
	return (token);
}

void token_add_index(t_token **token)
{
	t_token *token_cpy;
	int i;

	i = 0;
	token_cpy = *token;
	while (i < token_size(*token))
	{
		token_cpy->id = i;
		i++;
		token_cpy = token_cpy->next;
	}
	token_cpy = *token;
}

void token_add_type(t_token **token)
{
	int		i;
	int		opr_flag;
	int		key_flag;
	t_rdl	*rdl;
	t_token	*token_cpy;
	char	*keyword;
	char	*new_trim;

	i = -1;
	opr_flag = 0;
	key_flag = 0;
	rdl = malloc(sizeof(t_rdl) * 1);
	rdl->keyword_list = malloc(sizeof(t_keyword) * 8);
	rdl->operator_list = malloc(sizeof(t_operator) * 7);
	rdl->quote_list = malloc(sizeof(t_quote) * 3);
	rdl->delimiter_list = malloc(sizeof(t_delimiter) * 18);
	rdl->identifier_list = malloc(sizeof(t_operator) * 11);
	keyword_list(rdl->keyword_list);
	operator_list(rdl->operator_list);
	quote_list(rdl->quote_list);
	delimiter_list(rdl->delimiter_list);
	identifier_list(rdl->identifier_list);
	token_cpy = *token;
	while (++i < token_size(*token))
	{
		if (token_cpy->id == 0)
			new_trim = keyword_trim(token_cpy->context);
		if (token_cpy->id == 0 && is_keyword(rdl, new_trim))
		{
			token_cpy->type = ft_strdup("keyword");
			keyword = ft_strdup(token_cpy->context);
			if (ft_strncmp(keyword, "echo", ft_strlen(keyword)) == 0)
				key_flag = 1;
			if (ft_strncmp(keyword, "export", ft_strlen(keyword)) == 0)
				key_flag = 2;
		}
		else if (token_cpy->len == 1
				&& is_operator(rdl, token_cpy->context[0])
				&& keyword_in_operator(rdl, keyword, token_cpy->context[0]))
				{
					token_cpy->type = ft_strdup("operator");
					if (token_cpy->context[0] == '$')
						opr_flag = 1;
					if (token_cpy->context[0] == '=')
						opr_flag = 2;	
				}
		else if (token_cpy->len == 1
				&& is_operator(rdl, token_cpy->context[0])
				&& keyword_in_operator(rdl, keyword, token_cpy->context[0]) == 0)
				{
					token_cpy->type = ft_strdup("value");
					if (token_cpy->context[0] == '$')
						opr_flag = 1;
					if (token_cpy->context[0] == '=')
						opr_flag = 2;
				}
		else if (is_quote(rdl, token_cpy->context[0]) && (token_cpy)->len == 1 && token_cpy->t_flag == 2)
			token_cpy->type = ft_strdup("single_quote");
		else if (is_quote(rdl, token_cpy->context[0]) && (token_cpy)->len == 1 && token_cpy->t_flag == 3)
			token_cpy->type = ft_strdup("double_quote");
		else if ((token_cpy)->len > 0 && is_identifier(rdl, token_cpy->context)
					&& is_delimiter(rdl, token_cpy->context[token_cpy->len - 1]) == 0 && key_flag == 2 && opr_flag != 2 && opr_flag != 1)
			token_cpy->type = ft_strdup("valid_identifier");
		else if ((token_cpy)->len > 0 && is_identifier(rdl, token_cpy->context) == 0
					&& is_delimiter(rdl, token_cpy->context[token_cpy->len - 1]) == 0 && key_flag == 2 && opr_flag != 2 && opr_flag != 1)
			token_cpy->type = ft_strdup("invalid_identifier");
		else if ((token_cpy)->len > 0 && (key_flag == 1 || opr_flag == 2) && (opr_flag != 1 || opr_flag == 2))
			token_cpy->type = ft_strdup("value");
		else if ((token_cpy)->len > 0 && (opr_flag == 1 || opr_flag == 2) && (key_flag == 1 || key_flag == 2))
		{
			token_cpy->type = ft_strdup("key");
			opr_flag = 0;
		}
		token_cpy = token_cpy->next;
	}
	free(new_trim);
	free(rdl->keyword_list);
	free(rdl->quote_list);
	free(rdl->operator_list);
	free(rdl);
}
