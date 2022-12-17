/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:03:43 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/17 19:37:46 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static void export_default(t_command command)
{
	int i;

	i = -1;
	if (command.token_size == 0)
	{
		env_asc(g_env.env);
		while (g_env.env[++i])
			printf("declare -x %s\n", g_env.env[i]);
	}
}

static char *export_key(t_command command, char *value)
{
	char *key;
	char *join_value;
	char *tmp_value;

	key = NULL;
	tmp_value = NULL;
	join_value = ft_calloc(sizeof(char), 1);
	if (command.tokens->type_id == 10)
	{
		key = ft_strdup(command.tokens->context);
		tmp_value = env_find_value(key);
		if (tmp_value)
		{
			value = ft_strjoin(join_value, tmp_value);
			free(key);
		}
	}
	free(join_value);
	return (value);
}

static char *export_value(t_command command, char *value)
{
	if (command.tokens->type_id == 11)
		value = s1free_join(value, command.tokens->context);
	return (value);
}

static void export_add(char *identifier, char *value)
{
	env_add(identifier, value);
	free(identifier);
	free(value);
	value = ft_calloc(sizeof(char), 1);
}

int export_start(t_command *command)
{
	int i;
	char *value;
	char *identifier;

	i = -1;
	identifier = NULL;
	value = NULL;
	export_default(*command);
	while (++i < command->token_size)
	{
		if (command->tokens->type_id == 8)
			identifier = ft_strdup(command->tokens->context);
		value = export_key(*command, value);
		value = export_value(*command, value);
		if (command->tokens->type_id == 12 || command->token_size == i + 1)
			export_add(identifier, value);
		get_next_token(&command->tokens);
	}
	free(value);
	return (0);
}
