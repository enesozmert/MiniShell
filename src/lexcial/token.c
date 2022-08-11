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
