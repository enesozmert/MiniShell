#include "../../include/header.h"

void token_clear(t_token **token)
{
	t_token	*current;
	t_token	*next;

	if (!token)
		return ;
	current = *token;
	while (current)
	{
		next = current->next;
		token_delone(current);
		current = next;
	}
	*token = NULL;
}

void	token_delone(t_token *token)
{
	if (!token)
		return ;
	free((void *)token->context);
	free(token);
}