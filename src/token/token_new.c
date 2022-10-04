#include "../../include/header.h"

t_token *token_new(char *context, int flag)
{
	t_token *tmp;

	tmp = malloc(sizeof(t_token));
	tmp->context = context;
	tmp->len = ft_strlen(context);
	tmp->type = NULL;
	tmp->next = NULL;
	tmp->next = NULL;
	tmp->t_flag = flag;
	//printf("token new: %s\n", context);
	return (tmp);
}
