#include "../../include/header.h"

t_command parser(t_token **token, t_rdl_prop *rdl_prop)
{
	int i;
	t_command command;

	i = 0;
	while (i < rdl_prop->word_count)
	{
		command = parser_analizer(*token, rdl_prop);
		get_next_token(token);
		i++;
	}
	return (command);
}

t_command parser_analizer(t_token *token, t_rdl_prop *rdl_prop)
{
	int i;
	int select_i;
	t_command commands[8];

	i = 0;
	select_i = 0;
	command_list(commands);
	while (commands[i].type != NULL)
	{
		if (ft_strncmp(commands[i].type, rdl_prop->word[0].str, ft_strlen(commands[i].type)) == 0)
			select_i = i;
		i++;
	}
	i = 1;
	if (ft_strncmp(commands[select_i].type, token->context, ft_strlen(commands[select_i].type)))
	{
		while (i < rdl_prop->word_count)
		{
			if (ft_strncmp(rdl_prop->word[i].str, token->context, rdl_prop->word[i].len) == 0)
				commands[select_i].arg = ft_strdup(&rdl_prop->main_str[rdl_prop->word[0].len + 1]);
			i++;
		}
	}
	return (commands[select_i]);
}
