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
	t_token	*tmp;

	if (!*token)
		*token = new;
	else
	{
		tmp = token_last(*token);
		tmp->next = new;
	}
}

t_token *token_add(t_token *token, char *ptr)
{
	// int i;

	// i = 0;
	// while (ptr[i])
	// {
		token_append(&token, token_new(ptr));
	// 	i++;
	// }
	token_add_index(&token);
	token_add_type(&token);
	return (token);
}

void	token_add_index(t_token **token)
{
	t_token	*token_cpy;
	int		i;

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

void	token_add_type(t_token **token)
{
	int		i;
	t_rdl  *rdl;
	t_token	*token_cpy;

	i = -1;
	rdl = malloc(sizeof(t_rdl));
	rdl->keyword_list = malloc(sizeof(t_keyword) * 8);
	rdl->operator_list = malloc(sizeof(t_operator) * 8);
	keyword_list(rdl->keyword_list);
	operator_list(rdl->operator_list);
	token_cpy = *token;
	while (++i < token_size(*token))
	{
		if (is_keyword(rdl, token_cpy->context))
			token_cpy->type = ft_strdup("keyword");
		else if (is_operator(rdl, token_cpy->context[0]) 
				&& (token_cpy)->len == 1)
			token_cpy->type = ft_strdup("operator");
		else if ((token_cpy)->len > 1 && is_keyword(rdl, token_cpy->context) == 0)
			token_cpy->type = ft_strdup("arg");
		token_cpy = token_cpy->next;
	}
	token_cpy = *token;
	free(rdl->keyword_list);
	free(rdl->operator_list);
	free(rdl);
}