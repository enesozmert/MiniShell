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
	int			i;
	int			select_i = 0;
	t_command	commands[8];
	
	i = 0;
	select_i = 0;
	command_list(commands);
	while (commands[i].type != NULL)
	{
		if (ft_strncmp(commands[i].type, token->context, ft_strlen(commands[i].type)) == 0)
		{
			printf("command is type => %s\n", commands[i].type);
			select_i = i;
		}
		i++;
	}
	i = 0;
	if (ft_strncmp(commands[select_i].type, token->context, ft_strlen(commands[select_i].type)))
	{
		while (i < rdl_prop->word_count)
		{
			if (ft_strncmp(rdl_prop->word[i].str, token->context, rdl_prop->word[i].len) == 0)
			{
				commands[select_i].arg = ft_strdup(rdl_prop->main_str);
				break;
			}
			i++;
		}
	}
	printf("command is arg => %s\n", commands[select_i].arg);
	return (1);
}
