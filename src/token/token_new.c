#include "../../include/header.h"

t_token *token_new(t_token *get_token)
{
	t_token *tmp;

	tmp = malloc(sizeof(t_token));
	tmp->context = ft_strdup(get_token->context);
	tmp->len = ft_strlen(get_token->context);
	tmp->type = NULL;
	tmp->type_id = get_token->type_id;
	tmp->t_flag = get_token->t_flag;
	tmp->keyword_id = 0;
	tmp->next = NULL;
	return (tmp);
}
