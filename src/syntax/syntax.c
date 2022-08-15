#include "../../include/header.h"

void	syntax(t_rdl *rdl)
{
	int	i;

	i = 0;
	while (i < rdl->word_count)
	{
		syntax_analizer(rdl);
		get_next_token(&rdl->token);
		i++;
	}
}

int	syntax_analizer(t_rdl *rdl)
{
	int		i;
	t_token	*token_zero;
	
	i = -1;
	syntax_list(rdl->syntax);
	command_list(rdl->command_list);
	token_zero = get_token_id(rdl->token, 0);
	while (rdl->command_list[i++].type)
	{
		if (ft_strncmp(rdl->command_list[i].type, token_zero->context,
					   ft_strlen(rdl->command_list[i].type)) == 0)
			return (0);
	}
	i = -1;
	while (rdl->syntax[i++].name != NULL)
		rdl->syntax->f(rdl);
	return (1);
}
