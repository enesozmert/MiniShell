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
	while (rdl->keyword_list[++i].type != NULL)
	{
		if (ft_strncmp(rdl->keyword_list[i].type, token_zero->context,
					   ft_strlen(rdl->keyword_list[i].type)) == 0)
		{
			s_i = i;
			break;
		}
	}

	return (1);
}
