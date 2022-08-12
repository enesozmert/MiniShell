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

t_token	*get_token_id(t_token **token, int id)
{
	(void)id;
	t_token	*token_cpy;

	token_cpy = *token;
	printf("token_cpy %s", (*token)->context);
	// while (token_cpy)
	// {
	// 	if (token_cpy->id == id)
	// 	{
	// 		printf("token_cpy %s", token_cpy->context);
	// 		return (token_cpy);
	// 	}
	// 	(token_cpy) = (token_cpy)->next;
	// }
	return (NULL);
}