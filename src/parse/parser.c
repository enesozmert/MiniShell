#include "../../include/header.h"

void	parser(t_rdl *rdl)
{
	int	i;

	i = 0;
	while (i < rdl->word_count)
	{
		parser_analizer(rdl);
		get_next_token(&rdl->token);
		i++;
	}
}

t_rdl	*parser_analizer(t_rdl *rdl)
{
	int i;
	int s_i;
	t_token *token_zero;
	
	i = -1;
	s_i = 0;
	token_zero = get_token_id(rdl->token, 0);
	command_list(rdl->command_list);
	while (rdl->command_list[++i].type != NULL)
	{
		if (ft_strncmp(rdl->command_list[i].type, token_zero->context,
					   ft_strlen(rdl->command_list[i].type)) == 0)
		{
			s_i = i;
			break ;
		}
	}
	i = 0;
	rdl->command_list[s_i].arg =
				ft_strdup(&rdl->main_str[token_zero->len + 1]);
	rdl->command = rdl->command_list[s_i];
	return (rdl);
}
