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

t_token *token_add(t_token *token, t_token token_cpy)
{
	token_cpy.type_id = -1;
	token_append(&token, token_new(&token_cpy));
	token_add_index(&token);
	return (token);
}

void token_add_index(t_token **token)
{
	int		i;
	t_token	*token_cpy;

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
