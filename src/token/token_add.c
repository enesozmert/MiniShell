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

void token_add_type(t_rdl *rdl, t_token **token)
{
	int	i;

	i = -1;
	while (++i < token_size(*token))
	{
		rdl->token_type_prop->token = *token;
		token_add_type_handler(rdl);
		*token = rdl->token_type_prop->token;
		get_next_token(&rdl->token);
	}
}
