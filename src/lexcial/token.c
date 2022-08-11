#include "../../include/header.h"

void	get_next_token(t_token **token)
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
