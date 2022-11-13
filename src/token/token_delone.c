#include "../../include/header.h"

void	token_delone(t_token *token)
{
	if (!token)
		return ;
	free((void *)token->context);
	free(token);
}
