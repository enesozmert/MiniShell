#include "../../include/header.h"

int parser(t_token **token, t_rdl_prop *rdl_prop)
{
	int i;

	i = 0;
	while (i < rdl_prop->word_count)
	{
		parser_analizer(*token, rdl_prop);
		get_next_token(token);
		i++;
	}

	return (1);
}

int parser_analizer(t_token *token, t_rdl_prop *rdl_prop)
{
	return (1);
}
