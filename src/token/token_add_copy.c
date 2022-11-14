#include "../../include/header.h"

t_token *token_add_copy(t_token *cpy, t_token *token)
{
	cpy = token_add(cpy, ft_strdup(token->context), token->t_flag);
	cpy->id = token->id;
	cpy->len = token->len;
	cpy->type = ft_strdup(token->type);
	cpy->type_id = token->type_id;
	return (cpy);
}