#include "../../include/header.h"

int parser(t_token **token, t_rdl_prop *rd_prop)
{
	int i;

	i = 0;
	while (i < rd_prop->word_count)
	{
		parser_analizer(*token);
		get_next_token(token);
		i++;
	}

	return (1);
}

int parser_analizer(t_token *token)
{
	int			i;
	int			j;
	int			select_i;
	t_command	commands[8];

	i = 0;
	j = 0;
	select_i = 0;
	command_list(commands);
	while (commands[i].type != NULL)
	{
		if (ft_strncmp(commands[i].type, token->context, ft_strlen(commands[i].type)) == 0)
		{
			printf("command is type => %s\n", commands->type);
			select_i = i;
		}
		i++;
	}
	// commands[select_i].type = ft_strdup(token->context);
	commands[select_i].type = ft_strjoin(commands[select_i].type, token->context);
	printf("command is arg => %s\n", commands[select_i].type);
	return (1);
}
