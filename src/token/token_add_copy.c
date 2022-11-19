#include "../../include/header.h"

t_token *token_add_copy(t_token *token, t_token *get_token)
{
	token_append(&token, token_new(get_token));
	token_add_index(&token);
	return (token);
}