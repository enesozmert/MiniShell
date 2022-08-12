#include "../../include/header.h"

void	parser(t_token **token, t_rdl *rdl)
{
	int			i;

	i = 0;
	while (i < rdl->word_count)
	{
		parser_analizer(*token, rdl);
		get_next_token(token);
		i++;
	}
}

t_rdl	*parser_analizer(t_token *token, t_rdl *rdl)
{
	int i;
	int s_i;

	i = -1;
	s_i = 0;
	command_list(rdl->command_list);
	while (rdl->command_list[++i].type != NULL)
	{
		if (ft_strncmp(rdl->command_list[i].type, rdl->word[0].str,
					   ft_strlen(rdl->command_list[i].type)) == 0)
			s_i = i;
	}
	i = 0;
	while (++i < rdl->word_count)
	{
		if (ft_strncmp(rdl->word[i].str, token->context,
					   rdl->word[i].len) == 0)
			rdl->command_list[s_i].arg =
				ft_strdup(&rdl->main_str[rdl->word[0].len + 1]);
	}
	rdl->command = rdl->command_list[s_i];
	return (rdl);
}
