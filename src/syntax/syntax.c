#include "../../include/header.h"

void syntax(t_rdl *rdl)
{
	int i;

	i = -1;
	while (++i < rdl->word_count)
	{
		syntax_analizer(rdl);
		get_next_token(&rdl->token);
	}
}

int syntax_analizer(t_rdl *rdl)
{

	int i;
	int s_i;
	t_token *token_zero;

	i = -1;
	s_i = 0;
	token_zero = get_token_id(rdl->token, 0);
	printf("token zero %s\n", token_zero->context);
	if (is_keyword(rdl, token_zero->context))
		printf("True\n");
	else
		printf("False\n");
	return (1);
}
