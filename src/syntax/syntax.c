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
	t_token *token_zero;

	i = -1;
	syntax_list(rdl->syntax_list);
	command_list(rdl->command_list);
	token_zero = get_token_id(rdl->token, 0);
	if (ft_strncmp(rdl->token->context, token_zero->context,
				   rdl->token->len) == 0)
		return (0);
	i = -1;
	while (rdl->syntax_list[++i].name != NULL)
	{
		rdl->syntax_list->f(rdl);
		break;
	}
	return (1);
}
