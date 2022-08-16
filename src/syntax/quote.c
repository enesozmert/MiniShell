#include "../../include/header.h"

int single_quote(t_rdl *rdl)
{
	int		i;
	int		j;
	char	*arg;
	t_token	*token_cpy;

	j = 0;
	token_cpy = rdl->token;
	while (token_cpy)
	{
		if (count_char(token_cpy->context, '\'') % 2)
			return (0);
		token_cpy = token_cpy->next;
	}
	arg = malloc(sizeof(char) * rdl->token->len - count_char(rdl->token->context, '\''));
	i = -1;
	while (rdl->token->context[++i] != '\0')
	{
		if (rdl->token->context[i] !=  '\'')
			arg[j++] = rdl->token->context[i];
	}
	printf("arg => %s\n", arg);
	return (1);
}

int double_quote()
{
	return (1);
}