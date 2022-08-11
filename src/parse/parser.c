#include "../../include/header.h"

int parser(t_token **token, t_readline_prop rd_prop)
{
	int i;

	i = 0;
	while (i < rd_prop.word_count)
	{
		parser_analizer(*token);
		get_next_token(token);
		i++;
	}

	return (1);
}

int parser_analizer(t_token *token)
{
	printf("t->c %s¨\n", token->context);
	return (1);
}