#include "../../include/header.h"

t_token *token_new(char *context)
{
	t_token *tmp;

	tmp = malloc(sizeof(t_token));
	tmp->context = context;
	tmp->len = ft_strlen(context);
	tmp->next = NULL;
	return (tmp);
}
