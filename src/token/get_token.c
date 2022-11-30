#include "../../include/header.h"

void	get_next_token(t_token **token)
{
	t_token *head;

	head = *token;
	if (*token == NULL)
		return ;
	while ((*token)->next != NULL)
		*token = (*token)->next;
	(*token)->next = head;
	head = head->next;
	*token = (*token)->next;
	(*token)->next = NULL;
	*token = head;
}

void	get_next_token_rra(t_token **token)
{
	t_token	*front;
	t_token	*back;
	t_token	*head;

	head = *token;
	back = *token;
	front = *token;
	if (*token == NULL)
		return ;
	while (front->next != NULL)
	{
		front = front->next;
		if (front->next != NULL)
			back = back->next;
	}
	if (front->next == NULL)
	{
		front->next = head;
		back->next = NULL;
	}
	*token = front;
}

t_token	*get_token_id(t_token *token, int id)
{
	t_token	*token_cpy;

	token_cpy = token;
	while (token_cpy)
	{
		if (token_cpy->id == id)
			return (token_cpy);
		(token_cpy) = (token_cpy)->next;
	}
	return (NULL);
}

t_token	*get_token_type_id(t_token *token, int type_id)
{
	t_token	*token_cpy;

	token_cpy = token;
	while (token_cpy)
	{
		if (token_cpy->type_id == type_id)
			return (token_cpy);
		(token_cpy) = (token_cpy)->next;
	}
	return (NULL);
}