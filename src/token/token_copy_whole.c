#include "../../include/header.h"

t_token *token_copy_whole(t_token *token)
{
	int i;
	int count;
	t_token	*copy;
	t_token	*head;
	t_token *tmp;

	i = -1;
	count =	token_size(token);
    copy = malloc(sizeof(t_token));
	head = token;
	tmp = copy;
	while(++i < count)
	{
		ft_strlcpy(copy->context, head->context, head->len);
		copy->t_flag = head->t_flag;
		copy->id = head->id;
		copy->len = head->len;
		copy->type_id = head->type_id;
		copy->next = malloc(sizeof(t_token));
		copy = copy->next;
		head = head->next;
	}
	copy = tmp;
	return (copy);
}