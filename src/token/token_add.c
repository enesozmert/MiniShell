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
	{
		*token = new;
		return;
	}
	tmp = token_last(*token);
	tmp->next = new;
}

t_token *token_add(t_token *token, char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		token_append(&token, token_new(ptr[i]));
		i++;
	}
	token_add_index(&token);
	return (token);
}

void	token_add_index(t_token **token)
{
	t_token	*token_cpy;
	int		i;

	i = 0;
	token_cpy = *token;
	while (token_cpy)
	{
		i = -1;
		while (++i < token_size(*token))
			(token_cpy)->id = i;
		token_cpy = (token_cpy)->next;
	}
	token_cpy = *token;
}