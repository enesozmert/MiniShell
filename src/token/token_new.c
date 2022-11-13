#include "../../include/header.h"

t_token *token_new(char *context, int flag)
{
	t_token *tmp;

	tmp = malloc(sizeof(t_token));
	tmp->context = context;
	tmp->len = ft_strlen(context);
	tmp->type = NULL;
	tmp->type_id = 0;
	tmp->next = NULL;
	tmp->t_flag = flag;
	return (tmp);
}
